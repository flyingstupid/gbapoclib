#include <mudlib.h>
inherit MAGIC_ARMOUR;

reset(arg) {
  if(arg) return;
  set_name("amulet");
  set_type("amulet");
  set_short("Bronze Amulet");
  set_long("Elfin hands made this fine bronze amulet centuries ago. \n"+
           "A mighty eagle are carved into the soft metal. \n");
  set_ac(1);
  set_weight(1);
  set_value(300);
  set_armour_material("bronze");
  set_sell_destruct(1);
}

