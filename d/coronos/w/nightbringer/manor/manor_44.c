/* MANOR_44.C
   AUTHOR:NIGHTBRINGER
   04-27-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);

  load_door(({
     "file", "d/coronos/w/nightbringer/manor/manor_45.c",
     "direction", "east door",
     "long",
          "A plain wooden door.\n",
     "open",
  }));

  if(!present("sally")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/sally.c"),this_object());
       }
  if(arg) return;

  set_short("Nursery");
  set_long(
"The nursery is a baby's paradise. A soft looking baby bed dominates\n"+
"the center of the room. The walls have been painted by a master\n"+
"artisian in happy little scenes. The floor is covered with a soft\n"+
"carpet to keep a little one from getting hurt while at play. Baby toys\n"+
"lay scattered throughout the room.\n");

  set_items(({
"wall#walls",
"A master artisian has painted the walls to resemble clowns, ponies and\n"+
"other sweat childish things.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"The floor is covered with a very thick, soft blue carpet. It appears.\n"+
"to be thick enough to keep a baby from getting hurt, should they fall.\n",

"bed#baby bed",
"A pink babies crib that is made from soft wood. There is a soft looking\n"+
"baby blanket and several stuffed toys and dolls in it.\n",

"toy#toys#baby toy#baby toys",
"A bunch of toys suited for a baby to place with lay all over the floor.\n",

"blanket#baby blanket",
"It is soft and pink.\n",

"stuffed toy#stuffed toys",
"Several stuffed teddy bears and rabbits are in the baby bed.\n",

"doll#dolls",
"A couple of sweat looking baby dolls are in the baby bed.\n",

"carpet#soft carpet",
"A thick, soft, blue carpet covers the floor.\n",

"clown#clowns#pony#ponies#sweat childish things#sweat childish thing",
"Someone has painted them on the walls here.\n",
           }));


  set_weather(2,2,0);

}

