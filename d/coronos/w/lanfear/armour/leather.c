#include <mudlib.h>
inherit ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("armour");
  set_short("A suit of leather armour");
  set_long(
	"A fine pair of gloves bearing traditional elvish \n"+
	"designs on the gloves. The owner of this armour must  \n"+
	"be amoung the pride of the elvish nations outside Tempus.  \n");
  set_type("armour");
  set_ac(1);
  set_weight(2);
  set_value(200);
  set_sell_destruct(1);
}
