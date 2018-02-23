#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
object board;
  if(!present("board")) {
    board = clone_object(BULLETIN_BOARD);
    board -> set_save_file("ob_saves/boards/elder");
    board -> set_short("An MUDLIB notice board");
    move_object(board,this_object());
  }

  if(arg) return;
  set_short("The inner rooms of OOC");
set_long("\
\n\
  This large chamber is used simply as a place where the Admin Staff place\n\
  notes to inform eachother about matters of the mudlib.  Anyone who is a\n\
  Senior or greater be aware of what is written here. \n\
\n\
");

  set_exits(({
     "/d/ooc/creator/inner1", "north",
  })); 
  set_weather(2,1,0);
}

