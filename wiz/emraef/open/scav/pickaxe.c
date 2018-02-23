#include <mudlib.h>

#define NAME	(string)this_player()->query_name()

inherit BASE;

void reset(status arg) 
{
    if(arg) return;
    set_name("pickaxe");
    set_plural( "pickaxes" );
    set_short("a pickaxe");

    set_long(
            "This is a pickaxe\n");

    set_weight(1);
    set_value(0);
    set_alias("pickaxe");

}

status get()
{
    return 1;
}
