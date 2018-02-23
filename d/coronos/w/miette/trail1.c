#include <mudlib.h>
#define MONST	"d/coronos/w/miette/"
#define NAME (string)this_player()->query_name()
inherit ROOM;

void reset(status arg) {
    if(!present("raven")) {
	move_object(clone_object(MONST+"raven"),this_object());
    }
    if(arg) return;

    set_short("Trail");
    set_listen("A slight breeze rustles through the trees. \n");
    set_long(
      "This very unusual area is a mile-long slope caused by the \n"+
      "erosion of an ancient vertical cliff face.  Flat places are rare. \n"+
      "But this steepness in effect tilts it, and its vegitation, toward \n"+
      "the sun; and it is this fact, together with the water from the \n"+
      "countless springs that have caused the erosion, that lends the area\n"+      "its botanical strangeness - its wild arbutus and ilex and other\n"+
      "trees you will find growing no where else; its enormous ashes and \n"+
      "beeches; its green Brazilian chasms choked with ivy and the liana \n"+
      "of wild clematis; its bracken that grows seven eight feet tall; its\n"+      "flowers that bloom a month earlier than anywhere else.\n");
    set_items(({
	"arbutus",
	"Evergreen plants.  They have panicles of large, pale greenish-white \n"+
	"flowers, red fruit and evergreen leaves.\n",
	"ilex",
	"Shrubs of the holly family.\n",
	"ash#ashes",
	"Timber and shade trees.  They have pinnate leaves, winged fruit, and \n"+
	"tough, elastic wood with straight, close grain.\n",
	"beech#beeches",
	"Large trees with hard wood, dark-green leaves, and edible three-cornered\n"+
	"nuts.  The bark is smooth can be used to write on.\n",
	"chasms#chasm",
	"Fissures and clefts in the ground coked with plants.\n",
	"ivy",
	"A climbing vine, with a woody stem and evergreen leaves.\n",
	"clematis",
	"Woody climbing plants of the crowfoot family, with bright-colored \n"+
	"flowers.\n",
	"bracken",
	"Large, coarse ferns.\n",
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
	"d/coronos/w/miette/trail2", "north",
	"d/coronos/w/miette/trail", "south",
      }));
    set_weather(1,4,0);
}

