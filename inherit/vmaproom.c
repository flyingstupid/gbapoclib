//
//
#include <mudlib.h>
#include <ansi.h>
#include <levels.h>

inherit ROOM_BASE;

#define ROOM_LINE_SIZE 7
#define RENDER_LIVING 1
#define RENDER_PLAYERS 1
#define RENDER_USER 1

// Room renders
string *s_northwest = ({ "/", " ", " ", "N" });
string *s_northeast = ({ "\\", " ", " ", "M" });
string *s_north     = ({ "-----", "     ", "-+ +-", "-+=+-" });
string *s_south     = ({ "-----", "     ", "-+ +-", "-+=+-" });
mixed *s_west      = ({ ({ "|", "|", "|", "|", "|" }), 
    ({ " ", " ", " ", " ", " " }),
    ({ "|", "+", " ", "+", "|" }),
    ({ "|", "+", "]", "+", "|" }) });

mixed *s_east      = ({ ({ "|", "|", "|", "|", "|" }), 
    ({ " ", " ", " ", " ", " " }),
    ({ "|", "+", " ", "+", "|" }),
    ({ "|", "+", "[", "+", "|" }) });

string *s_southeast = ({ "/", " ", " ", "N" });
string *s_southwest = ({ "\\", " ", " ", "M" });
//                | /-----\/-----\/-----\ |
string tabOver = "                         ";

string vmap( string arg );

mixed *CreateRoomDescData();
string render_exits();
string render_ghost_exits();
string *render_objects();
string *render_mobs();

/** Render Functions */
string *RenderRoom( string exit );
string RenderHeader();
string *RenderMobiles( object room, string *roomRender );
string ApplyColor( string output );
string GetRoomDescLine(mixed *data);
/********************/

void dlog( string str )
{
    object ob = find_player( "emraef" );
    
    if( ob )
        tell_object( ob, str + "\n" );
}

int adminp( object obj )
{
    return obj->query_security_level() ? 1 : 0;
}

int wizardp( object obj )
{
    return obj->query_security_level() ? 1 : 0;
}

void do_vmap( object ob )
{
    tell_object( ob, vmap("") );
}

string vmap( string arg )
{
    string *render;
    mixed * rooms;
    mixed *roomLong;
    
    roomLong = CreateRoomDescData();
    
    render = allocate( ROOM_LINE_SIZE * 3 );
    rooms = allocate( 9 );
    
    rooms[0] = RenderRoom( "northwest" );
    rooms[1] = RenderRoom( "north" );
    rooms[2] = RenderRoom( "northeast" );
    
    rooms[3] = RenderRoom( "west" );
    rooms[4] = RenderRoom( "here" );
    rooms[5] = RenderRoom( "east" );
    
    rooms[6] = RenderRoom( "southwest" );
    rooms[7] = RenderRoom( "south" );
    rooms[8] = RenderRoom( "southeast" );
    
    
    for( int i = 0; i < 9; i += 3 )
    {
        for( int j = 0; j < ROOM_LINE_SIZE; j++ )
        {
            render[(i/3)*ROOM_LINE_SIZE+j] = ApplyColor( "| " + rooms[i][j] + rooms[i+1][j] +
                                                        rooms[i+2][j] + " |" );
            
            render[(i/3)*ROOM_LINE_SIZE+j] += "  " + GetRoomDescLine( roomLong );
        }
    }
    
    render += ({  "\\-----------------------/  " + GetRoomDescLine( roomLong ) });
    
    while( roomLong[0] < sizeof( roomLong ) )
    {
        render += ({ tabOver + "  " + GetRoomDescLine( roomLong ) });
    }
    
    return sprintf( "%s%s", RenderHeader(), implode( render, "\n" ) );
}

mixed *CreateRoomDescData()
{
    mixed *roomLong;
    string ghostExits;
    
    roomLong = allocate( 2 );
    roomLong[0] = 2;
    roomLong[1] = 0;
    roomLong += explode( implode(explode(this_object()->query_long(),"\n")," "), "/FORCE_NEWLINE/"
                        );
    roomLong += ({ "", "", render_exits() });
    
    roomLong += ({ "", "" });
    roomLong += render_objects();
    roomLong += render_mobs();
    
    for( int l = 2; l < sizeof( roomLong ); l++ )
    {
        roomLong[l] = explode( roomLong[l], " " );
    }
    
    
    return roomLong;
}

string GetRoomDescLine(mixed *data)
{
    string retVal;
    int i;
    
    retVal = "";
    
    if( sizeof( data ) <= data[0] )
    {
        return NOR;
    }
    
    for( i = data[1]; i < sizeof(data[data[0]]); i++ )
    {
        if( sizeof( clear_ansi_tags( retVal + data[data[0]][i] ) ) > 48 )
            break;
        
        retVal += data[data[0]][i] + " ";
    }
    
    if( i < sizeof( data[ data[0] ] ) )
    {
        data[1] = i;
    }
    else
    {
        data[0]++;
        data[1]=0;
    }
    
    return retVal + NOR;
}



string ApplyColor( string output )
{
    output = replace_string( output, "\[", RED + "\[" + NOR );
    output = replace_string( output, "C", RED + "U" + NOR );
    output = replace_string( output, "V", RED + "D" + NOR );
    output = replace_string( output, "Z", HIB + "*" + NOR );
    output = replace_string( output, "X", HIG + "*" + NOR );
    output = replace_string( output, "B", HIR + "*" + NOR );
    output = replace_string( output, "N", RED + "/" + NOR );
    output = replace_string( output, "M", RED + "\\" + NOR );
    output = replace_string( output, "+", HIW + "+" + NOR );
    output = replace_string( output, "=", RED + "=" + NOR );
    output = replace_string( output, "\]", RED + "\]" + NOR );
    
    return output;
}

string RenderHeader()
{
    string returnString;
    
    returnString = "";
    
    if( previous_object(1) &&  adminp( previous_object(1) ) )
    {
        returnString += file_name( this_object() ) + "\n";
    }
    
    returnString += sprintf( "/%|23.23s\\\n", query_short() );
    
    return returnString;
}

string *RenderRoom( string exit )
{
    string *render;
    object room;
    int east, west;
    int northeast, northwest;
    int southeast, southwest;
    int north, south;
    int up, down;
    
    if( exit == "here" )
    {
        room = this_object();
    }
    else
    {
        room = load_object_safe( query_exit_filename_all( exit ) );
    }
    
    // if the door is closed then we cannot go though it
    if( query_door_exit_status( exit ) > 1 )
    {
        room = 0;
    }
    
    render = allocate( ROOM_LINE_SIZE );
    
    if( room == 0 ) 
    {
        render[0] = "       ";
        render[1] = "       ";
        render[2] = "       ";
        render[3] = "       ";
        render[4] = "       ";
        render[5] = "       ";
        render[6] = "       ";
        return render;
    }
    
    northeast = min( 3, room->valid_exit( "northeast" ) + room->query_door_exit_status( "northeast" ) );
    northwest = min( 3, room->valid_exit( "northwest" ) + room->query_door_exit_status( "northwest" ) );
    north     = min( 3, room->valid_exit( "north" ) + room->query_door_exit_status( "north" ) );
    southeast = min( 3, room->valid_exit( "southeast" ) + room->query_door_exit_status( "southeast" ) );
    southwest = min( 3, room->valid_exit( "southwest" ) + room->query_door_exit_status( "southwest" ) );
    south     = min( 3, room->valid_exit( "south" ) + room->query_door_exit_status( "south" ) );
    east      = min( 3, room->valid_exit( "east" ) + room->query_door_exit_status( "east" ) );
    west      = min( 3, room->valid_exit( "west" ) + room->query_door_exit_status( "west" ) );

    render[0] = s_northwest[northwest] + s_north[north] + s_northeast[northeast];
    
    for( int i = 0; i < 5; i++ )
    {
        render[i+1] = s_west[west][i] + "     " + s_east[east][i];
    }
    
    up   = room->valid_exit( "up" );
    down = room->valid_exit( "down" );
    
    if( up )
    {
        render[1][3] = 'C';
    }
    
    if( down )
    {
        render[5][3] = 'V';
    }
    
    render[6] = s_southwest[southwest] + s_south[south] + s_southeast[southeast];
    
    RenderMobiles( room, render );
    
    if( exit == "here" && RENDER_USER )
    {
        // Render the player
        render[3] = render[3][0..2] + "B" + render[3][4..];
    }
    
    return render;
}


string *RenderMobiles( object room, string *roomRender )
{
    int randrow, randcol;
    object *inv;
    
    if( !room )
    {
        return roomRender;
    }
    
    inv = all_inventory( room );
    for( int i = 0; i < sizeof( inv ); ++i )
    {
        if( inv[i] == this_player() )
        {
            continue;
        }
       

        if( RENDER_PLAYERS && is_a( PLAYER, inv[i] ) )
        {
            randrow = random(5) + 1;
            randcol = random(5) + 1;
            while( ( randrow == 1 || randrow == 3 || randrow == 5 ) && randcol == 3 )
            {
                randcol = random(5) + 1;
            }
            roomRender[randrow][randcol] = 'Z';
        }
        else if( RENDER_LIVING && is_a( LIVING, inv[i] ) )
        {
            randrow = random(5) + 1;
            randcol = random(5) + 1;
            while( ( randrow == 1 || randrow == 3 || randrow == 5 ) && randcol == 3 ||
                  roomRender[randrow][randcol] == 'Z' )
            {
                randcol = random(5) + 1;
            }
            roomRender[randrow][randcol] = 'X';
        }
    }
    
    return roomRender;
}

string render_exits()
{
    return "";

    string retVal;
    string *exits;
    
    exits = m_indices(this_object()->query_exits());
    
    switch(sizeof(exits))
    {
        case 0:
        {
            retVal = (CYN + "There are no obvious exits here." + NOR + "");
            break;
        }
        case 1:
        {
            retVal = (CYN + "The only obvious exit is " + HIY + exits[0] + NOR + CYN + "." + NOR +
                      ""); 
            break;
        }
        default:
        {
            retVal = (CYN + 
                      sprintf("The only obvious exits are %s and %s.",
                              HIY + implode(exits[0..<2], NOR + CYN + ", " + HIY) + NOR + CYN,
                              HIY + exits[<1] + NOR + CYN
                              ) + NOR + ""
                      );
        }
    }
    
    
    return retVal;
}

string * render_objects()
{
    object *objects;
    objects = filter(all_inventory(this_object()), (: !living($1) :));
    
    if(sizeof(objects) > 0)
    {
        return map(objects, 
                   (: capitalize( WHT + ( $1->query_long() ? $1->query_short(): "ERROR: " + file_name($1)
                                         ) + NOR )  :));
    }
    
    return ({});
}

string * render_mobs()
{
    string *users;
    users = filter(all_inventory(this_object()), (: living($1) && $1 != this_player() :));
    
    if(sizeof(users) > 0)
    {
        return map(users, (: CYN + capitalize($1->query_short() ? $1->query_short() : $1->query_name()) + NOR :));
    }
    
    return ({});
}

/**
string cambridge( string str )
{
    
}

string scramble_word( string str )
{
    
}
**/


