#include <mudlib.h>
inherit ARMOUR;

  void reset(status arg) {
  if(arg) return;
  set_name("amulet");
  set_alias("locket");
  set_short("a silver floral locket");
  set_long("\
A small floral locket on a thin leather strap. It is quite pretty.\n");
  set_ac(1);
  set_type("amulet");
  set_value(200);
  set_weight(2);
  set_enchanted(1);
  set_info(
	"This locket is enchanted with protection magicks, enough to \n"+
	"provide the wearer with the equivalent of leader armours.\n");
}
