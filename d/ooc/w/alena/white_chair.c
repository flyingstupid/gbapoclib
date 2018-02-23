#include <mudlib.h>
inherit "inherit/chair";

reset(arg) {
    ::reset(arg);
    if(arg)return;
    set_name("white chair");
    set_short("A white chair");
    set_alias("chair");
    set_long("A simple white leather lounge chair that looks so very \n"+
"comfortable, seeming to beg you to sit down and rest awhile.\n");
    set_max_sitters(4);
    set_weight(2000);
}

