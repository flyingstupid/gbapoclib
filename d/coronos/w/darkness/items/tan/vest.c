#include <mudlib.h>
inherit CLOTHING;
 
reset(arg) {
  if(arg) return;
  set_name("vest");
  set_alias("leather");
  set_short("a leather vest");
  set_long(
    "This is a leather vest, made from tanned animal hide.\n"+
    "It is brand new and a little stiff, but once it's broken\n"+
    "in a little, it will be soft and very comfortable.\n");
  set_smell("The vest smells of new leather.\n");
  set_weight(2);
  set_value(600);
  set_sell_destruct(1);
}
