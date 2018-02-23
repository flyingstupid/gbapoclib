#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    reset_doors(0);
    load_door(({
	"destination",     "d/coronos/w/angel/city/gardens/garden11",
	"direction",       "north gate",
	"closed",
	"description",
	"The gate is a beautifully crafted wrought iron gate.\n",
      }));


    if (arg) return;

    set_short("just south of the gardens");
    set_long(
      "A huge gate stands before you, standing between you and a lovely \n"+
      "garden here in the center of Ille Coronos. The cobblestones beneath \n"+
      "your feet seemingly disappear as the path disappears into the garden \n"+
      "to the north. Bushes line the edges of the pathway.");
    set_day_desc(
      " A pair \n"+
      "of unlit lamps hang from hooks on the gate.\n");
    set_night_desc(
      " A pair of \n"+
      "lamps hang from the hooks on the gate. They shine brightly.\n");
    set_items(({
	"cobblestones#cobblestone",
	"These grey cobblestones have been smoothed and worn over time.\n",
	"road",
	"The road is paved with many cobblestones.\n",
	"shrub#shrubs",
	"A few shrubs grow along the road, on the side opposite the wall.\n",
	"gate",
	"The gate stands to the north and is between you and the gardens to \n"+
	"the north.\n",
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
	"/d/coronos/w/alena/ille/m_1","south",
      }));
}
