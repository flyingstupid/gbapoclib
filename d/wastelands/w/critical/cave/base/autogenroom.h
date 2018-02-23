
#define AREA_PATH (implode( explode( file_name( this_object() ), "/" )[..<2], "/" ) + "/")

string * dig_exits;
int *exit_health;

#define SAVE save()
#define LOAD load()

//#define LOAD
//#define SAVE 

#define GET_ID (to_int(explode( file_name(this_object()), "_" )[<1]))
#define SIZE_X 50
#define SIZE_Y 20

void save()
{
    string file = file_name(this_object())+".o";

    string out = save_value( dig_exits );
    out += save_value( exit_health );

    write_file( file, out, 1 );

}

void load()
{
    string file = file_name(this_object())+".o";

    if( file_size(file) != -1 )
    {
        int start = 1;

        dig_exits = restore_value(read_file(file, start, 2));
        exit_health = restore_value(read_file(file, start+=2, 2));
    }

    if(!dig_exits) dig_exits = ({});
    if(!exit_health) exit_health = ({ 75, 75, 75, 75 });
}

string get_short_by_id( int id )
{
	return "in a cave";
}

string get_long_by_id( int id )
{
	string * longs = ({
           "The cave is dark and wet. The smell of stale air all around you.\n",
           "Musty and dark the cave is big enough to work in but still somehow cramped.\n",
           "Carved over the ages the cave dark. Uneven ground below your feet as you walk\n",
           "Small debris litters the floor of the dark, wet, cave.\n"
	});

	return longs[id%sizeof(longs)];
}

string get_room_scav_type(string type, int id)
{
    return type + ( random(10) + 1 );
}

string * set_exits( string *e )
{
    LOAD;
    
    if( !dig_exits )
        dig_exits = ({});

    e += dig_exits;

    return ::set_exits( e );
}

void init()
{
    ::init();
    add_action( "do_dig", "dig" );
}

//-----------------------------------------------------
void dig_cleanup(object player)
{
    object ob = player->query_calloutwatch_object(this_object());
    destruct( ob );
}

//-----------------------------------------------------
void dig_cancel(object player)
{
    tell_object( player, "You abandon your digging and move on.\n" );
    remove_call_out( "do_dig_2" );
    dig_cleanup(player);
}

status do_dig( string arg )
{
    if( this_player()->query_calloutwatch_object(this_object()) )
    {
        tell_object( this_player(), "You seem a little busy do be doing that right now...\n" );
        return 1;
    }

    if( !present( "pickaxe", this_player() ) )
    {
        tell_object( this_player(), "You don't have the right tools for the job.\n" );
        return 1;
    }
        
    if( find_call_out( "do_gather_2" ) != -1 || find_call_out( "do_gather_3" ) != -1 )
    {
        tell_object( this_player(),  "Somone is already digging here.\n" );
        return 1;
    }

    int id = GET_ID;
    int x = id % SIZE_X;
    int y = id / SIZE_X;

    int exitID = 0;

    if( arg == "east" )
    {
        x++;
        exitID = 0;
    }
    else if( arg == "west" )
    {
        x--;
        exitID = 1;
    }
    else if( arg == "north" )
    {
        y--;
        exitID = 2;
    }
    else if( arg == "south" )
    {
        y++;
        exitID = 3;
    }
    else
    {
        tell_object( this_player(), "The direction " + arg + " is not valid.\n" );
        return 1;
    }


    if( x >= 0 && y >= 0 && x < SIZE_X && y < SIZE_Y )
    {

        string file = AREA_PATH + "cave_" + (y * SIZE_X + x);

        if( member( dest_dir, file ) != -1 || member( dest_dir, file + ".c" ) != -1 )
        {
            tell_object( this_player(), "There is already an opening that direction\n" );
            return 1;
        }

        clone_object( "/obj/shadows/calloutwatch.c" )->calloutwatch( this_player(), this_object(), "dig_cancel" );
        tell_room( this_object(), capitalize( this_player()->query_name() ) + " starts digging...\n", ({this_player()}) );
        tell_object( this_player(), "You start digging..\n" );
        call_out( "do_dig_2", 4, arg, x, y, exitID ) ;
        return 1;
    }
    else
    {
        tell_object(this_player(), "You can't dig " + arg + " it is too solid.\n" );
    }

    return 1;
}

void do_dig_2( string arg, int x, int y, int exitID )
{

    if( exit_health[exitID] > 0 )
    {
        exit_health[exitID] -= 1;
        SAVE;
        tell_room( this_object(), capitalize( this_player()->query_name() ) + " keeps digging...\n", ({this_player()}) );
        tell_object( this_player(), "You keep digging..\n" );
        call_out( "do_dig_2", 4, arg, x, y, exitID ) ;
        return;
    }

    mapping opp = ([ "east":"west",
                     "west":"east",
                     "north":"south",
                     "south":"north"]);

    string file = AREA_PATH + "cave_" + (y * SIZE_X + x);
    add_exit( file, arg );
    file->add_dig_exit( file_name(this_object()), opp[arg] );

    dig_exits += ({ file, arg });

    tell_object(this_player(), "You dig " + arg + ".\n" );
    tell_room(this_object(), capitalize( this_player()->query_name() ) + " digs " + arg + ".\n", ({this_player()}) );

    SAVE;

}

void add_dig_exit( string file, string dir )
{
    add_exit( file, dir );
    dig_exits += ({ file, dir });
    SAVE;
}
