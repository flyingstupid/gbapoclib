/*  This is UNIQUE armour for Newbies.  There isn't anything special about
    it statistic-wise, but it has a unique description.  The armour once
    was used by Grandpa Newman when he was younger.
*/

#include <mudlib.h>
inherit ARMOUR;
 
reset(arg) {
  if(arg) return;
  set_name("soldier's armour");
  set_alias("armor");
  set_short("Lieutenant Class soldier's armour");
  set_long(
    "This armour is very elegant and battle-worthy.  It is quite old, but\n"+
    "is in almost perfect condition.  Tiny scratches mark up the bronze\n"+
    "gilded chestplate and shoulder coverings, which are clear reminders\n"+
    "of the many battles it has survived.  Lieutenant stripes decorate the\n"+
    "right shoulder guard, and a Soldier's Crest adorns the left side of\n"+
    "the chestplate.  This style of armour is out of date, but serves its\n"+
    "purpose to the novice soldier of this time.\n");
  set_type("armour");
  set_armour_material("Iron");
  set_ac(4);
  set_weight(6);
  set_value(1600);
  set_sell_destruct(1);
}
