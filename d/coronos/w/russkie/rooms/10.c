#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long ("\n");
  set_day_desc("\
A flock of gulls fly overhead, high above the cobblestone street.\n\
A large wall has been built next to the street, which is covered \n\
in thick vines of lavendar. The sun above shines brightly on the \n\
stones in the road, making it warm underfoot. The road continues \n\
to the east here, looking quite long.\n");
  set_night_desc("\
Many bright stars shine like sparkling diamonds in night the sky.\n\
The moon glows full, lighting the night sky with its aura. A stone\n\
wall that is hard to make out in the dark, stands near the road. A\n\
large lamp post stands lit on a corner, lighting the area with a soft\n\
glow. The road continues to the east here, looking quite long.\n");
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
"/d/coronos/w/russkie/rooms/9", "west",
"/d/coronos/w/russkie/rooms/11", "east",
}));
  set_weather(2, 6, 0);
}
