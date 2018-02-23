#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
   if(!present("bird")) {
   move_object(clone_object("d/coronos/w/russkie/npc/bird"),this_object());
}
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long("\
The sound of people walking can be heard along this busy road.\n");
  set_day_desc("\
Birds fly gracefylly above this cobblestone street. A large wall\n\
has been built next to the street, and is covered in thick vines\n\
of lavendar. The sun above shines brightly on the stones in the\n\
making it quite warm. The road continues to the east here, as well\n\
as to the southeast.\n");
  set_night_desc("\
Bright stars shine like diamonds in the sky, and the moon shines\n\
full. A stone wall is hard to make out in the darkness, though a \n\
large lamp post stands lit on a corner, lighting the area with a \n\
soft glow. The road continues to the east here, and also to the \n\
southeast.\n");
  set_day_items(({
"birds",
"Many seagulls fly overhead, hovering above you...better run for cover!\n",
"street#stones",
"This street is made up of large yellowish stones.\n",
"wall#lavendar#vines",
"The tall wall near the street is covered in fragrant vines of lavendar.\n",
"sun#road",
"The sun beats down on the road, creating warmth.\n",
}));
  set_night_items(({
"stars#sky",
"The sky is a dark shade of midnight blue. Stars shine brightly there.\n",
"street#stones#road",
"The street seems to be made of dark stones, though harder to see in the\n\
night.\n",
"wall#vines",
"The wall seems to be covered in vines.\n",
"moon",
"The moon emits a romantic glow on the area.\n",
"lamp post#lamp#light#post",
"The lamp illuminates the area in a soft glow.\n",
}));
  set_exits(({
 "/d/coronos/w/vorax/street3.c", "northwest",
 "/d/coronos/w/russkie/rooms/2", "east",
 "/d/coronos/w/russkie/rooms/15", "southeast",
}));
  set_weather(2, 6, 0);
}
