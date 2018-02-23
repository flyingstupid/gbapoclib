#include <mudlib.h>
inherit MAGIC_ARMOUR;

void reset(status arg) {
  if(arg) return;
  set_name("chainmail");
  set_alias("elfin chainmail");

  set_short("A suit of fine chainmail");
  set_long(
	"This is a fine suit of chainmail, whose links are fine \n"+
	"and delicate. It could be that this is the workmanship \n"+
	"of the elves, but a suit such as this one is a rare    \n"+
	"find indeed.\n");
  set_type("armour");
  set_sell_destruct(1);
  set_ac(4);
  set_weight(3);
  set_value(5600);
  set_info(
	"This is a suit of elfin chainmail given to Alexander \n"+
	"while he was a diplomatic advisor to Entannax from the\n"+
	"Council of Wyrms, and is made from the finest of adamantite.\n");
  set_protection("fire");
  set_armour_material("adamantite");
}

	

