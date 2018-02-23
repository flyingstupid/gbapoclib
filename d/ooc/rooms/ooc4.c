#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
    object board;
    object chair;

    if(!present("board")) {
	board = clone_object(BULLETIN_BOARD);
	board -> set_save_file("/ob_saves/ooc/board1");
	board -> set_long("This board is for OOC topics.\n");
	move_object(board,this_object());
    }
    if(!present("chair")) {
	chair = clone_object("/d/ooc/w/alena/simple_chair1");
	move_object(chair, this_object());
    }

    if(arg)return;
    set_short("upstairs from the main meeting room");
    set_long(
      "A large picture window looks out to the west, however, the view "+BS(n)+
      "is blocked by the many branches of a large oak tree. The walls of "+BS(n)+
      "the room are covered with wooden paneling. The floor under "+BS(n)+
      "a tattered rug is the same hardwood as the room downstairs. "+BS(n)+
      "The room seems bare other then a single chair within the corner "+BS(n)+
      "and a board hanging upon the south wall."+BS(n));
    set_items(({
	"large picture window#picture window#window#west window",
	"Thick branches of a tall oak tree block your view."+BS(n),
	"branches#tall oak#oak tree#oak#thick branches",
	"They hang out of reach and block all view from this upstairs "+BS(n)+
	"window."+BS(n),
	"walls#wall#wooden paneling",
	"Even though it is fake wood it still gives the room an older "+BS(n)+
	"charm, much like wooden homes from the past."+BS(n),
	"floor#hardwood floor",
	"Made of hardwood to last as well as to match the walls."+BS(n),
	"rug#tattered rug",
	"Many footprints can be found upon the darkened beige rug."+BS(n),
	"stairs#staircase",
	"They lead back down to the main room."+BS(n),
      }));
    set_exits (({
	"/d/ooc/rooms/ooc2","stairs",
      }));
    set_smell("You smell nothing out of the ordinary."+BS(n));
    set_listen("You hear people chatting downstairs."+BS(n));
    set_weather(2, 1, 0);
    set_ooc_room(1);

}
/* Lena  Sept 27, 1996 */
