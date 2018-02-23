#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
  if(!present("sailor")) {
  move_object(clone_object("/d/coronos/w/russkie/npc/sailor"),this_object());
   }
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long(
"This wide stone road offers a peacefull and relaxing view.\n");
  set_day_desc(
"The sun beams down on the cobblestone street, as well as\n"+
"glinting off the waves in the vast sea to the west.  Gulls\n"+
"peck the ground for food, and a slight salty breeze blows\n"+
"through the air. A railing to the west shows a view to a\n"+
"beach below, as well as the sea. The road continues to the\n"+
"southeast and the northwest from here.\n");
  set_night_desc(
"A cool night breeze blows softly through the street. Many iron\n"+
"lamps offer a soft glow to the area, glinting off of the stones\n"+ 
"in the road. A bird screeches by now and then, but other than \n"+
"that all is very quiet here. The road continues to the southeast\n"+
"and northwest here.\n");
  set_day_items(({
"birds",
"Many seagulls fly overhead, hovering above you...better run for cover!\n",
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
"street#stones#road",
"The street seems to be made of dark stones, though harder to see in the\n\
night.\n",
"lamp post#lamp#light#post",
"The lamp illuminates the area in a soft glow.\n",
"lamps",
"Tall, black iron lamps shine brightly in the night.\n",
}));
  set_exits(({
"/d/coronos/w/russkie/rooms/17", "northwest",
"/d/coronos/w/russkie/rooms/21", "southeast",
}));
  set_weather(2, 6, 0);
}
