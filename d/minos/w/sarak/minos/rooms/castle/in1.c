#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
   if (!present("guard")) {
       move_object(clone_object(CASTLE_MONSTERS+"elite"),this_object());
       move_object(clone_object(CASTLE_MONSTERS+"elite"),this_object());
 }      
 
  if(!arg) {
      set_short("Inner Circle of the Castle");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You have entered the inner circle of Minotaur Castle. This area of the\n"+
"castle is totally devoid of any treasures, yet it is still guarded. There\n"+
"is no gold in this room at all. What could be so important to be guarded\n"+
"as heavily as this?\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
        CASTLE_ROOMS+"in2",  "north",
        CASTLE_ROOMS+"entrance",  "southeast",
      }));
      set_weather(2,2,0);
  }
}

