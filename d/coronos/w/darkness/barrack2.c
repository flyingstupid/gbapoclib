/* Darkness & Lean */

#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {

  if(!present("guard")){
    move_object(clone_object(
    "/d/coronos/w/darkness/npc/sguard"),
    this_object());
  }

if (arg) return;
 
set_short("barracks sleeping quarters");
set_long (
  "This is the sleeping quarters for the guards. There are several\n"+
  "cots here each with a straw tick. At the foot of each cot lies\n"+
  "a chest. There are sconces on the walls here to light the room\n");
set_day_desc (
  "The sconces are unlit to conserve fuel during the day.\n");
set_night_desc (
  "The sconces are lit, producing a soft glow.\n");
set_items (({
  "thatch#roof",
    "The roof is made of straw.\n",
  "beam#beams",
    "The beams support the roof, they look a little dusty.\n",
  "sconce#sconces",
    "Small enclosed lanterns are evenly spaced along the wall.\n",
  "wall#walls",
    "The walls are made of stone held togater with mortar.\n",
  "cot#cots",
    "The cots are each covered with a straw tick.\n",
  "tick#straw tick",
    "The straw tick looks verry scratchy, and seems to be full of\n"+
    "bedbugs.\n",
  "chest#chests",
    "The chests apear to be empty except for some personal\n"+
    "belongings of no value.\n",
  "bedbug#bedbugs",
    "The straw seems to be a breeding ground for these small\n"+
    "bloodsucking bugs.\n",
  }));
set_weather(2,2,0);
set_exits (({
  "/d/coronos/w/darkness/barrack1", "east",
  }));


}

