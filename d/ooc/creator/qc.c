#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
object board;
  if(!present("board")) {
    board = clone_object(BULLETIN_BOARD);
    board -> set_save_file("ob_saves/boards/QC");
    board -> set_short("A 'QC' notice board");
    move_object(board,this_object());
  }

  if(arg) return;
  set_short("The inner room of town hall");
set_long("\
\n\
  This large chamber is used primarily as an announcement room for QC related\n\
  matters.   If you wish to have an area, or item approved, or queries about\n\
  'QC' matters, then post notes here. \n\
\n\
");

  set_exits(({
     "/d/ooc/creator/inner1", "south",
  })); 
  set_weather(2,1,0);
}

