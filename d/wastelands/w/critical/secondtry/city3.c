#include <mudlib.h>
inherit STORE_ROOM;
 
void reset(status arg) {

    ::reset(arg);
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("Second Chance's Stock Pile");
    set_long(
      "Second Chance's Stock Pile\n"+
      "Stacked up in neat rows are tons of supplies for the city set\n"+
      "on a huge stone slab. Its covered with a corrugated steel roof to\n"+
      "protect the senstive supplies but is otherside open to the air. \n"+
      "Every person in the city is given a space here to store their finds.\n"+
      "In return the city offers to buy some of the supplies it needs through\n"+
      "a credit system. Here you can drop off your supplies and or sell your\n"+
      "finds for credits. A sign is posted on a supporting pillar.\n");   
    set_exits(({
    "d/wastelands/w/critical/secondtry/city2","north",
    }));
    set_items(({
     "sign", "-=-Dropping off supplies-=-\n"+
     "UNLOAD - This will unload your scavenging backpack into your supply area\n"+
     "SELLALL - This will transfer all of your scavenging backpack supplies to credits\n"+
     "LIST - This will display whats in your supply area\n"+
     "RETRIEVE (item) [amount] - This will take out items from your supply area\n"}));
}
