#include <mudlib.h>
inherit MAGIC_ARMOUR;


/* if it was just standard armour
you would use inherit ARMOUR,
similarly, to make a weapon use inherit WEAPON
 */

void reset(status arg) {
  if(arg) return;
  set_name("platemail");
  set_short("A suit of platemail");
  set_long(
	"A fine suit of platemail armour bearing traditional elvish \n"+
	"designs on the breastplate. The owner of this armour must  \n"+
	"be amoung the pride of the elvish nations outside Tempus.  \n");
  set_type("armour");
  set_ac(5);
  set_max_charges(50);
  set_cast_level(20);
  set_charges(20);
  set_info("Magical armour, protecting the wielder from fire.\n");
  add_spell("fire ball");
  add_spell("burning hands");
  set_weight(6);
  set_value(4000);
  set_sell_destruct(1);
  set_protection("fire");
}

