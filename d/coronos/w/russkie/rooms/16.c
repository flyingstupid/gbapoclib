#include <ansi.h>
#include <mudlib.h>
inherit ROOM;

  void reset(status arg) {

   if(arg) return;
  set_short("a cobblestone street");
  set_long("\
It is very quiet walking along this cliffside road of stones.\n");
  set_day_desc("\
Sweet, salty breezes blow here. The sun beams down onto the stones\n\
in the road, creating great warmth. The sea breezes come from the\n\
east, where a railing keeps travelers safe from falls. The hard\n\
cobblestone street continues to the southwest.\n");
  set_night_desc("\
A chilly night breeze is blowing across this wide cobblestone\n\
street. The area is well lit by black iron lamps, as well as\n\
a bright moon and stars hanging in the midnight blue sky. More\n\
of the road can be seen to the southwest and northeast from here.\n");
  set_day_items(({
"birds",
"Many seagulls fly overhead, hovering above you...better run for cover!\n",
"street#stones",
"This street is made up of large yellowish stones.\n",
"sun#road",
"The sun beats down on the road, creating warmth.\n",
"railing",
"A sturdy metal railing keeps visitors from tumbling into the sea.\n",
}));
  set_night_items(({
"stars#sky",
"The sky is a dark shade of midnight blue. Stars shine brightly there.\n",
"moon",
"The moon is full and bright.\n",
"street#stones#road",
"The street seems to be made of dark stones, though harder to see in the\n\
night.\n",
"lamp post#lamp#light#post",
"The lamp illuminates the area in a soft glow.\n",
"glow#lamps",
"The black iron lamps cast a dim glow across the misty night air.\n",
}));
  set_exits(({
"/d/coronos/w/russkie/rooms/14", "northeast",
"/d/coronos/w/russkie/rooms/18", "southwest",
}));
  set_weather(2, 6, 0);
}
