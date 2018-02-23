#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
   if (!present("elemental")) {
        move_object(clone_object(CASTLE_MONSTERS+"light"), this_object());
        move_object(clone_object(CASTLE_MONSTERS+"light"), this_object());
        move_object(clone_object(CASTLE_MONSTERS+"light"), this_object());
 }      
 
  if(!arg) {
      set_short("The Inner Sanctum");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You have come to a dead end. There is nothing here except for a spiraling\n"+
"staircase which hasn't been completed yet. You have found the source of\n"+
"bright light however. Three evil Light Elementals stand here guarding\n"+
"access to the upper levels of the castle even though you cannot get there\n"+
"yet due to the incomplete staircase.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
        CASTLE_ROOMS+"in6",  "north",
      }));
      set_weather(2,2,0);
      set_items(({
        "staircase#stairs", "The spiraling staircase was to provide access "+
                            "to the upper levels\n"+
                            "of the castle. However, it has not yet been "+
                            "completed. Maybe if you came back\n"+
                            "some day in the near future it will be ready",
      }));
  }
}
