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
  "The slope on which you find yourself, the prospect before you, the \n"+      "sounds, the scents, the unalloyed wildness of growth and burgeoning \n"+
      "fertility, forces you into anti-science.  The ground about you is \n"+
      "studded gold and pale yellow with celandines and primroses and banked \n"+
      "by the bridal white of densely blossoming sloe.\n");
    set_items(({
 "sloe",
        "Small, bitter, blue-black, wild plums.\n",
        "celandines#celandine",
        "A weedy plant of the poppy family, with deeply divided leaves\n"+
        "and yellow flowers and juice.\n",
        "primrose#primroses",
        "Plants with white, yellow and red tubelike flowers with five lobes.\n",
        "sloe",
        "Trees with black bark, finely serrulate leaves and white flowers.\n",        "elder#elders",
        "Trees of the honeysuckle family, bearing large corymbs of white and pink\n"+
        "flowers and red and black berries.\n",
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
	"d/coronos/w/miette/trail3", "north",
	"d/coronos/w/miette/trail1", "south",
      }));
    set_weather(1,4,0);
}

