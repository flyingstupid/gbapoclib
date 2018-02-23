#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("Center of Second Chance");
    set_long(
      "Center of Second Chance\n"+
      "Standing here admists all the other survivors you can see that\n"+
      "life in fact does go on. The crossroads here is filled with  \n"+
      "activity. People constantly passing through with chores to do \n"+
      "to ensure their survival. The dirt roads lead in every direction,\n"+
      "to the south is the stockpile, to the west is the training houses\n"+
      "and general store, to the east is the inn and finally to the north\n"+
      "is the gate that leads into the forest.\n");   
    set_exits(({
    "d/wastelands/w/critical/secondtry/city1","hall",
    "d/wastelands/w/critical/secondtry/city3","south",
    "d/wastelands/w/critical/secondtry/city7","north",
    "d/wastelands/w/critical/secondtry/city4","east",
    "d/wastelands/w/critical/secondtry/city8","west",
    }));
}
