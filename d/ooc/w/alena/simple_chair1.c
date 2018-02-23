#include <mudlib.h>
inherit "inherit/chair";

reset(arg) {
    ::reset(arg);
    if(arg)return;
    set_name("simple chair");
    set_short("a simple wooden chair");
    set_alias("chair");
    set_long("The chair looks old and well used. It is made from "+BS(n)+
      "a light wood and the legs and seat look scratched up."+BS(n));
    set_max_sitters(1);
    set_weight(2000);
}
