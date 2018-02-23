#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long ("\n");
  set_day_desc("\
Birds fly overhead, high above this cobblestone street. A wall\n\
has been built next to the street, and is covered in thick vines\n\
of lavendar. The sun above shines brightly on the stones in the\n\
road, causing it to be quite warm. The road continues to the east\n\
here, looking quite long.\n");
  set_night_desc("\
Many stars shine like diamonds in the sky, and the full moon \n\
shines brightly. A stone wall that is hard to make out in the \n\
dark, stands near the road. A large lamp post stands lit on a \n\
corner, lighting the area with a soft glow. The road continues \n\
to the east here, looking quite long.\n");
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
"/d/coronos/w/russkie/rooms/11", "west",
"/d/coronos/w/russkie/rooms/13", "east",
}));
  set_weather(2, 6, 0);
}
