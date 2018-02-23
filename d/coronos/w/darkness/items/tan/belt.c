#include <mudlib.h>
inherit CLOTHING;
 
reset(arg) {
  if(arg) return;
  set_name("belt");
  set_alias("leather");
  set_short("a leather belt");
  set_long(
    "This is a leather belt used to keep your pants up.\n"+
    "It is made from tanned animal hide, and looks strong\n"+
    "and sturdy.  The belt has been made well.\n");
  set_smell("The belt smells like new leather.\n");
  set_weight(1);
  set_value(175);
  set_sell_destruct(1);
}
