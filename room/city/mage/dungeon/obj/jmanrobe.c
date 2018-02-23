#include <mudlib.h>

inherit MAGIC_ARMOUR;

void reset(status arg) {
    if(arg) return;
    set_name("robe");
    set_alias("robes");
    set_short("white robes");
    set_long(
      "These robes carry the markings of a White Robed mage. The hem of this \n"+
      "traditional garment is lined with silvery runes of various sorts.\n");
    set_type("cloak");
    set_armour_material("cloth");
    set_enchanted(1);
    set_sell_destruct(1);
    set_weight(1);
    set_ac(1);
    set_value(900);
    set_info(
      "Robes of protection, conveying magical cover from fire.\n");
    set_protection("fire");
}
