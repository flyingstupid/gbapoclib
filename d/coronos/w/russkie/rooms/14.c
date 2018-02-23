#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
   if(!present("bird")) {
   move_object(clone_object("d/coronos/w/russkie/npc/bird"),this_object());
}
 
   if(arg) return;
  set_short("a cobblestone street");
  set_long ("\n");
  set_day_desc("\
A seagull glides just above the cobblestone street. A large wall\n\
has been built next to the street, and is covered in thick vines\n\
of lavendar. The sun above shines brightly on the stones warming\n\
the road. The road splits here, leading west and southwest.  The\n\
docks of Ille Coronos lie off to the northeast.\n");
  set_night_desc("\
Hundreds of bright stars shine like diamonds, and the moon glows\n\
full and prominent next the the black backdrop of the night sky.\n\
A stone wall that is hard to make out in the dark, stands near the\n\
road. A large lamp post stands lit on a corner, lighting the area\n\
with a soft glow. The road splits here, leading west and southwest.\n\
The docks of Ille Coronos lie off to the northeast.\n");
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
"pier",
"Far to the southwest is a huge pier.\n",
"street#stones#road",
"The street seems to be made of dark stones, though harder to see in the\n\
night.\n",
"wall#vines",
"The wall seems to be covered in vines.\n",
"lamp post#lamp#light#post",
"The lamp illuminates the area in a soft glow.\n",
}));
  set_exits(({
"/d/coronos/w/russkie/rooms/13", "west",
"/d/coronos/w/russkie/rooms/16", "southwest",
"/d/coronos/w/alena/ille/c_7", "northeast",
}));
  set_weather(2, 6, 0);
}
