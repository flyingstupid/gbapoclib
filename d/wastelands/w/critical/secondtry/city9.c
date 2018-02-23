#include <mudlib.h>
inherit STORE;
 
void reset(status arg) {
    
    if(arg) return;
    
    
    
    set_owner("Jason");
    add_sell_items("Armour");
    add_sell_items("Weapon");
    add_sell_items("Treasure");
    
    
    set_weather(2, 1, 0);
    set_short("Second Chance's General Store");
    set_long(
      "Second Chance's General Store\n"+
      "Within these walls are some of the best supplies the Waste Runners have found.\n"+
      "The building is full of weapons, pieces of armor, and god only knows what else.\n"+
      "The store is run like everything else. Credits from the stockpile make the world\n"+
      "go round, but if you were going to spend them on something. This would be the\n"+
      "place to do it.\n"
      );   
    set_exits(({
    "d/wastelands/w/critical/secondtry/city8","north",
    }));
}
