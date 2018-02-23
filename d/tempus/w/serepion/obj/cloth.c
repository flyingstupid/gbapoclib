#include <mudlib.h>
inherit CLOTHING;

void reset(status arg) {
  if(arg) return;
  set_short("a piece of cloth");
  set_name("cloth");
  set_weight(2);
  set_value(0);
  set_long("A piece of torn cloth a mouse dragged in.\n");
}
