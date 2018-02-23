#include <mudlib.h>
inherit FOOD;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("carrot");
  set_short("a carrot");
  set_long(
   "This is a large, fresh carrot. It still needs to be cleaned, but it\n"+
   "looks quite orange and tasty regardless of a little dirt.  Whoever\n"+
   "grew this vegetable must be a good gardener.\n");
  set_smell(
   "The carrot smells sweet and yummy.\n");
  set_value(0);                /*to not buy*/
set_strength(90);
  set_weight(1);              
}
