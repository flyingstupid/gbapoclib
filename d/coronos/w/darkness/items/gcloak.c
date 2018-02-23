#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("Hooded burgandy cloak");
  set_alias("cloak");
  set_short("a hooded burgandy cloak");
  set_long(
    "This is the heavy burgandy cloak that is worn by Gitane, the keeper.\n"+
    "of the Dancing Flame Candle Shop.  It drapes down to the floor and\n"+
    "has a wide hood.  It is trimmed in silver thread.\n");
  set_type("cloak");
  set_armour_material("cloth");
  set_ac(1);
  set_weight(2);
  set_plural("burgandy cloaks");
  set_value(200);
  set_sell_destruct(1);

}
