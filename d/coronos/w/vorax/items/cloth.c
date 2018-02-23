#include <mudlib.h>
inherit TREASURE;
void reset(status arg) {
  ::reset(arg);
  
  if(arg) return;
  set_name("cotton cloth");
  set_short("a piece of cotton cloth");
  set_alias("cloth");
  set_long(
    "This is a piece of cotton cloth. It is very durable, but not\n"+
    "very pretty.\n");
  set_weight(3);
  set_value(30);
}

