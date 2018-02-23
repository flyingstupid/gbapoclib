#include <mudlib.h>
#define MONST	"d/coronos/w/miette/"
#define NAME (string)this_player()->query_name()
inherit ROOM;

void reset(status arg) {
    if(!present("dragon")) {

	move_object(clone_object(MONST+"dragon1"),this_object());
    }
    if(arg) return;

    set_short("Trail");
    set_smell(
      "The salt of the ocean is in the air.\n");
    set_listen(
      "You can hear the relentless sound of the surf to the east.\n");
    set_long(
      "The cavern is vast hollow, right in the hill's heart, its darkness hardly \n"+
      "touched by your light, its dead stillness of air where you can\n"+
      "feel and hear your own blood beating. The face of the cavern shows the \n"+
      "marks of work, the face seamed and split by axes, and smashed open by \n"+
      "water.  There is a doomed roof that disappears into darkness and in a \n"+
      "corner some rusty metal where a pump had stood.  On the walls is a \n"+      "curtain of gleaming damp.  Fully a third of the floor is under water.\n"+
      "Rubble blocks the passage east.\n");  
    set_items(({
	"dome#roof",
	"The top of the cavern is obscured by darkness.\n",
	"rubble",
	"Rocks and dirt block the passage east.\n",
	"pump#metal",
	"The metal was once a pump used to draw water out of the pool.  Now, only \n"+
	"rusted metal remains.\n",
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
      }));
    set_weather(1,4,0);
}
void init() {
    ::init();
    add_action("rubble","rubble");
    add_action("rubble","enter rubble");
    add_action("water", "enter");
    add_action("water", "enter water");
    add_action("water", "dive");
    add_action("water", "dive water");

}

status rubble (){
    if(present("symbol", this_player())){
	this_player()->move_player("#/d/coronos/w/miette/lairc");
	tell_room(environment(this_player()), this_player()->query_name()+" disappears into the rubble. \n");
	return 1;
    }
}

void long(status wiz) {
    ::long(wiz);
    if(present("symbol", this_player())) {
	write("You notice a passage: <rubble>\n");
    }
}
water() {
    write(
      "You try to enter the water but it is too cold.\n");
    say(NAME+" tries to enter the water but finds it too cold.\n");
    return 1;
}
