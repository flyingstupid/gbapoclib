#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long("\n");
  set_day_desc("\
Birds fly overhead, above the cobblestone street. A large wall\n\
has been built next to the street, and is covered in thick vines.\n\
The sun above shines brightly on the stones in the road, causing\n\
it to be quite warm. The road continues to the east.\n");
  set_night_desc("\
Stars shine like diamonds in the sky, and the moon shines full. In\n\
the shadows along the road, a stone wall stands, covered in vines.\n\
A large lamp post stands lit on a corner, lighting the area with a\n\
soft glow. The road continues to the east here, looking quite long.\n");
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
"lamp post#lamp#light#post",
"The lamp illuminates the area in a soft glow.\n",
}));
  set_exits(({
"/d/coronos/w/russkie/rooms/5", "west",
"/d/coronos/w/russkie/rooms/7", "east",
}));
  set_weather(2, 6, 0);
}
