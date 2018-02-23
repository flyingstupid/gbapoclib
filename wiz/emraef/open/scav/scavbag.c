/* The base Scavenger bag (scavbag) */

#include <mudlib.h>
#include <ansi.h>
#include "/wiz/emraef/open/scav/scavpaths.h"

inherit CONTAINER;

void reset(status arg) 
{
    if(arg) return;
    set_name("scavbag");
    set_plural("scavbags");
    set_alias("bag");
    set_short("A large scavbag");
    set_long("A large bag used to carry scavenged items.\n");
    set_max_weight(25);
    set_value(0);
    set_weight(0);
}

status can_put_and_get()
{
    return 0;
}

status look_at(string arg)
{
    int total_pips = 17;
    tell_object( this_player(), "-----[SCAVBAG]-----\n" );

    int pip_count = (int)(((float)query_container_weight() / query_max_weight()) * 17);
    string fullness = "[";

    // do color
    fullness += BOLD;
    if( pip_count > (total_pips-3) )
        fullness += RED_B;
    else if( pip_count > (total_pips/2) )
        fullness += YELLOW_B;
    else
        fullness += GREEN_B;

    for( int i = 0; i < total_pips ; i++ )
    {
        //TODO CHECK FOR ANSI ON
        if( false )
        {
            if( i < pip_count ) 
            {
                fullness += "|";
            }
            else
            {
                fullness += " ";
            }
        }
        else
        {
            if( i >= pip_count )
            {
                fullness += OFF;
            }

            fullness += " ";
        }
    }

    tell_object( this_player(), fullness + OFF + "]\n" );

    this_player()->show_inventory( this_object() );

    return 1;
}

