#include <mudlib.h>
#include "/wiz/emraef/open/scav/scavpaths.h"

inherit VMAP_ROOM;

#define CAP_NAME(XXX) (capitalize(XXX->query_name()))
#define TR(XXX, YYY) tell_room( this_object(), XXX, ({YYY}) )
#define TP(XXX, YYY) tell_object( XXX, YYY )

int max_attempts;
string room_type;

// Forward declarations
object check_for_gathersource_type( string alias );

//Accessors and Getters
void set_max_attempts( int attempts ) { max_attempts = attempts; }
int query_max_attempts() { return (max_attempts ? max_attempts : 3); }

void set_room_type( string type ) { room_type = type; }
string query_room_type() { return room_type; }



void reset(status arg) {
    if (arg) return;

    set_short("Scaveng Room");
    set_long ("This is a test room of the scavenge system.\n");
    set_weather(5, 5, 5);
    set_exits(({
        "/wiz/emraef/workroom.c", "west",
        "/wiz/emraef/open/scav/storeroom.c", "south",
    }));

    set_room_type( "test" );
}

//-----------------------------------------------------------------
void init()
{
    ::init();

    add_action( "do_scavenge", "scavenge" );
}

//-----------------------------------------------------------------
object check_for_gathersource_type( string alias )
{
    return present( alias );
}

//-----------------------------------------------------------------
void scavenge_cleanup(object player)
{
    object ob = player->query_calloutwatch_object(this_object());
    destruct( ob );
}

//-----------------------------------------------------------------
void scavenge_cancel(object player)
{
    TP( player, "You abandon your scavenging and move on.\n" );
    remove_call_out( "do_scavenge_2" );
    remove_call_out( "do_scavenge_3" );
    scavenge_cleanup(player);
}

//-----------------------------------------------------------------
int do_scavenge( string verb, string arg )
{
    if( sizeof( query_room_type() ) <= 0 )
    {
        TP( this_player(), "You cannot scavenge here\n" );
        return 1;
    }
    
    if( this_player()->query_calloutwatch_object(this_object()) )
    {
        TP( this_player(), "You seem a little busy do be doing that right now...\n" );
        return 1;
    }

    if( find_call_out( "do_scavenge_2" ) != -1 || find_call_out( "do_scavenge_3" ) != -1 )
    {
        TP( this_player(),  "Somone is already scavenging here...\n" );
        return 1;
    }

    TR( CAP_NAME(this_player()) + " starts scavenging...\n", this_player() );
    TP( this_player(), "You start scavenging...\n" );

    call_out( "do_scavenge_2", 4, this_player(), 0 );

    clone_object( "/obj/shadows/calloutwatch.c" )->calloutwatch( this_player(), this_object(), "scavenge_cancel" );


    return 1;
}

//-----------------------------------------------------------------
void do_scavenge_2( object player, int attempts )
{
    // do the skill roll to see if they pass
    int roll = random(100);
    if( roll < 30 || attempts+1 > query_max_attempts() )
    {
        // SUCCESS! we have a success on finding... something.
        // The following calls out to scav3 and passes how successful 0 - 100
        call_out( "do_scavenge_3", 4, player, (int)(((30 - roll) / 30.0) * 100) );
    }
    else
    {
        call_out( "do_scavenge_2", 4, player, attempts+1 );
    }

    TR( CAP_NAME(player) + " continues to scavenge...\n", player );
    TP( player, "You keep on scavenging...\n" );
}

//-----------------------------------------------------------------
void do_scavenge_3( object player, int success )
{
    scavenge_cleanup(player);

    object newSource = RESOURCE_D->create_source_by_room_type( this_object(), room_type );

    if( !newSource )
    {
        //LOG( "newSource == NULL" );
        TR( CAP_NAME(player) + " didn't find anything.\n", player );
        TP( player, "You don't find anything and give up.\n" );
        return;
    }

    string type = newSource->query_source_type();

    object ob;
    if( ob = check_for_gathersource_type( newSource->query_alias() ) )
    {
        TR( CAP_NAME(player) + " finds some more " + type + ".\n", player );
        TP( player, "You find more " + type + ".\n" );

        ob->add_num_gathers( newSource->query_num_gathers() );

        destruct( newSource );

        return;
    }
    
    move_object( newSource, this_object() );

    TP(player, "You scavenged some " + type + ".\n" );
    TR(CAP_NAME(player) + " scavenged some " + type + ".\n", player );
}

