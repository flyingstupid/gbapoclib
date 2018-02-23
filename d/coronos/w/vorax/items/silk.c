#include <mudlib.h>
inherit TREASURE;
void reset(status arg) {
  ::reset(arg);
  
  if(arg) return;
  set_name("silk cloth");
  set_short("a piece of silk cloth");
  set_alias("cloth");
  set_long(
    "This is a piece of silk cloth. It is very shiny and smooth\n"+
    "but it isn't very durable.\n");
  set_weight(1);
  set_value(10);
}

