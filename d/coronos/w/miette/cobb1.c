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
      "The Cobb has invited what familiarity breeds for at least seven \n"+
      "thousand years, and the people who live here will never see much \n"+
      "more to it than a long claw of old grey wall that flexes itself \n"+
      "against the sea.  In fact, since it lies well apart from the main \n"+
      "town, a tiny Piraeus to a microscopic Athens, they seem almost to \n"+
      "turn their backs on it. \n") ;
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
	"d/coronos/w/miette/cobb", "west",
	"d/coronos/w/miette/cobb2", "east",
      }));
    set_weather(1,4,0);
}

