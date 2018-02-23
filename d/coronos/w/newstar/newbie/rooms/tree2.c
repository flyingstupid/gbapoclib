/* tree2.c  Newbie Area */
/* Darkness & Newstar */

#include <mudlib.h>
 
inherit ROOM;
 
void reset (status arg){

 if(!present("raven")) {
    int i;
    for(i=0; i<7; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/raven"),this_object());
    } 
 }
 
  if(arg) return;
 
  set_short("atop a tree");
  set_long(
    "In the twisted branches of the gnarled tree, the horizon spans far and\n"+
    "wide.  High above the ground, the view is quite breathtaking and a nice\n"+
    "change from the dim and gloom of the dark forest below.");
  set_day_desc(
    "  Sunlight filters\n"+
    "in through the high branches and leaves.  The forest looks much different\n"+
    "from this vantage point up in the tree tops.  The tangled underbrush of\n"+
    "the forest floor look much smaller and less threatening from this height.\n");
  set_night_desc(
    "Moonlight filters\n"+
    "in through the high branches and leaves.  The forest looks much different\n"+
    "from this vantage point up in the tree tops.  The black of the night envelops\n"+
    "the sullen forest, casting an eerie glow on the forest floor bar below.\n");
  set_items(({
    "ground",
      "The ground is far below these upper branches of the tree.\n",
    "branches",
      "The branches of the old, gnarled tree are thick and twisted.\n",
    "horizon",
      "The horizon spans across far and wide for many miles.\n",
    "forest",
      "The dark forest seems some what less threatening in the high branches\n"+
      "of the tree.\n",
    "underbrush",
      "Many different plants make up the thorny, tangled underbrush that\n"+
      "covers the forest floor far below.\n",
    "forest floor#floor",
      "The forest floor is covered by thick underbrush far below.\n",
      }));
  set_day_items(({
    "sunlight",
      "Rich sunlight floods in through the twisted branches of the tree.\n",
      }));
  set_night_items(({
    "moonlight",
      "Silvery moonlight floods in through the twisted branches of the tree.\n",
      }));
  set_smell( 
      "You smell the rich, deep scent of the damp forest.\n");
  set_listen(
      "You hear the soft rustling of the dark leaves.\n");
  set_weather(1, 4, 0);
  set_climb(2);
  set_fall_dam(random(4));
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/forest4", "down",
      }));
}
