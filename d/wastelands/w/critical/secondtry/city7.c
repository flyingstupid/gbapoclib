#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("The Entrance to Second Chance City");
    set_long(
      "The Entrance to Second Chance City\n"+
      "Standing 20 feet into the air is a massive wooden gate designed to protect the\n"+
      "city of Second Chance. Its construction along with the city's equally large walls\n"+
      "helps keep the city safe from the preditors of the new world. A guard station is\n"+
      "also here, supplied with things to alert the town of danger. To the south is the\n"+
      "center of the town and to the north leads into the forest that surrounds Second\n"+
      "Chance and provides the fresh food, water and materials that makes life possible\n"+
      "out here in since the bombs dropped.\n"
      );   
    set_exits(({
    "d/wastelands/w/critical/secondtry/city2","south",
    "d/wastelands/w/critical/forest/forest_7","gate",
    }));
    set_items(({
    "gate","A massive wood gate lashed together with rope bars the entrance and exit\n"+
    "from the town when closed\n" }));
}
