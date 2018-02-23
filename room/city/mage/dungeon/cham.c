#include <mudlib.h>
inherit "/players/josh/room/dungeon/Dtemp.c";

#define NAME "josh"


reset (arg) {
    if (arg) return;
    set_short("Large central chamber");

    set_long(
      "This room is brightly lit by dozens of glowing orbs.  With this light you can \n"+
      "see that this room is shaped like a pentagon. Each wll is etched with protective \n"+
      "glyphs that your eyes have a hard time focusing on. Five carved collums support \n"+
      "the ceiling.\n"
    );
    set_items(({
	"collums#collum","Which collum? There are five. i.e. look at ne collum\n",
	"ceiling","High above you see a arching domed roof. \n"
      }));
    set_exits (({
	"stcase.c","u",
	"neh.c","ne",
	"seh.c","se",
	"sh.c","south",
	"swh.c","sw",
	"nwh.c","nw"
      }));
}
