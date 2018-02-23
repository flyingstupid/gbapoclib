//
//  wiz/kate/open/city_objects/generator.c

#include <mudlib.h>
inherit BASE;
void reset(status arg)
{
    if(arg) return;
    
    set_name("petrol");
    set_alias("petrol");
    set_short("refined petrol");
    set_long("a small can of refined petrol");
    set_extra_info("This is a very small can of refined petrol.  It is \n"
                   "quite rare and valuable.\n"
                   );
}

status get()
{
    return 1;
}