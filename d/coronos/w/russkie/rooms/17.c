#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
  if(!present("bird")) {
  move_object(clone_object("/d/coronos/w/russkie/npc/bird"),this_object());
}
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long("\n");
  set_day_desc("\
The sun beams down on this long cobblestone street. Gulls\n\
peck the ground for food, and a breeze blows through the \n\
air. A railing to the west shows a view to a beach below,\n\
as well as the sea. The road continues to the southeast at\n\
this point, and a small house lies to the west.\n");
  set_night_desc("\
A cool night breeze blows softly through the street. Many iron\n\
lamps illuminate the area, glinting off of the stones in the\n\
road. A bird screeches by now and then, but other than that all\n\
is very quiet here. The road continues to the southeast here,\n\
and a small house lies to the west of the street.\n");
  set_day_items(({
"birds",
"Many seagulls fly overhead, hovering above you...better run for cover!\n",
"house",
"A small blue house lies to the west.\n",
"railing#beach#sea",
"From the edge of the railing you can see a beach and the rough ocean.\n",
"street#stones",
"This street is made up of large yellowish stones.\n",
"sun#road",
"The sun beats down on the road, creating warmth.\n",
}));
  set_night_items(({
"stars#sky",
"The sky is a dark shade of midnight blue. Stars shine brightly there.\n",
"A small blue house lies to the west, well lit in the darkness.\n",
"street#stones#road",
"The street seems to be made of dark stones, though harder to see in the\n\
night.\n",
"lamp post#lamp#light#post",
"The lamp illuminates the area in a soft glow.\n",
"lamps",
"Tall, black iron lamps shine brightly in the night.\n",
}));
  set_exits(({
"/d/coronos/w/russkie/rooms/15", "northwest",
"/d/coronos/w/russkie/rooms/19", "southeast",
"/d/coronos/w/russkie/rooms/h1", "west",
}));
  set_weather(2, 6, 0);
}
 
