#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
  void reset(status arg) {
 
   if(!present("beggar")) {
     move_object(clone_object("d/coronos/w/angel/city/monst/beggar"),
     this_object());
   }

   if(arg) return;
  set_short("a cobblestone street");
  set_long("\
The sound of people walking can be heard as they walk along.\n");
  set_day_desc("\
A few birds fly overhead, above the cobblestone street. A large \n\
wall stands next to the street, and is covered in thick lavendar\n\
vines. The sun above shines brightly on the stones in the road, \n\
making it to quite warm. The road continues to the east.\n");
  set_night_desc("\
Stars shine like diamonds in the sky, and the moon shines full. A \n\
stone wall stands near the road, lit up by a lamp post that stands\n\
on the corner.  The road continues to the east here, looking quite\n\
in the darkness of night.\n");
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
 "/d/coronos/w/russkie/rooms/3", "west",
 "/d/coronos/w/russkie/rooms/5", "east",
}));
  set_weather(2, 6, 0);
}
