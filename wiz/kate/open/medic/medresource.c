//
//  wiz/kate/open/medic/medresource.c
//
// object file for shaft part
//

#include <mudlib.h>
inherit BASE;

void reset(status arg)
{
    if(arg) return;
    
    set_name("medresource");
    set_alias("medresource");
    set_short("medresource");
    set_long("a medical resource");
    set_extra_info("This is a medical resource.\n"
                   "It can be converted into medkit items.\n"
                   );
    set_weight(1);
    set_value(0);
    set_alias("resource");
}

status get()
{
    return 1;
}