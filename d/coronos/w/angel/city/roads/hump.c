#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("an old humpbacked bridge");

  set_long(
"A small stream runs underneath this old humpbacked bridge that leads\n"+
"further into the farming lands, north of Ille Coronos. A small chapel\n"+
"stands on a hill to the north east. ");

  set_day_desc(                                           "A few tall"+
" lanterns are set into\nthe sides of the bridge, waiting til evening"+
"when they will be lit.\n");

  set_night_desc(                                           "A few tall"+
" lanterns are set into\nthe sides of the bridge, lighting the way to "+
"the city of Ille Coronos,\n far to the south.\n");


  set_weather(3,0,0);
  set_exits(({
	PATH+"road3",  "east",
	PATH+"wild1", "west",
  }));


  set_items(({
	"sandstone",
	"A strong yellowish block of stone. It's a little mossy",

	"bridge",
	"The bridge is made from sandstone, built from stones \n"+
	"crafted at a nearby quarry. You can see the stream running\n"+
	"far below",

	"stream",
	"The stream looks like fresh water, probably running from the \n"+
	"icy peaks of Darken Mountain. You catch a glimpse of something\n"+
	"underneath the bridge, drinking from the water. Perhaps you \n"+
	"should go down and investigate? ... it's a long way down,\n"+
	"however, and you wouldn't want to hurt yourself if you fall!",

	"farms#grazing land#land#farm",
	"The farms around these parts seem to be growing corn. A magpie\n"+
	"is seated atop a scarecrow watching you",

	"magpie",
	"A crow-sized bird with black and white markings. Its call seems\n"+
	"to mimick several birds you've heard before",

	"corn",
	"It looks ripe and golden yellow, peaking out from its green \n"+
	"jacket. If it weren't against the law, you'd certainly be   \n"+
	"tempted to pick some",

	"chapel",
	"A small chapel stands on a hill to the north east",

	"lanterns#lantern",
	"They stand nearly 10 feet tall and are made from iron.",

	"road#pavement",
	"The road is made from pebbles and rocks, fused together with\n"+
	"a grey mortar. It looks well travelled",

	"darken mountain#mountain",
	"Darken Mountain is said to be the home of the drow",

	"cloud#clouds", "They are fluffy clouds. One looks like a dog\n",
 }));


  set_smell("The air smells fresh and clean.\n");
  set_listen("You hear a stream of fresh water.\n");
} 

void init() {
  ::init();
  add_action("down", "down");
  add_action("down", "d");
  add_action("down", "climb");
}

status down(string str) {
  if(query_verb() == "climb") {
    if(!str) {
      notify_fail("Climb down where?\n");
      return 0;
    }
  }

  write("You climb down to the stream below the bridge\n");
  this_player()->move_player("down toward the stream#"+PATH+"stream");
  return 1;
}

