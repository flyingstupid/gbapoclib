/* Darkness 97 */

#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
  if(arg) return;
 
  set_name("knife");
  set_short("a sharp knife");
  set_plural("sharp knives");
  set_long(
    "This knife is very sharp and deadly.  The blade shine a bright\n"+
    "silver color that matches the greenish black hilt.  It is very\n"+
    "well crafted, possibly the work of elves.\n");
  set_extra_info(
    "The knife feels very well balanced and the blade is very sharp.\n"+
    "This is a +1 weapon.\n");
  set_length(12);
  set_type("slash");
  set_sell_destruct(1);
  set_value(500);  /* Because it's +1 */
  set_wc(7); /* +1 */
  set_weight(3);
}
