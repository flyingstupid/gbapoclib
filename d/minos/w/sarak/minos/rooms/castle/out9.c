#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
  if (!present("corpse")) 
    move_object(clone_object(CASTLE_ITEMS+"corpse"), this_object());
  if (!present("vampire"))
    move_object(clone_object(CASTLE_MONSTERS+"vampire"), this_object());
 
  if(!arg) {
      set_short("Northeast Corner of the Castle");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"As you enter this dark room, you are greeted with the gruesome sight of\n"+
"the blood stained walls. The thick, red liquid is literally everywhere. It\n"+
"drips from the walls, the roof and the pool on the ground is deep enough\n"+
"to fully cover your feet. You're stomach churns as a large drop of the\n"+
"the viscous fluid falls from the ceiling onto your head.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
        CASTLE_ROOMS+"out8",  "west",
        CASTLE_ROOMS+"out10",  "south",
      }));
      set_weather(2,2,0);
      set_items (({
        "blood", "The thick red blood is everywhere! It has a strange smell",
      }));
      set_smell("The vile stench of the rotting blood is just too much for\n"+
        "your stomach. You add to the chaos here by throwing up everywhere!\n");
  }
}

