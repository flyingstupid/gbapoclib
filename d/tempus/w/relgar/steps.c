#include "/players/relgar/private/mydefs.h"
inherit "/d/tempus/w/relgar/main.c";

reset(arg){
    object board;
    if(!present("board")){
	board = clone_object(BULLETIN_BOARD);
	board -> set_long(
	  "Comments, questions, concerns about this area can be posted here.\n"+
	  "Once my area is up I'll be checking this board frequently and removing\n"+
	  "any posts once they are over two weeks old.\n"
	);
	board -> set_save_file("/ob_saves/relgar_temple_board");
	move_object(board,TO);
    } /* endif */

    if(arg)return;
    set_exits(({
	"d/tempus/w/relgar/road1","east",
      }));
    load_door(({
	"destination","d/tempus/w/relgar/entrance",
	"direction","north door",
	"open","unlocked",
	"long",
	"The double doors to the north are extremely large and have strange sigils\n"+
	"carved into the faces of them.\n",
	"lock id","lock",
	"key id","key",
	"door number",1,
	"trap off",
	"lock difficulty",1000,
      }));
    set_short("The steps up to the temple");
    set_light(1);
    set_long(
      "        You stand just to the south of an extremely large cathedral. The\n"+
      "butresses that hold the walls are carved to resemble menacing demons and\n"+
      "tortured human forms. A wide flight of steps lead up to a pair of double\n"+
      "doors that lead into the cathedral. The road to the west ends in a deep \n"+
      "ravine.\n"
    );
    set_items(({
	"humans",
	"The carvings of humans appear to be crying out for help and relief from \n"+
	"their endless suffering.\n",
	"demons#demon#spawn of hell#hell-spawn",
	"The carvings of demons appear to leer down at you from their high perches.\n",
	"cathedral",
	"The cathedral is extremely menacing. It is obviously not a place of holy\n"+
	"worship. There are many carvings of demons and other hell-spawn.\n",
	"carvings#butresses",
	"The carvings and butresses are carved in the forms of demons and other  \n"+
	"spawn of hell. They appear to be leering at you from their high perches.\n"+
	"Several of them are also carved to resemble the tortured forms of humans\n"+
	"the appear to be crying out for help and relief from their endless \n"+
	"suffering.\n",
	"steps",
	"The wide stone steps lead up to a pair of double doors to the north.\n",
	"ravine",
	"The ravine to the west is extremely deep. It blocks all passage to the west.\n",
      }));
} /* end of reset */
