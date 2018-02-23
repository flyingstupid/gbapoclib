#include <mudlib.h>
#define MONST	"d/coronos/w/miette/"
#define PATH "d/coronos/w/miette/"
#define NAME (string)this_player()->query_name()
inherit ROOM;

void reset(status arg) {
    if(!present("squirrel")) {
	move_object(clone_object(MONST+"squirrel"),this_object());
    }
    if(arg) return;

    set_short("Cave");
    set_smell(
      "You smell the fresh water.\n");
    set_listen(
      "Somewhere deeper in the hill is the sound of water falling.\n");
    set_long(
      "The cave's dark emptiness is doubled in the great mirror of water that\n"+
      "has spread until it covers all of the floor save for a dry crescent of \n"+
      "rock six paces deep, just inside the mouth of the adit.  Into this great\n"+
      "still lake the jutting ribs of the cave walls run like buttresses to \n"+
      "meet the angle of their own reflections, then on down again into \n"+
      "darkness.  The walls of the cave are curtained with a think shining \n"+
      "veil of damp which slides down imperceptibly to swell the pool.\n");
    set_items(({
	"cliff",
	"The cliff rises about twenty feet.  You might try and climb it.\n",
	"path",
	"The rock by the path is dry.\n",
	"plateau",
	"The Undercliff here is slightly elevated.\n",
	"birdsfoot",
	"Various ferns with small wiry leaves in groups of three.\n",
	"wall#stone",
	"A three foot high wall made from individual stones.  You could climb it.\n",
	"celandines#celandine",
	"A weedy plant of the poppy family, with deeply divided leaves\n"+
	"and yellow flowers and juice.\n",
	"primrose#primroses",
	"Plants with white, yellow and red tubelike flowers with five lobes.\n",
	"sloe",
	"Trees with black bark, finely serrulate leaves and white flowers.\n",
	"elder#elders",
	"Trees of the honeysuckle family, bearing large corymbs of white and pink\n"+
	"flowers and red and black berries.\n",
	"moschatel",
	"Plants of the honeysuckle family.  Their leaves and greenish-white \n"+
	"flowers smell like musk.\n",
	"woodsorrel",
	"Plants with pink, white, red, yellow and purplish flowers made up of \n"+
	"five petals on a cone-shaped tube.\n",
	"anemones#anemone",
	"Plants with cup-shaped flowers, usually white, purple or red.\n",
	"bluebell#bluebells",
	"Plants with blue, bell-shaped flowers.  These are wild hyacinths.\n",

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
	"d/coronos/w/miette/cave1", "out",
      }));
    set_climb(20);
    set_fall_dam(random(15));
    set_search_array(({
	"plateau",
	"The plateau is more or less level.  Its northern edge hides a broad,\n"+
	"sloping ledge of grass some five feet beneath the level of \n"+
	"the plateau.  You could probably jump to it\n",
      }));
    set_weather(1,4,0);
}
void init() {
    ::init();
    add_action("cliff", "climb");
    add_action("cliff", "climb cliff");

}
cliff() {
    write("You climb the cliff.\n");
    tell_room(environment(this_player()), this_player()->query_name()+" climbs the cliff. \n");
    this_player()->move_player("climbs the cliff"+"#/players/miette/surface/ucave1") ;
    return 1;
}
