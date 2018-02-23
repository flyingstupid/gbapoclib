#include <mudlib.h>
#define MONST	"d/coronos/w/miette/"
#define NAME (string)this_player()->query_name()
inherit ROOM;

void reset(status arg) {
    if(!present("elf")) {
	move_object(clone_object(MONST+"elf"),this_object());
    }
    if(arg) return;

    set_short("Cobb");
    set_listen("A slight breeze rustles through the trees. \n");
    set_long(
      "An easterly is the most disagreeable wind in Lyme Bay - Lyme Bay \n" +
      "being that largest bite from the underside of this area's oustretched\n"+
      "southwestern leg. \n") ;
    set_items(({
	"chasms",
	"Gaps and fissures in the earth, filled with plant-life.\n",
	"bluffs#bluff",
	"High, steep, broad-faced banks and cliffs.\n",
	"flint",
	"Very hard stone, a kind of quartz, which produces sparks when struck \n"+
	"against steel.  It may be found in brown, black or gray.\n",
	"chalk",
	"Calcareous earthy substance, of an opaque white color, soft and \n"+
	"easily pulverized.  It is a kind of limestone.\n",
      }));


    set_exits(({
	"d/coronos/w/miette/cobb1", "east",
      }));
    set_weather(1,4,0);
}

