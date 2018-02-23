#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long ("\n");
  set_day_desc("\
A large wall has been built along this cobblestone street.  It \n\
covered in thick vines of lavendar. The sun shines relentlessly \n\
on the stones in the road, causing it to get quite warm. The long\n\
road continues along to the East and West.\n"); 
  set_night_desc("\
The night sky is full of bright stars and a moon full and bright.\n\
A stone wall stands along the moonlit road, also illuminated by\n\
a large lamp post that stands lit on a corner.  The road runs along\n\
East and West from here.\n");
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
"/d/coronos/w/russkie/rooms/10", "west",
"/d/coronos/w/russkie/rooms/12", "east",
}));
  set_weather(2, 6, 0);
}
