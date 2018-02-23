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
  set_length(15);
  set_type("slash");
  set_value(280);
  set_wc(8); 
  set_weight(3);
}
