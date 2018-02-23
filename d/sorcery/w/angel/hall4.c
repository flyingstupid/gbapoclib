#include <mudlib.h>
inherit ROOM;

object board;
void reset(status arg) {
  reset_doors(arg);
  if(!present("board")) {
    board = clone_object(BULLETIN);
    board -> set_save_file("ob_saves/boards/robes");
    board -> set_long("The board of the Robes of Alignment\n");
    move_object(board, this_object());
  }

  if(arg) return;

  load_door(({
	"direction", "north door",
	"file", "d/sorcery/w/angel/path6",
	"long",
	"Two ornate doors of translucent blue glass steel",
  }));
  set_short("the tower of sorcery");
  set_long(
"The ceiling of the main chambers of the Towers of High Sorcery looms \n"+
"overhead; an impressive display of magical architecture. The ceiling \n"+
"is almost composed entirely of glass, but it appears to be as hard as\n"+
"steel; there are no supports to speak of! The walls are reasonably   \n"+
"plain, but there are huge glass windows stretching from floor to     \n"+
"ceiling, complimenting the overall feeling of the room. This is a    \n"+
"place of light.\n");

  set_items(({
"ceiling", "Its made entirely of glass steel",
"walls#wall", 
"The wall has large windows of similar design to the ceiling",
  }));


  set_weather(2, 1, 0);
  set_exits(({
	"d/sorcery/w/angel/hall3", "south",
  }));
}

