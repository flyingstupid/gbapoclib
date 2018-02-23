#include <mudlib.h>
#include "/wiz/emraef/open/scav/scavpaths.h"

inherit BASE;

string resource_type;

void set_resource_type( string new_type ) { resource_type = new_type; }
string query_resource_type() { return resource_type; }

void reset(status arg) 
{
    if(arg)
        return;

    set_name("resource_base");
    set_short("resource base object");

    set_long(
            "This is a resource base object and should not have been\n"+
            "cloned.\n");

    set_weight(0);
    set_value(0);
    set_sell_destruct(0);
    set_alias("resource base");
}


