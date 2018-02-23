#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
  set_short("University Street");
  set_long(
    "This road is paved with smooth, grey bricks.  The grass and bushes\n"+
    "that line the street are neatly trimmed and well kept.  A few young\n"+
    "trees stand behind a group of wooden benches.  The path that leads\n"+
    "to the University dormitory is to the north.  A pair of lamp posts\n"+
    "stand on either side of the path.");
  set_day_desc(
    "\n");
  set_night_desc(
    "  The pair of lamp posts burn brightly,\n"+
    "illuminating University Street.\n");
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
      "/d/coronos/w/darkness/dormpath", "north",
      "/d/coronos/w/darkness/univst1", "west",
      "/d/coronos/w/darkness/univst3", "south",
      }));
}
