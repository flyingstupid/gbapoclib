#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("small brooch");
  set_alias("brooch");
  set_short("a small brooch");
  set_long(
    "This is a very old brooch found wedged in a small crack in a rock.\n"+
    "It must have been in that crack for a long time, unfound by its\n"+
    "original owner.  There are many intricate designs on the face of\n"+
    "the pin, including the engraving of a rose which is in the center\n"+
    "of the beautiful brooch.\n");
  set_type("amulet");
  set_ac(1);
  set_weight(1);
  set_sell_destruct(1);
  set_value(280);
}
 
