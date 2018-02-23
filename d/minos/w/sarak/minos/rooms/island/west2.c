#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit STORE;

void reset(status arg) {

  ::reset(arg);
  if(arg) return;
  set_short("The Island Shop");
  set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"\tMinotaur Island General Store\n"+
"Here in a dark corner of the forest lies an ancient shop. The building\n"+
"is extremely old and looks like it is about to collapse. Towards the\n"+
"rear of the building are a few items the shopkeeper has bought over\n"+
"the years from brave adventurers like yourself. There is also an old\n"
"bark sign leaning up against the wall.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  set_weather(1,4,2);
  set_exits(({
    ISLAND_ROOMS+"west1",  "south",
  }));
  set_owner("Galdor");
  set_sell_treasure(1);
  set_sell_armour(1);
  set_sell_weapon(1);
} 
