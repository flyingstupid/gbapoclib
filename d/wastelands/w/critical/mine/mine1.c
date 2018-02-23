#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("Entrance to the mineshaft");
    set_long(
      "Rough stone carved smooth from digging into the earth rests at"+
      "reachable levels. In front of you is a mineshaft that leads downword"+ "into the mine itself. From here you can enter the mine.");
    set_exits(({"d/wastelands/w/critical/forest/forest_1","out",
    "d/wastelands/w/critical/mine/mine2.c", "enter",}));
}