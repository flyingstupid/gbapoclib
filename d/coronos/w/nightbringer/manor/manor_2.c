/*   AUTHOR:NIGHTBRINGER
   04-23-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
reset_doors(arg);
 if(arg) return;

  load_door(({
    "destination", "d/coronos/w/nightbringer/manor/manor_3.c",
    "direction", "south door",
    "description", "A plain wooden door .\n",
    "closed",
    "door number", 1,
  }));

  set_short("Cloakroom");
  set_long(
"This small room is used to store the outside garments of the houses\n"+
"occupants. It is extremely small and constricting in size, and is\n"+
"poorly lit. It is devoid of any decorations, as it is only meant to\n"+
"be used as a place to hang cloaks and coats in.\n");


  set_items(({
"wall#walls#floor",
"It is made of wood.\n",
"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",
"coat#coats#cloak#cloaks#outer garment#garment#garments",
"Eleven wool cloaks are hanging in here.\n",
           }));

set_listen("You can hear soft, scraping coming from the\n"+
"south.\n");

  set_smell("It smells kinda musty in here.\n");

set_weather(1,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_1.c", "northwest",
           }));
}

