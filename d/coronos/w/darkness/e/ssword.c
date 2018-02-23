/*Darkness97*/
#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
  if(arg) return;
 
  set_name("Shortsword");
  set_short("a shortsword");
  set_alias("sword");
  set_long(
    "This is a short sword of elvish make.  The sharp blade looks very\n"+
    "deadly.  The hilt has a leather grip tied with black cord.  The\n"+
    "guard is simple, with a greyish gem in the center.\n");
  set_extra_info(
    "This sword feels very well balanced.  It is a +1 weapon.\n");
  set_length(24);
  set_type("slash");
  set_value(960);
  set_sell_destruct(1);
  set_wc(11); /* +1 */
  set_weight(4);
}
