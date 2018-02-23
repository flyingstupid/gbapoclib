#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
  set_short("University Street");
  set_long(
    "This road is paved with smooth, grey bricks.  The grass and bushes\n"+
    "that line the street are neatly trimmed and well kept.  The arch of\n"+
    "the University can be seen towards the north from here.  A lamp post\n"+
    "stands on the west side of the road.");
  set_day_desc(
    "  To the south is the commercial\n"+
    "sector of the city.\n");
  set_night_desc(
    "  The lamp post burns brightly,\n"+
    "illuminating University Street.  To the south is the commercial\n"+
    "sector of the city.\n");
  set_items(({
    "road",
    "This is University Street.  It is paved with grey bricks.\n",
    "bricks#brick#grey bricks",
    "These are smooth grey bricks that pave the road.\n",
    "bush#bushes",
    "These bushes are well trimmed and in healthy condition.\n",
    "grass",
    "The grass is green and healthy.\n",
    "arch",
    "The arch of the University rises to the north.\n",
    "leaves",
    "These are healthy, green leaves of the bushes.\n",
    "university",
    "The university of Ille Coronos rises high into the sky.\n",
    }));
  set_day_items(({
    "lamp post#lamp#post",
    "This lamp post is made from iron, and is engraved with intricate\n"+
    "designs.  It has a cylindrical top that house the oil and wick.\n"+
    "It is currently unlit.\n", 
    }));  
  set_night_items(({
    "lamp post#lamp#post",
    "This lamp post is made from iron, and is engraved with intricate\n"+
    "designs.  It has a cylindrical top that house the oil and wick.\n"+
    "It burns brightly, illuminating the road.\n",
    }));
  set_smell(
     "You smell nothing but fresh air.\n");
  set_listen(
      "You hear the rustling leaves as a breeze blows by.\n");
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/darkness/univst3", "north",
"/d/coronos/w/alena/ille/c_3","south",
      "/d/coronos/w/darkness/univst5", "west",
      }));
}
