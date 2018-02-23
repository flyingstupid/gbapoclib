/* dormpath.c */
/* Darkness   */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/nightbringer/college/room1",
     "direction", "dorm door",
     "long",
          "A ornately carved wooden door.\n",
     "closed",
     "door number", 1,
   }));
 

  if (arg) return;
 
  set_short("a short path");
  set_long(
    "The path is paved with smooth, grey bricks, just like those on University\n"+
    "Street.  The path leads to the University Dormitory that stand to the east\n"+
    "of the actual University complex.  Several young trees line the sides of the\n"+
    "path, and the grass and bushes that line the path are neatly trimmed.  A pair\n"+
    "of lamp posts stand on either side of the path.");
  set_day_desc(
    "\n");
  set_night_desc(
    "  The pair of lamp posts burn\n"+
    "brightly, illuminating University Street.\n");
  set_items(({
    "dormitory#dorm",
    "The dormitory is an old three storie building.  The third floor looks dark\n"+
    "and drearie as if it had once been through a fire and was never restored.\n",
    "path",
    "This is the path that leads to the University dormitory.\n",
    "road",
    "The road is paved with grey bricks.\n",
    "bricks#brick#grey bricks",
    "These are smooth grey bricks that pave the road.\n",
    "bush#bushes",
    "These bushes are well trimmed and in healthy condition.\n",
    "grass",
    "The grass is green and healthy.\n",
    "tree#trees",
    "These are young saplings that have recently been planted.\n",
    "bench#benches#wooden benches",
    "These wooden benches look brand new.  They are made from wood, and\n"+
    "held together with an iron frame.",
    "leaves",
    "These are the leaves of the trees and bushes. \n",
    }));
  set_day_items(({
    "lamp post#lamp posts",
    "This pair of lamp posts are made from iron, and are engraved with\n"+
    "intricate designs.  They have cylindrical tops that house the oil\n"+
    "and wick.  They are currently unlit.\n", 
    }));  
  set_night_items(({
    "lamp post#lamp posts",
    "This pair of lamp posts are made from iron, and are engraved with\n"+
    "intricate designs.  They have cylindrical tops that house the oil\n"+
    "and wick.  They burn brightly, illuminating the road.\n",
    }));
  set_smell(
     "You smell nothing but fresh air.\n");
  set_listen(
      "You hear the rustling leaves as a breeze blows by.\n");
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/darkness/univst2", "south",
      }));
}
