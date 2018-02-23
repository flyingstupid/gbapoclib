#include <mudlib.h>
#define MONST	"d/coronos/w/angel/city/monst/"
inherit ROOM;

void reset (status arg){
    if(!present("guard")){
	move_object(clone_object(MONST+"guard1"),this_object());
    }

    reset_doors(arg);
    load_door(({
"file", "d/coronos/w/russkie/rooms/gate",
	"direction",       "south gate",
"long",
	"The gate bridges the gap in the wall to the south, made of \n"+
	"beautifully crafted wrought iron.\n",
      }));

    if (arg) return;

    set_short("the North Gate");
    set_long(
      "The west, east wall comes together here, bridged by a tall \n"+
      "iron gate. Small bushes and trees line South Temple on the \n"+
      "north side, hidding the temple of Ille Coronos behind their \n"+
      "branches and thick cover of leaves. The brick is that of \n"+
      "red and browns, smoothed over from the boots of many \n"+
      "travelers.");
    set_day_desc(
      " A pair of unlit lamps hang from the gate.\n");
    set_night_desc(
      " A pair of lamps hang from the gate. They \n"+
      "shine brightly, illuminating the large iron gate.\n");
    set_items(({
	"cobblestones#cobblestone",
	"Red and brown cobblestones that have been worn over time.\n",
	"road",
	"The road is paved with many cobblestones.\n",
	"shrub#shrubs",
	"A few shrubs grow along the road, on the side opposite the wall.\n",
	"gate",
	"The gate bridges the gap in the tall wall to the south.\n",
	"trees#small trees#tall trees#tree#bushes#bush",
	"Their branches make it hard to view the temple behind them \n"+
	"to the north.\n",
	"wall",
	"It stretches along the south side of South Temple, rising \n"+
	"high above the pavement and seemingly unscaleable.\n",
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
	"/d/coronos/w/alena/ille/t_4","west",
	"/d/coronos/w/alena/ille/t_6","east",
      }));
}
