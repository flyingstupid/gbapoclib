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

    set_short("Ledge");
    set_smell(
      "The salt of the ocean is in the air.\n");
    set_listen(
      "You can hear the relentless sound of the surf to the east.\n");
    set_long(
      "The ledge is a sloping area of grass some five feet beneath the level\n"+
      "of the plateau.  The chalk walls behind this natural little balcony \n"+
      "make it a sun trap during the day, for its widest axis points \n"+
      "southwest.  Its outer edge gives onto a sheer drop of some thirty \n"+
      "or forty feet into an ugly tangle of brambles.  A little beyond them \n"+
      "the real cliff plunges sharply down to the beach and rough surf.\n");
    set_day_desc(
      "Far out to sea, above the southernmost horizon, there has risen gently \n"+
      "into view an armada of distant cloud.  Cream, amber, snowy, like the \n"+
      "gorgeous crests of some mountain range, the towers and ramparts stretch \n"+
      "as far as the eye can see. . . and yet so remote - as remote as some \n"+
      "abbey of Theleme, some land of sinless, swooning idyll.\n");
    set_items(({
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
      }));
    set_search_array(({
	"ledge",
	"The plateau is five feet above you.  You could probably climb to it. \n",
      }));
    set_weather(1,4,0);
}
void init() {
    ::init();
    add_action("plateau", "climb");
    add_action("plateau", "climb plateau");
}
plateau() {
    write("You climb up to the plateau.\n");
    tell_room(environment(this_player()), this_player()->query_name()+" climbs up to the plateau. \n");
    move_object(this_player(), PATH "trail6");
    return 1;
}

