/* MANOR_57.c
   AUTHOR:NIGHTBRINGER
   04-28-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  if(!present("wraith")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/wraith.c"),this_object());
       }


  set_short("Under The Penor's Manor");
  set_long(
"The wailing sounds grow louder here, something is definately not\n"+
"right here. A sensation of pure evil hangs in the air like a thick\n"+
"cloud. The air here is very cold, enough so to chill ones bones.\n");


  set_items(({
"wall#walls#floor",
"It is made of made of earth\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

           }));


  set_smell("It smells damp and musty in here.\n");
  set_listen("Erie sounds seem to assail your ears from all directions.\n");

  set_weather(-1,4,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_56.c", "west",
        "d/coronos/w/nightbringer/manor/manor_61.c", "east",
        "d/coronos/w/nightbringer/manor/manor_59.c", "south",
        "d/coronos/w/nightbringer/manor/manor_58.c", "north",
}));
}

