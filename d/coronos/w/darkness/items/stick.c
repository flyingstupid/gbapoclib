#include <mudlib.h>
inherit WEAPON;

void reset(status arg){
  if(arg) return;

  set_name("club");
  set_alias("stick");
  set_short("a wooden stick");
  set_long(
    "This is a simple wooden stick that is sold at the woodshop\n"+
    "in Ille Coronos.\n");
  set_type("crush");
  set_wc(7); /* ..its not a good club, but its better than nothing! */
  set_length(60);
  set_value(30);
  set_weight(1);
  set_sell_destruct(1);
}
