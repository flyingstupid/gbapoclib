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

    set_short("Trail");
    set_smell(
      "The salt of the ocean is in the air.\n");
    set_listen(
      "Your footsteps make a crunching sound on the path.\n");
    set_long(
      "The ground slopes shaply up, west, to a bluff some two hundred yards\n"+
      "away; this is one of the huge subsident steps that can be glimpsed \n"+      "from the Cobb two miles away.  East, the path leads to a grassy plateau.\n");
    set_day_desc(
      "The far clouds remind you of your own dissatisfaction; of how you would \n"+
      "like to be sailing once again through the Tyrrhenian; or riding, arid \n"+
      "scents in your nostrils, towards the distant walls of Avila; or \n"+
      "approaching some temple in blazing sunshine.  But even so a figure, \n"+
      "a dark shadowy spider, moves ahead of you, lightly luring, up the \n"+
      "ashlar steps and into the broken columns' mystery.\n");
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
	"d/coronos/w/miette/trail8", "west",
	"d/coronos/w/miette/trail6", "south",
      }));
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
    add_action("wall", "climb");
    add_action("wall", "climb wall");
    add_action("ledge", "jump");
    add_action("ledge", "jump ledge");
}
wall() {
    write("You climb the wall.\n");
    tell_room(environment(this_player()), this_player()->query_name()+" climbs over the wall. \n");
    move_object(this_player(), PATH "trail5");
    return 1;
}
ledge() {
    write("You jump down to the ledge.\n");
    tell_room(environment(this_player()), this_player()->query_name()+" jumps over the edge of the plateau. \n");
    move_object(this_player(), PATH "cledge");
    return 1;
}

