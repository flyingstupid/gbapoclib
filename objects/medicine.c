#include <mudlib.h>
#include "/wiz/emraef/open/scav/scavpaths.h"

inherit TREASURE;

string resource_type;

void set_resource_type( string new_type ) { resource_type = new_type; }
string get_resource_type() { return resource_type; }
string query_object_type() { return "resource"; }


void reset(status arg) 
{
    if(arg)
        return;

    set_name("medicial resource");
    set_short("medicial resource");

    set_long("This is a handful of medicines, pills, and salves.\n");

    set_weight(0);
    set_value(0);
    set_sell_destruct(0);
    set_alias("medicine");
    set_resource_type("medicine");

    
}


