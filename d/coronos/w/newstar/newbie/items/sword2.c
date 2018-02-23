/* sword2.c -- Toy Sword -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
    if(arg) return;
 
  set_name("shortsword");
  set_alt_name("wood sword");
  set_alias("sword");
  set_short("a wooden sword");
  set_long(
    "This is a a short sword made from wood.  Little boys play with\n"+
    "with swords and other weapons such as these, pretending to be\n"+
    "knights and warriors.\n");
  set_length(14);
  set_type("slash");
   set_sell_destruct(1);
  set_value(10);
  set_wc(3);
  set_weight(4);
}
