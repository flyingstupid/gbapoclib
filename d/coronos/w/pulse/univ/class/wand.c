/******************************************************************************
 * univwand.c
 * Wand class for Mage Univ standard wands (ice is default)
 * 
 * Pulse
 * October, 1996
 */
 
#include <mudlib.h>
inherit "/objects/wand";
 
string set_wand_type() {
  return "ice";
}
 
void init_wand_features() {
  set_spells( ({
    "ice cream", "cone of cold",
    "freeze", "chill touch",
  } ));
  this_player()->set_protection("cold");
}
 
void reset(status arg) {
  if (arg) {
    return;
  }
  
  ::reset(arg);
  
  set_short("College Standard Issue "+set_wand_type()+" wand");
  set_long(
    "This is a standard issue wand of "+set_wand_type()+" from the College\n"+
    "of Extraphysical Sciences.\n"
  );
  
  set_cast_level(10);
  set_value(1000);
  set_charges(50);
  
  init_wand_features();
}
 
