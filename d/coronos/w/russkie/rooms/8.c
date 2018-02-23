#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long ("\n");
  set_day_desc("\
A large wall has been built next to this cobblestone street. The\n\
wall is covered in thick vines of lavendar, and stands tall and\n\
strong. The sun above shines brightly on the stones in the road,\n\
causing it to be quite warm. The road continues to the east here,\n\
looking quite long.\n");
  set_night_desc("\
The moon shines full this night, with bright stars filling the \n\
night sky.  A stone wall stands near the road. A large lamp post\n\
stands lit on a corner, lighting the area with a soft glow. The \n\
road continues to the east here, looking quite long.\n");
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
"/d/coronos/w/russkie/rooms/gate", "west",
"/d/coronos/w/russkie/rooms/9", "east",
}));
  set_weather(2, 6, 0);
}
