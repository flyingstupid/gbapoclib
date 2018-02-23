#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
   if (!present("elite guard")) {
       move_object(clone_object(CASTLE_MONSTERS+"elite"),this_object());
       move_object(clone_object(CASTLE_MONSTERS+"elite"),this_object());
 }      
 
  if(!arg) {
      set_short("Inner Circle of the Castle");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You have come to the northeast corner of the inner circle. The blinding\n"+
"light is very strong here. The intensity seems to be much stronger. It\n"+
"seems to have originated west of here.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
    CASTLE_ROOMS+"in3",  "west",
    CASTLE_ROOMS+"in5",  "south",
      }));
      set_weather(2,2,0);
  }
}

