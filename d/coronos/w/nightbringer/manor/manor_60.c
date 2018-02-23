/* MANOR_60.c
   AUTHOR:NIGHTBRINGER
   04-28-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {

  if(!present("banshee")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/banshee.c"),this_object());
       }
  if(arg) return;

  set_short("Under The Penor's Manor");
  set_long(
"You have encountered the source of the evil wailings coming from the\n"+
"underground passageways. This is the lair of an unspeakable creature\n"+
"of complete evil. The rotted remains of several unidentifiable creatures\n"+
"lay scattered across the room.\n");


  set_items(({
"wall#walls#floor",
"It is made of made of earth\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"remanins#rotted remains#creatures#creature",
"The disgusting rotting corpses of unknown creatures",

           }));


  set_smell("It smells damp and musty in here.\n");
  set_listen("Erie sounds seem to assail your ears from all directions.\n");

  set_weather(0,4,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_59.c", "north",

           }));
}

