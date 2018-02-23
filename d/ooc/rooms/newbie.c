#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object ob;

  if(!present("board")) {
    ob = clone_object(BULLETIN_BOARD);
    ob -> set_save_file("ob_saves/boards/newbie");
    ob -> set_short("A Newbie's Board -> type bo to read it");
    ob -> set_long(
	"This board is for letting new people to H7 know of \n"+
	"how to play, hints to play, and other things like that!\n");
    move_object(ob, this_object());
  }


  if(arg) return;

  set_short(" [ Newbie Information Centre ] ");

  set_long(
" [ Newbie Information Centre ] \n"+
"This room is dedicated to informing new players of various \n"+
"bits of information, rules, and playing tips. \n");

  set_weather(2, 1, 0);

  set_exits(({
    "d/ooc/rooms/ooc1", "east",
    "d/ooc/rooms/post", "west",
  }));

  set_ooc_room(1);

}




