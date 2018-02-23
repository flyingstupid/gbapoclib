#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long("\
A beautiful view of the sea makes this a ver peacefull and\n\
relaxing road.  ");  
  set_day_desc("\
The sun beams down on this quiet cobblestone\n\
street. Birds peck the ground for food, and a slight salty \n\
breeze blows through the air. A railing to the west shows a\n\
view to a beach below, as well as the sea. The road leads off\n\
to the northwest from here.\n");
  set_night_desc("\
A cool night breeze blows softly through the \n\
street. Iron lamps offer a soft glow to the area, glinting off\n\
of the stones in the road. A bird screeches by now and then, \n\
but other than that all is very quiet here. The road leads off\n\
to the northwest from here.\n");
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
"/d/coronos/w/russkie/rooms/23", "northwest",
"/d/coronos/w/russkie/rooms/27", "southeast",
}));
  set_weather(2, 6, 0);
}
 
