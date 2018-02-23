//
//  wiz/kate/open/city_objects/generator.c

#include <mudlib.h>
inherit BASE;
void reset(status arg)
{
    if(arg) return;
    
    set_name("generator");
    set_alias("generator");
    set_short("power generator");
    set_long("A very heavy power generator");
    set_extra_info("This is a large power generator, the type used to power\n"
                   "small towns.\n"
                   );
}

status get()
{
    return 0;
}