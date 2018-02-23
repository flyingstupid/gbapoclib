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
      "Primitive yet complex, elephantine but delicate; as full of subtle \n"+
      "curves and volumes as a Henry Moore or a Michelangelo; and pure, clean,\n"+
      "salt, a paragon of mass.  This is the Cobb. \n");
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
	"d/coronos/w/miette/cobb1", "west",
	"d/coronos/w/miette/cobb3", "east",
      }));
    set_weather(1,4,0);
}

