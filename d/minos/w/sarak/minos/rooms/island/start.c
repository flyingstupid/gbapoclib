#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit "inherit/room2";

void reset(status arg) {
  object board;
  if(!present("board")) {
    board = clone_object(BULLETIN_BOARD);
    board->set_save_file(BOARD_FILE);
    board -> set_long(
"	The Minotaur Island bulletin board is used to pass ideas and\n"+
"comments between players and creators regarding the island. Please\n"+
"feel free to post your thoughts on the area upon this board.\n");
    move_object(board, this_object());
  }
  if (arg) return;

  set_short("Minotaur Island");
  set_long (
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
   "As you glance around this small and uninviting island, you notice a\n"+
   "large golden castle nestled within the mountains to the north. The\n"+
   "cool ocean breeze combined with the chilly water washing over your\n"+
   "feet help to cool you down on this hot tropical island. To your east\n"+
   "and west lies a great forest. You can make out small walking tracks\n"+
   "leading into the western part of the forest and an old path winding\n"+
   "through the eastern side.\n"+
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  set_weather(1,4,2);
  set_exits (({
    ISLAND_ROOMS+"west1", "west",
    ISLAND_ROOMS+"land", "east",
    CASTLE_ROOMS+"valley.c", "north",
    "d/affils/ships/open/types/tamiel/stern", "tamiel",
  }));
  set_items (({
    "castle", "The magnificent castle is covered in gold. From here it\n"+
      "looks a little different towards the top of the castle",
    "mountains", "These huge mountains make up most of the island and\n"+
      "provide a safe haven for the castle",
    "forest", "The dense rainforest seems impossible to travel through",
    "tracks", "The small tracks in the forest have become too small to\n"+
      "travel through due to the fast growing trees",
    "water#ocean", "The ocean water looks very refreshing",
  }));
}
