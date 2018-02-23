#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
    object obj, pollen;
    int y;


    if(!present("bee")) {
	for(y=0; y < (4 + random(4)); y++) {
	    obj = clone_object(MONSTER);
	    obj -> set_name("bee");
	    obj -> set_race("insect");
	    obj -> set_short("A busy bee");
	    obj -> set_long(
	      "A little yellow and black striped bee. As it is a native \n"+
	      "Australian bee, it does not have a sting. Even so, it can\n"+
	      "still cause a nuisance.\n");
	    obj -> set_level(1);
	    obj -> set_ac(3);
	    obj -> set_wc(5);
	    obj -> load_chat(5, ({ "Bee buzzes merrily.\n",
		"Bee buzzes happily.\n",
		"Bee buzzes noisily.\n",
		"Bee buzzes hurridly.\n",
		"Bee buzzes around.\n",
		"Bee collects pollen from the wattle.\n",
		"Bee buzzes around you head.\n",
	      }));
	    obj -> load_a_chat(5, ({ "Bee buzzes angrily.\n",
		"Bee buzzes around your head.\n",
		"Bee buzzes noisily.\n",
		"Bee buzzes ferociously.\n",
		"Bee buzzes menacingly.\n",
	      }));
	    obj -> set_attack_msg(({
		"bumps into",  "softly",
		"bumps into",  "lightly",
		"bumps into",  "with some force",
		"grazes", "",
		"bumps into",  "with a great deal of force",
		"bumps into",  "with a stunning blow!",
		"bumps into",  "with a bone crunching sound!",
	      }));
	    move_object(obj, this_object());
	    pollen = clone_object(TREASURE);
	    pollen -> set_name("pollen");
	    pollen -> set_short("Some pollen");
	    pollen -> set_sell_destruct(1);
	    pollen -> set_long(
	      "This is some pollen from a yellow wattle bush.\n");
	    pollen -> set_weight(1);
	    pollen -> set_value(20 + random(50));  /* something to give out */
	    move_object(pollen, obj);
	}
    }

    if(arg) return;

    set_short("the city garden");
    set_long(
      "A beautiful flowering wattle bush stands beside the cobblestone \n"+
      "pathway which winds its way around in many directions. The sounds\n"+
      "of bees fills the air as they busily collect pollen from the    \n"+
      "wattle flowers. ");

    set_day_desc(
      "The sunlight beams down on you from on high,\npeeking through "+
      "the white fluffy clouds.\n");
    set_night_desc(
      "The moon stares down at you as dark sinister clouds\npass by.\n");

    set_listen("The air is full of busy bees buzzing...\n");
    set_smell("The air is full of the sweet smell of wattle.\n");

    set_items(({
	"wattle#bush",
	"A fine yellow wattle bush. The spiky wattle has sharp spines \n"+
	"at the end of its leaflike stalks. The leaves of most wattles\n"+
	"are minute, appearing to be almost like flattened stalks",
	"path#cobblestone path#cobblestones#cobblestone",
	"A well travelled cobblestone path",
	"tree#gum tree#ghost-gum#gum",
	"This tree's trunk is a light grey, almost white colour. Atop \n"+
	"the tree is some movement amid the leaves",
	"orchid#spider orchid",
	"A long black-orange flower sways in the breeze that blows \n"+
	"through the leaves of the trees. The orchid seems to be   \n"+
	"growing on the trees themselves",
      }));
    set_day_items(({
	"sunlight#sun#light",
	"Do you want to go blind?",
	"cloud#clouds",
	"They are white and fluffy. One reminds you of an echidna",
      }));

    set_night_items(({
	"moon",
	"You can see the man in the moon. He \n"+
	"appears to be grinning an evil grin at you",
	"cloud#clouds",
	"They look dark and sinister...and very spooky",
      }));
    set_exits(({
	"d/coronos/w/angel/city/gardens/garden2", "northeast",
	"d/coronos/w/angel/city/gardens/garden10", "southeast",
	"d/coronos/w/angel/city/gardens/garden6", "east",
	"/d/coronos/w/vorax/alley6","west",
      }));
    set_weather(1,4,0);
}
