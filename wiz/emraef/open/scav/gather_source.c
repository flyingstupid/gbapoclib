#include <mudlib.h>
#include "/wiz/emraef/open/scav/scavpaths.h"

#define CAP_NAME(XXX) (capitalize(XXX->query_name()))
#define TR(XXX, YYY) tell_room( environment( this_object() ), XXX, ({YYY}) )
#define TP(XXX, YYY) tell_object( XXX, YYY )

#define MAX_ATTEMPTS (3)

inherit BASE;

string gather_object;
int num_gathers;
int difficulty;
string source_type;
string required_item;

// Forward declarations
object get_scavbag( object player );


// Accessors and Queries
void set_gather_object( string type ) { gather_object = type; }
string query_gather_object() { return gather_object; }

void set_difficutly( int diff ) { difficulty = max( 1, diff ); }
int query_difficulty() { return difficulty; }

void add_num_gathers( int num ) { num_gathers += max( 0, num); }
void set_num_gathers( int num ) { num_gathers = max( 0, num ); }
int query_num_gathers() { return num_gathers; }

void set_source_type( string type ) { source_type = type; }
string query_source_type() { return source_type; }

void set_required_item( string item ) { required_item = item; }
string query_required_item() { return required_item; }

//-----------------------------------------------------
void reset(status arg) 
{
    if(arg)
        return;

    set_name("gather_source");
    set_short("gather source");

    set_long(
            "This is the default gather_source you should not see\n"+
            "this. If you are a player this is surely a bug.\n");

    // set weight incase overriding get doesnt work.
    set_weight(1000000);
    set_alias("gather source base");
}

//-----------------------------------------------------
void init() 
{
    ::init();
    add_action("do_gather", "gather");
}

object get_scavbag( object player )
{
    if( !player )
    {
        return 0;
    }

    object *inv = all_inventory( player );

    for( int i = 0; i < sizeof( inv ); i++ )
    {
        if( is_a( SCAVBAG, inv[i] ) )
            return inv[i];
    }

    return 0;
}

//-----------------------------------------------------
status get()
{
    // make sure we can't get this object
    return 0;
}

status can_put_and_get()
{
    return 0;
}

status long(status wiz)
{
    ::long(wiz);
    tell_object( this_player(), "\nYou'd guess there are about " + num_gathers + " units left\n" );

    return 1;
}




//-----------------------------------------------------
// Gather command functions below:
//-----------------------------------------------------


//-----------------------------------------------------
void gather_cleanup(object player)
{
    object ob = player->query_calloutwatch_object(this_object());
    destruct( ob );
}

//-----------------------------------------------------
void gather_cancel(object player)
{
    TP( player, "You abandon your gathering and move on.\n" );
    remove_call_out( "do_gather_2" );
    remove_call_out( "do_gather_3" );
    gather_cleanup(player);
}

//-----------------------------------------------------
status do_gather( string arg )
{
    //LOG( "do_gather arg: " + arg + " " + query_source_type() );
    if( arg && arg != "" && arg != query_source_type() )
        return 0;

    if( query_gather_object() )
    {
        if( this_player()->query_calloutwatch_object(this_object()) )
        {
            TP( this_player(), "You seem a little busy do be doing that right now...\n" );
            return 1;
        }

        if( find_call_out( "do_gather_2" ) != -1 || find_call_out( "do_gather_3" ) != -1 )
        {
            TP( this_player(),  "Somone is already gathering from " + this_object()->query_short() + ".\n" );
            return 1;
        }

        if( required_item && required_item != "" && !present( required_item, this_player() ) )
        {
            TP( this_player(), "You don't have the right tools for the job.\n" );
            return 1;
        }

        call_out( "do_gather_2", 4, this_player(), 0 );

        clone_object( "/obj/shadows/calloutwatch.c" )->calloutwatch( this_player(), this_object(), "gather_cancel" );

        TP( this_player(), "You start to gather from " + query_short() + "\n" );
        TR( CAP_NAME( this_player() ) + " starts to gather from " + query_short() + ".\n", this_player() );

        return 1;
    }

    return 0;
}

//-----------------------------------------------------
void do_gather_2( object player, int attempts )
{
    // do the skill roll to see if they pass
    int roll = random(100);
    if( roll < 30 || attempts+1 > MAX_ATTEMPTS )
    {
        // SUCCESS! we have a success on finding... something.
        // The following calls out to gather_3 and passes how successful 0 - 100
        call_out( "do_gather_3", 4, player, (int)(((30 - roll) / 30.0) * 100) );
    }
    else
    {
        call_out( "do_gather_2", 4, player, attempts+1 );
    }

    TR( CAP_NAME(player) + " continues to gather...\n", player );
    TP( player, "You keep on gathering...\n" );
}

//-----------------------------------------------------
void do_gather_3( object player, int success )
{
    gather_cleanup(player);

    object bag = get_scavbag( player );

    if( !bag )
    {
        TP( player, "You forgot your scavbag you have no where to put your goods.\n" );
        TR( capitalize( player->query_name() ) + " forgot his scavbag.\n", player );
        return;
    }

    object ob = RESOURCE_D->create_resource_by_type( query_gather_object() );

    if(!bag->add_weight( ob->query_weight() ) )
    {
        TP( player, "Your scavbag is too full!\n" );
        destruct( ob );
        return;
    }

    move_object( ob, bag );

    string type = ob->query_resource_type();


    num_gathers--;
    if( num_gathers == 0 )
    {
        TP(player, "You gather the last of the " + type + ".\n" );
        TR(CAP_NAME(player) + " gathers the last of the " + type + ".\n", player );

        destruct( this_object() );
    }
    else
    {
        TP(player, "You gathered some " + type + ".\n" );
        TR(CAP_NAME(player) + " gathered some " + type + ".\n", player );
    }
}

