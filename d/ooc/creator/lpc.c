#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
object board;
  if(!present("board")) {
    board = clone_object(BULLETIN_BOARD);
    board -> set_save_file("ob_saves/boards/LPC");
    board -> set_short("A 'LPC' notice board");
    move_object(board,this_object());
  }

  if(arg) return;
  set_short("The inner room of town hall");
set_long("\
\n\
  This large chamber is used to discuss and place notes about LPC and related\n\
  items, including mudlib functions. \n\
\n\
");

  set_exits(({
     "/d/ooc/creator/inner1", "west",
     "/obj/quests/quest_rm",  "east",
  })); 
  set_weather(2,1,0);
}

