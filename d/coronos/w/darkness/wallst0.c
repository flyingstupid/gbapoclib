/* wallst0.c -- Ille Coronos */
/* Darkness */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  object ob;
  int i;
 
  if(!present("guard")) {
    for(i=0; i<2; i++) {
      ob = clone_object("d/coronos/w/angel/city/monst/guard1");
      move_object(ob, this_object());
    }
  }
 
  if(!find_living("malf")) {
    move_object(clone_object(
    "d/coronos/w/darkness/npc/malf"), this_object());
  }
 
  if(!find_living("frank, the vendor")) {
    move_object(clone_object(
    "d/coronos/w/darkness/npc/frank"), this_object());
  }

  reset_doors(0);
  load_door(({
	"file", "d/coronos/w/angel/scanthian/road1",
        "direction", "north gate",
        "long",
	"The North Gate forms a set of archways some sixty feet above your head, \n"+
	"leading to the trade routes that span out from this fine city. Set into \n"+
	"the walls of the Gate are the doors that lead into the barraks of the   \n"+
	"12th garrison who guard the north walls against intruders.\n",

  }));
 
 
   load_door(({
   "destination",     "d/coronos/w/angel/city/gardens/garden1",
   "direction",       "south gate",
   "closed",
   "description",
"The gate leads southward, towards the inner garden.\n",
    }));
 
  if (arg) return;
 
  set_short("Wall Street");
  set_long(
	"This cobblestone road continues from east to west.  A long, brick \n"+
	"wall stretches along next to the road.  Vines and moss grow on    \n"+
	"the wall, and a few shrubs line the opposite side of the road.    \n"+
	"An iron gate stands here, leading south into the city gardens,    \n"+
	"dwarved by the massive construction of the Great North Gate, that \n"+
	"leads out of the city to the trade routes of the Northern Continent.\n");


  set_day_desc(
      "Several pairs of unlit lamps hang from hooks along the walls of the North Gate.\n");
  set_night_desc(
      "Several pairs of lamps hang from hooks along the walls of the North \n"+
      "Gate, illuminating travellers way through the grand archway.\n");
  set_items(({
	"door#doors#doorway#archway#archways",
	"You spy several doors set into the walls of the great North Gate. Each  \n"+
	"leads upward into the barracks of the 12th garrison who are stationed   \n"+
	"here permanently. The captain of this troup is said to be always looking\n"+
	"for new recruits. Perhaps you enter and find out what lays within?\n",
      "cobblestones#cobblestone",
      "These grey cobblestones have been smoothed and worn over time.\n",
      "road",
      "The road is paved with many cobblestones.\n",
      "wall#brick wall",
      "This is a long brick wall that runs along one side of the road.\n"+
      "It is made of red bricks.\n",
      "bricks#brick",
      "These bricks were made from red clay.\n",
      "vine#vines",
      "These green vines grow along the wall, clinging to the bricks.\n",
      "moss",
      "This green moss grows in patches on the wall.\n",
      "shrub#shrubs",
      "A few shrubs grow along the road, on the side opposite the wall.\n",
      "gate",
      "The gate is far to the west.  It seems top lead south towards\n"+
      "the gardens.\n",
      }));
  set_day_items(({
      "lamp#oil lamp#lamps#oil lamps",
      "These are simple oil lamps that hang from the gate.  They have metal\n"+
      "frames and glass panels.  The lamps is unlit right now.\n",
      }));
  set_night_items(({
      "lamp#oil lamp#lamps#oils lamps",
      "These are simple oil lamps that hang from the gate.  They have metal\n"+
      "frames and glass panels.  The lamps shine brightly, illuminating the\n"+
      "area.\n",
      }));
  set_smell(
      "You smell nothing but fresh air.\n");
  set_listen(
      "You hear the sound of a gentle breeze.\n");
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/vorax/west16", "west",
      "/d/coronos/w/darkness/wallst1", "east",
      }));
}

void init() {
  ::init();
  add_action("enter", "enter");
}

status enter(string str) {
  if(!str) {
    notify_fail("Enter what? ..the garrison?\n");
    return 0;
  }

  if(str == "garrison" ||
     str == "doors"    ||
     str == "doorway")  {

    write("You enter the barracks of the 12th garrison...\n\n");
    this_player()->move_player("into the barracks of the 12th garrison"+
          "#d/coronos/w/angel/city/barracks/stairs");
    return 1;
  }
  notify_fail("Enter what? ..the garrison?\n");
  return 0;
}


