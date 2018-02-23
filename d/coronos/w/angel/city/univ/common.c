#include <mudlib.h>

#define PATH 	"d/coronos/w/angel/city/univ"
#define MONST	"d/coronos/w/angel/city/monst"

inherit ROOM;

void reset(status arg) {
  object board;
  reset_doors(arg);

  if(!present("board")) {
    board = clone_object(BULLETIN_BOARD);
    board -> set_save_file("ob_saves/boards/mage1");
    board -> set_long(
	"This board is designed for discussion between Masters and \n"+
	"Apprentices of magic, and for topics of magic of the Robes\n");
    move_object(board, this_object());
  }


  load_door(({
	"file", PATH+"/foyer",
	"direction", "north door",
	"long",
	"The door is made from a hard wood and is bound in iron.\n",
  }));

  if(arg) return;

  set_short("the University of Power");
  set_long(
"Here is a room for relaxing, with plush sofas and divans, fine paintings and \n"+
"sweet incense burning. This is the wizards common room where the masters of \n"+
"the various departments come to relax away from their annoying students.\n");

  set_weather(2, 1, 0);

  set_items(({
	"sofas#divans",
"They are made from fine royal purple silk and red hard woods.\n"+
"A fine collection to any living room",

"paintings", 
"There are several paintings of abstract art work by the famous \n"+
"artist of Ille Coronos; Jacques Silverbrush",

"incense", "A golden incense burner stands in the corner, burning "+
"day and night",
  }));


  set_listen("All is quite and peaceful here.\n");
  set_smell("The scent of fine perfumes and incense greets your nostrils.\n");

  set_exits(({
  }));
}


