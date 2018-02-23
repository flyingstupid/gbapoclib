/* dagger.c */
/* Darkness and Newstar */

#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
  if(arg) return;
 
  set_name("dagger");
  set_short("a drow dagger");
  set_plural("drow daggers");
  set_long(
    "This is a small dagger made from Drow materials.  The guard is\n"+
    "a dull grey color, and is simply made.  A simple spiral patern\n"+
    "is all that decorates this weapon.\n");
  set_length(12);
  set_type("slash");
  set_sell_destruct(1);
  set_value(110);
  set_wc(6);
  set_weight(3);
}
