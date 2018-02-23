#include <mudlib.h>
inherit MAGIC_ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("amulet");
  set_short("a gold amulet");
  set_long(
    "This gold amulet is a perfect circle hanging from a thin, golden chain.\n"+
    "It is decorated with a small design of a circular rune with many lines\n"+
    "radiating out from the center.  Smaller runes and designs cover every\n"+
    "inch of the amulet.  The amulet seems to glow faintly right now.\n");
  set_type("amulet");
  set_ac(1);
  set_weight(1);
  set_armour_material("Gold");
  set_sell_destruct(1);
  set_enchanted(1);
  set_arm_light(4);
  set_value(1000); /* Very powerfull light source.  Unique. */
}
