#include "/players/relgar/private/mydefs.h"
inherit "/d/tempus/w/relgar/main.c";

reset(arg){

    if(arg)return;

    set_exits(({
	"d/tempus/w/relgar/steps","west",
	"d/tempus/w/relgar/road2","east",
      }));
    set_short("An ash covered road");
    set_light(1);
    set_long(
      "        You walk along a section of road that is very dark and foreboding.\n"+
      "The buildings on both sides of the street have been weather beaten to the\n"+
      "point that the wood they are made of has turned a silvery grey color. To\n"+
      "the north only the face of the building still stands. The rest of the    \n"+
      "building has burned to the ground and the ashes cover the sides of the   \n"+
      "buildings to either side making them appear even darker. To the south you\n"+
      "can see the back of one of the buildings on the main thoroughfare. It too\n"+
      "has suffered from the weather and appears dead and decayed.\n"
    );
    set_items(({
	"buildings#building",
	"Which building? The north or the south building?\n",
	"north building#facade",
	"The north building has burned to the ground and only the facade of the \n"+
	"structure remains. It is a dark grey color and has thrown ash all over\n"+
	"the buildings to either side of it.\n",
	"south building#back",
	"The south building is merely the back of one of the buildings on the main\n"+
	"thoroughfare through the town.\n",
	"ashes",
	"The ashes from the burned down building cover the walls of the buildings\n"+
	"near it. They also give the whole area a greyish cast.\n",
      }));
    set_smell(
      "You smell the acrid stench of sulfur in the air.\n");
    set_listen(
      "You hear a dog whining nearby.\n"
    );
} /* end of reset */
