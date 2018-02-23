#include <mudlib.h>
#include <ansi.h>
#include "path.h"

inherit "inherit/room2";

void reset(status arg) {
  if(arg) return;

  set_short("Dock One");
  set_long(YELLOW_F+"\t--<Dock One>--\n"+OFF+
"This is where the riverboats come in to deliver and pickup their cargo.\n"+
"There are several river boats in port right now, and a couple in the center\n"+
"of the river at anchor awaiting thier turn to dock.  There are crates stacked\n"+
"on wagons that will be pulled to the warehouses for storage until the porper\n"+
"taxes can be charged on them, then they will be delivered to their recipient.\n"+
"Dock workers bustle from place to place, some with crates on their backs others\n"+
"busily unloading ships.\n");
  set_weather(5, 4, 6);
  set_items(({"boats##river boats##riverboats",
"There are large ones and small ones, all are shallow hulled and suitable only\n"+
"for river travel.  Although, some do travel the river until it empties out\n"+
"into the ocean then they hug the coast until thier next destination.\n",
    "cargo",
    "Goods to be sold in the markets of the realms city.\n",
    "wagons",
    "These are used to transport the cargo to and from the warehouses or to the purchaser of\n"+
    "the cargo if it is someone within the city.\n",
    "crates",
"Who knows what is inside, could be plates, swords spices or any number of\n"+
    "goods.\n",
    "workers##dock workers",
    "Without these men and women, this city would be in a world of hurt.\n",
    "dock",
    "You're standing on it silly.\n"
  }));
  set_exits(({
    ROOMS "ds01.c", "north",
  }));
}
