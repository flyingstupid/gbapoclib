#include <mudlib.h>
#define MONST	"d/coronos/w/miette/"
#define NAME (string)this_player()->query_name()
inherit ROOM;

void reset(status arg) {
    int i ;
    if(!present("squirrel")) {
	for(i=0;i<2;i++) {

	    move_object(clone_object(MONST+"squirrel"),this_object());
	}
    }
    if(arg) return;

    set_short("Trail");
    set_smell(
      "The salt of the ocean is in the air.\n");
    set_listen(
      "You can hear the relentless sound of the surf to the east.\n");
    set_long(
      "You appear to be in a main gallery, and the rock seems reasonably good.\n"+
      "Here and there are falls from roof or wall, and the passage west is \n"+
      "blocked by a fall of rubble.  East the tunnel returns to the entrance.\n")
    ;
    set_items(({
	"wall#adit#cave#shaft",
	"On the wall the image of a dragon has been etched in blood.\n",
	"thicket",
	"A dense growth of brambles and vines reinforced with fallen dirt and rock.\n",
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
	"d/coronos/w/miette/lairb", "east",
      }));
    set_weather(1,4,0);
}
void init() {
    ::init();
    add_action("rubble","rubble");
    add_action("rubble","enter rubble");

}

status rubble (){
    if(present("symbol", this_player())){
	this_player()->move_player("#/d/coronos/w/miette/laird");
	return 1;
    }
}

void long(status wiz) {
    ::long(wiz);
    if(present("symbol", this_player())) {
	write("You notice a small passage: <rubble>\n");
    }
}
