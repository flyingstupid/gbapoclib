#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
object board;

  if(!present("board")) {
    board = clone_object(BULLETIN_BOARD);
    board -> set_save_file("ob_saves/boards/inner1");
    board -> set_short("A creator's notice board");
    move_object(board,this_object());
  }

  if(arg) return;
  set_short("The inner room of town hall");
set_long("\
\n\
  This large chamber exudes the magical power that allows the creator to\n\
  design and create.  Here is where creators meet and to discuss matters of\n\
  great importance.  North --> 'QC' notes and area approval East --> 'LPC'\n\
  notes and coding items\n\
\n\
");

  set_exits(({
     "/d/ooc/creator/qc", "north",
     "/d/ooc/creator/lpc", "east",
     "/d/ooc/creator/elder", "south",
     "d/ooc/rooms/ooc1", "west",
  })); 
  set_weather(2,1,0);
}


