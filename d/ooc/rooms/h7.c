#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object ob;
    if(!present("board")) {
        ob = clone_object(BULLETIN_BOARD);
	ob -> set_long(
	"This board is for discussion on H7 mudlib and related topics.\n");
	ob -> set_save_file("ob_saves/boards/h7");
        move_object(ob, this_object());
    }
  if(arg) return;

  set_short("the "+ MUD_NAME +" creativity room");
  set_long(
	" [ OOC ] "+ MUD_NAME +" Creativity Centre\n"+
	"The walls here are littered with diagrams, flow charts, CPU \n"+
	"and hard disk configurations, as well as new and interesting\n"+
	"pieces of new code. This room is dedicated to asking questions\n"+
	"and answering them, with respect to H7 releases and code.\n");

  set_weather(2, 1, 0);
  set_exits(({
	"d/ooc/rooms/ooc1", "north",
  }));
  set_ooc_room(1);
}
