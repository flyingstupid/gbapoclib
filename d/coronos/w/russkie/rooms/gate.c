#include <mudlib.h>
inherit ROOM;

  void reset(status arg) {

    reset_doors(0);
    load_door(({
"destination", "d/coronos/w/alena/ille/t_5",
        "direction",   "north gate",
        "closed",
"long",
        "The gate bridges the gap in the wall to the north, made of \n"+
        "beautifully crafted wrought iron.\n",
      }));

  if(arg) return;
    set_short("a large gate");
set_long(
"Huge stone gates stand to the north, bridging the gap between the \n"+
"wall. Between the bars a large temple rises up behind trees and \n"+
"bush on the other side of the wall. On the south side of the gate \n"+
"however, the long road travels along the wall to the east and west.\n");
 set_night_desc("\
The gates cast shadows upon the path.\n");
  set_day_items(({
"gates#stone#birds",
"Large gates loom to the north. Many birds sit on top of it.\n",
"sun#clouds#sky",
"The sky is filled with soft white clouds, and a bright sun.\n",
"street#road#stones",
"The street is made up of beige cobblestones.\n",
}));
  set_night_items(({
"gates",
"The gates look dark and ominous in the night.\n",
"moon#sky#stars",
"The moon shines brightly in the sky, accompanied by many stars.\n",
"lamps#light#glow",
"These tall black lamps create a soft glow on the street.\n",
"road",
"The road continues east and west here, lit by the lamps.\n",
}));
  set_exits(({
"/d/coronos/w/russkie/rooms/7", "west",
"/d/coronos/w/russkie/rooms/8", "east",
}));
  set_weather(2, 6, 0);
}
