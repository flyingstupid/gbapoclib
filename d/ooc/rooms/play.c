#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object ob;
    if(!present("board")) {
        ob = clone_object(BULLETIN_BOARD);
	ob -> set_long(
	"This board is for H7 Players to write and discuss their skills, \n"+
	"their spells, and all things related to play.\n");
        ob -> set_save_file("ob_saves/boards/oocplay");
        move_object(ob, this_object());
    }

  if(arg) return;
  set_ooc_room(1);
  set_short("the H7 players room");
  set_long(
	" [ OOC ] The "+ MUD_NAME +" Players Discussion Centre\n"+
	"This is a simple room devoted to player discussion on \n"+
	"mud things, whether it be spells, skills or anything!\n");

  set_weather(2, 1, 0);
  set_exits(({
/**
	"d/ooc/rooms/vote", "north",
**/
	"d/ooc/rooms/ooc1", "south",
  }));
}
