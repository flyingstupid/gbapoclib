#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  if(arg) return;

  load_door(({
	"direction", "south door",
	"file", "d/sorcery/w/angel/hall4",
	"long",
	"Two ornate doors of translucent blue glass steel",
  }));

  set_short("the isle of sorcery");
  set_long(
"The basalt road rolls out infront of the majestic halls of the \n"+
"Council building and then back to form a loop. In the middle   \n"+
"is a small fountain around which sits a flower bed of simple   \n"+
"white roses. ");

  set_day_desc(
              "With the sunlight pouring into the front foyer of\n"+
"magical glass, the whole place is bathed in reds and blues.    \n");

  set_night_desc(
	      "The stars shine their light on the glass foyer    \n"+
"which is reflected back onto the water of the fountain.         \n");

  set_items(({
"roses#rose bed#flowers#flower bed",
"A bed of roses. Some claim this is the oldest rose garden in "+
"all of Magia",

"light#stars#sun light#star light",
"The way the light reflects off the glass and into the court \n"+
"yard is truly breathtaking",

"fountain", 
"It looks very simple, and very beautiful. A single nerid, like \n"+
"a living wave, spirals from its middle. It is a lovely statue.\n",

"water",
"It looks and smells like a cool mountain spring",

"foyer#glass foyer",
"The reflections of light passing through it bathe the whole area\n"+
"in an effect that is truly breathtaking. The architect of this  \n"+
"feat was a true genius.\n",
  }));

  set_weather(2, 1, 0);
  set_exits(({
	"d/sorcery/w/angel/path5", "north",
  }));
}








