#include <mudlib.h>
inherit TREASURE;
void reset(status arg) {
  ::reset(arg);
  
  if(arg) return;
  set_name("rayon cloth");
  set_short("a piece of rayon cloth");
  set_alias("cloth");
  set_long(
    "This is a piece of rayon cloth. It is soft and shiny, and is\n"+
    "fairly durable too.\n");
  set_weight(2);
  set_value(20);
}

