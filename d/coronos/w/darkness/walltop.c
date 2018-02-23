#include <mudlib.h>
 
inherit ROOM;
 
void reset (status arg){
  if(arg) return;
 
  set_short("Atop a wall");
  set_long(
      "This is the top of the wall which is about one foot wide.\n"+
      "There is an oak tree growing next to the wall.  Its branches\n"+
      "stretch far out over the wall.");
  set_day_desc(
      "  From this vantage point,\n"+
      "much of the busy city can be seen.  Many people walk the streets\n"+
      "of Ille Coronos going about their buisness.\n");
  set_night_desc(
      "  The city of Ille Coronos\n"+
      "is much quieter at this time.\n");
  set_items(({
      "wall",
      "This is the wall that runs along Wall Street.  Its bricks are\n"+
      "made from red clay.  It is about one foot wide.\n",
      "bricks",
      "These bricks are made from red clay.\n",
      "tree#oak#oak tree",
      "This is a very large oak tree.  Its branches stretch out\n"+
      "from its great trunk.\n",
      "branches#branch",
      "These branches stretch out from the oak's trunk.\n",
      "trunk",
      "This is the tree's trunk.\n",
      "city",
      "This is the city of Ille Coronos.\n",
      }));
  set_smell( 
       "You smell the rich scent of the oak tree.\n");
  set_listen(
      "You hear the rustling of leaves.\n");
  set_weather(1, 4, 0);
  set_climb(6);
  set_fall_dam(10);
  set_exits(({
      "/d/coronos/w/darkness/wallst3", "down",
      "/d/coronos/w/darkness/oaktree", "tree",
      }));
}
void init(){
  ::init();
  add_action("climb", "climb");
  add_action("climb", "down");
  add_action("climb", "d");
}

void climb(){
  write("You climb down the wall.\n");  
  return;
}

