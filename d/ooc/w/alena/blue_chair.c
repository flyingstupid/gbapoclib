#include <mudlib.h>
inherit "inherit/chair";

reset(arg) {
    ::reset(arg);
    if(arg)return;
    set_name("blue chair");
set_short("a comfy blue chair");
    set_long("An overstuffed blue chair that looks so very comfortable, "+BS(n)+
      "seeming to beg you to sit down and rest awhile."+BS(n));
    set_max_sitters(1);
    set_weight(2000);
}
