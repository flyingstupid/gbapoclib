/* egg2.c  cooked egg*/
/* Darkness */

#include <mudlib.h>
inherit FOOD;

void reset(status arg) {

  ::reset(arg);

  if(arg) return;

  set_name("cooked chicken egg");
  set_short("a fried egg");
  set_alias("egg");
  set_long(
    "This is a tasty looking fried egg.\n");
  set_smell(
    "The fried egg smells freshly cooked.\n");
  set_value(0);                
  set_weight(1);
  set_strength(4+random(6));
}
