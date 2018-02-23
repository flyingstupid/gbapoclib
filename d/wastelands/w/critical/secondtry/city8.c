#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("Second Chance's West Path");
    set_long(
      "Second Chance's West Path\n"+
      "Just beyond the crossroads of the town is the towns general store. This little\n"+
      "building is the culmination of all the traderable goods found in the wreckage\n"+
      "of the Megacity. Here citizens can trade in their stock pile credits for gear \n"+
      "to make exploring a bit easier. You constantly see Waste's Runners moving in\n"+
      "and out of the store, while making plans for their next big scavenge run. The\n"+
      "store itself is made just like all the other buildings in Second Chance, wooden\n"+
      "stacks piled to make a log cabin like feel. Though this building does have\n"+
      "windows, more than likely a good score from the runner's you see around you.\n"
      );   
    set_exits(({
    "d/wastelands/w/critical/secondtry/city10","west",
    "d/wastelands/w/critical/secondtry/city2","east",
    "d/wastelands/w/critical/secondtry/city9","south",
    }));

}
