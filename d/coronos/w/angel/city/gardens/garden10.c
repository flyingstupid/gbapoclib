#include <mudlib.h>
#define PATH "d/coronos/w/angel/city/gardens/"
#define MONST "d/coronos/w/angel/city/monst/"
inherit ROOM;

void reset(status arg) {
    object obj;
    if(!present("wombat")) {
	obj = clone_object(MONST+"wombat");
	move_object(obj,this_object());
    }
    if(arg) return;
    set_weather(1,3,0);
    set_short("the city garden");
    set_long(
      "Continuing through the garden the ground becomes a bit more \n"+
      "arid and the green grass seems to become much more sparse. \n"+
      "Within the dry patch of ground is a start of a burrow. A \n"+
      "large rock sets off to one side. Footprints lay within the \n"+
      "sandy soil.\n");
    set_day_desc(
      "The sun shines down, an occasional cloud making the only shade.\n");
    set_night_desc("The moon shines down from high above.\n");
    set_listen("A soft scraping is heard from around you.\n");
    set_smell("As you sniff the air you get a bit of dry sand "+
      "in your nose.\n");

    set_items(({
	"grass#green grass",
	"The blades of grass have beomce fewer and far between",
	"rock#large rock",
	"A good sized rock which sits beside the hole",
	"sandy soil#soil#sand",
	"Simple sandy soil, however, it contains many footprints",
	"footprint#footprints",
	"They appear to be prints made from a wombat",
      }));
    set_exits(({
	PATH+"garden5","northwest",
	PATH+"garden6","north",
	PATH+"garden11","east",
      }));
    set_weather(1,4,0);
}
