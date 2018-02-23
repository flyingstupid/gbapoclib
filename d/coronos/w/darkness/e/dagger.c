/*Darkness 97*/
#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
  if(arg) return;
 
  set_name("Dagger");
  set_short("a dagger");
  set_long(
    "This is a long dagger of elvish make.  The sharp blade looks very\n"+
    "deadly.  The hilt has a leather grip tied with black cord.  The\n"+
    "guard is simple, with a greyish gem in the center.\n");
  set_extra_info(
    "This dagger feels very well balanced.  It is a +1 weapon.\n");
  set_length(15);
  set_type("slash");
  set_value(500);
  set_sell_destruct(1);
  set_wc(9); /* +1 */
  set_weight(3);
}
