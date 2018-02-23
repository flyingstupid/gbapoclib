#include <mudlib.h>
#define MONST	"d/coronos/w/miette/"
#define NAME (string)this_player()->query_name()
inherit ROOM;

void reset(status arg) {
    if(!present("elf")) {
	move_object(clone_object(MONST+"elf"),this_object());
    }
    if(arg) return;

    set_short("Trail");
    set_listen("A slight breeze rustles through the trees. \n");
    set_long(
      "The terrain here is very abrupt, cut by deep chasms and accented by \n"+
      "strange bluffs and towers of chalk and flint, which loom over the lush\n"+
      "foliage around them like the walls of ruined castles.\n");
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
	"d/coronos/w/miette/trail1", "north",
	"d/coronos/w/miette/track", "west",
      }));
    set_weather(1,4,0);
}

