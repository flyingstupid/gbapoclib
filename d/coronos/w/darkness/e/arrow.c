#include <mudlib.h>
inherit TREASURE;
 
static int bonus;
 
void reset(status arg) {
  if(arg) return;
  set_name("arrow");
  set_short("An arrow");
  set_long(
  "This arrow is made from a fine wood, carved with expert hands, and\n"+
  "has a head made from cold worked steel. This would be a fine addition\n"+
  "to a quiver of arrows.\n");
 
  set_info("The arrow must go in a quiver to be effective.\n");
 
  set_plural("arrows");
  set_weight(1);
  set_sell_destruct(1);
  set_value(1);
  set_plural("arrows");
}
 
int query_ammunition_bonus()    { return bonus;     }
int set_ammunition_bonus(int i) { return bonus = i; }
 
