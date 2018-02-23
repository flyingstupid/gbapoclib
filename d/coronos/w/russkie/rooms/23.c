#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
  if(!present("bird")) {
  move_object(clone_object("/d/coronos/w/russkie/npc/bird"),this_object());
}
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long("\
A quiet road and beautiful scenery mark this spot well.\n");
  set_day_desc("\
The warm sun shines down on the cobblestone road as birds\n\
peck the ground for food.  A railing to the west shows a \n\
view to a beach below, as well as the sea. The road leads\n\
off to the northwest and southeast.\n");
  set_night_desc("\
Iron lamps offer a soft glow to the area, glinting off of \n\
the stones in the road. A bird screeches by now and then, but\n\
other than that all is very quiet here.  The road leads on to\n\
the northwest and southeast from here.\n");
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
"/d/coronos/w/russkie/rooms/21", "northwest",
"/d/coronos/w/russkie/rooms/25", "southeast",
}));
  set_weather(2, 6, 0);
}
