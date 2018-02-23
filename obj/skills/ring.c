/* the std wedding ring that clerics use to marry people with */

#include <mudlib.h>
inherit CLOTHING;

void reset(status arg) {
  if(arg) return;
  set_short("a golden ring");
  set_long("A beautiful gold wedding band.\n");
  set_weight(1);
  set_value(1000);
}

status drop(status quit) { return 1; }
status get(status quit)  { return 0; }

void long(status wiz) {
  ::long(wiz);
  write("It represents your vows of commitment to "+
	(string)environment()->query_spouse()+".\n");
}
