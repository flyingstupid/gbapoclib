#include <mudlib.h>

inherit WEAPON;
 
reset(arg) {
    if(arg) return;
 
  set_name("shortsword");
  set_alias("sword");
  set_short("a shortsword");
  set_long(
    "This is a well crafted shortsword.  It has been balanced with\n"+
    "great accuracy to make swift attacks.  Engraved upon the hilt\n"+
    "is an insignia of some sort.\n");
  set_length(24);
  set_type("slash");
  set_value(1200);
  set_wc(11);
  set_weight(3);
}
 

