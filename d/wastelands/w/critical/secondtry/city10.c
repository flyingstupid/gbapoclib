#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("West Road in Second Chance");
    set_long(
      "West Road in Second Chance\n"+
      "Place holder for description");   
    set_exits(({
    "d/wastelands/w/critical/secondtry/city8","east",
    "d/wastelands/w/critical/secondtry/city11","north"
    }));
}
