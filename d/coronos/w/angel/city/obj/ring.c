#include <mudlib.h>
inherit ARMOUR;

void reset(status arg) {
  if(arg) return;

  set_type("ring");
  set_short("A gold ring");
  set_name("ring");
  set_weight(1);
  set_ac(2);
  set_value(900);
  set_info(
	"This is a ring endowed with magical protection.\n");
  set_long(
	"This is a simple ring with the symbol of the \n"+
	"All-God enscribed into its surface. The ring \n"+
	"looks as new as the day it was made.\n");
  set_sell_destruct(1);
}
