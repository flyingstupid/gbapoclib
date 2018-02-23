/* ROOM58
   AUTHOR:NIGHTBRINGER
   06-02-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

if(!present("ghost")) {
move_object(clone_object("d/coronos/w/nightbringer/college/npc/ghost"),this_object());
}

  reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/nightbringer/college/room44",
     "direction", "west door",
     "long",
          "A plain wooden door.\n",
     "open",
     "door number", 1,

  }));


  set_short("Dormatory Room");
  set_long(
"The room is small and cramped. It contains the blackened remains of\n"+
"of what used to be bedroom furniture. Everything that remains in the\n"+
"room is blackened and charred. An overpowering sense of death and \n"+
"agony hang about the room.\n");

  set_items(({
"wall#walls",
"They are charred and blackened by smoke and fire.\n",

"ceiling",
"The ceiling is made of stone that is blackened by smoke and fire.\n",

"floor",
"It is made out of hardwood that has been burned by fire.\n",

"remains#bedroom furniture#furniture",
"The burnt remains of bedroom furniture lay falling apart in the room.\n",

           }));


  set_weather(1,2,0);

} 

