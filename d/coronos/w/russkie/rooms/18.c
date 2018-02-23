#include <ansi.h>
#include <mudlib.h>
inherit ROOM;

  void reset(status arg) {
  if(!present("drunk")) {
  move_object(clone_object("/d/coronos/w/russkie/npc/drunk"),this_object());
}

   if(arg) return;
  set_short("a cobblestone street");
  set_long("\
The air here is filled with the scent of beer mixed with the sea.\n");
  set_day_desc("\
Sweet, salty breezes blow here. The sun beams down onto the stones\n\
in the road, creating great warmth. The sea breezes come from the\n\
east, where a railing keeps travelers safe from falls. The hard\n\
cobblestone street continues to the southwest, and a large building\n\
lies to the west. There is a sign in front of the building.\n");
  set_night_desc("\
A chilly night breeze is blowing across this wide cobblestone\n\
street. The area is well lit by black iron lamps, as well as\n\
a bright moon and stars hanging in the midnight blue sky. More\n\
of the road can be seen to the southwest and northeast from here,\n\
and a railing of iron guards a cliff to the east. Loud talking\n\
can be heard in a brightly lit building to the west. A sign\n\
stands outside the business.\n");
  set_day_items(({
"birds",
"Many seagulls fly overhead, hovering above you...better run for cover!\n",
"sign",
"\
-=-=^^=-=-=-^^=-=-\n\
-=     Skyes    =-\n\
-=  Tavern and  =-\n\
-=     ~Inn~    =-\n\
-=-=-=-=-=-=-==-=-\n\
\n",
"street#stones",
"This street is made up of large yellowish stones.\n",
"building",
"A large business of some sort stands to the west.\n",
"sun#road",
"The sun beats down on the road, creating warmth.\n",
"railing",
"A sturdy metal railing keeps visitors from tumbling into the sea.\n",
}));
  set_night_items(({
"stars#sky",
"The sky is a dark shade of midnight blue. Stars shine brightly there.\n",
"sign",
"\
It's a bit hard to read in the dark, but you can see that the building\n\
houses a tavern, and several other rooms.\n",
"railing",
"The area around the railing is well lit for safety.\n",
"building#business",
"A well lit building lies to the west.\n",
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
"/d/coronos/w/russkie/rooms/16", "northeast",
"/d/coronos/w/russkie/rooms/20", "southwest",
"/d/coronos/w/russkie/rooms/tavern", "west",
}));
  set_weather(2, 6, 0);
}
  void init() {
  add_action("read", "read");
   ::init();
}
  status read(string str) {
   string tmp;
  if(str == "sign") {
  write("A shimmery blue glass sign reads:\n\
-=-=^^=-=-=-^^=-=-\n\
-=     Skyes    =-\n\
-=  Tavern and  =-\n\
-=     ~Inn~    =-\n\
-=-=-=-=-=-=-==-=-\n\
\n");
}
  return 1;
}
