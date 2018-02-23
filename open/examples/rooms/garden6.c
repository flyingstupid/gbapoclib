#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object obj, seeds;
  int y;


  if(!present("bird")) {
    for(y=0; y < (4 + random(4)); y++) {
      obj = clone_object(MONSTER);
      obj -> set_name("pigeon");
      obj -> set_race("bird");
      obj -> set_short("A grey pigeon");
      obj -> set_long(
		"A simple little pigeon, searching for some food.\n");
      obj -> set_level(1);
       obj -> set_max_hp(45);
      obj -> set_hp(45);
      obj -> set_ac(3);
      obj -> set_wc(5);
       obj -> load_chat(5, ({ "Pigeon flaps its wings.\n",
		"Pigeon bobs its head.\n",
		"Pigeon tilts is head at you.\n",
		"Pigeon waddles around.\n",
       }));
      obj -> load_a_chat(5, ({ "Pigeon flaps around angrilly.\n",
		"Pigeon pecks at your feet.\n",
		"Pigeon tries to fly away...!\n",
	}));
      obj -> set_attack_msg(({
               "pecks into",  "softly",
               "pecks into",  "lightly",
               "pecks into",  "with some force",
               "grazes", "",
               "pecks into",  "with a great deal of force",
               "pecks",  "with a stunning blow!",
               "pecks into",  "with a bone crunching sound!",
             }));
      move_object(obj, this_object());
      seeds = clone_object(FOOD);
      seeds -> set_name("seeds");
      seeds -> set_short("Some seeds");
      seeds -> set_strength(1);
      seeds -> set_sell_destruct(1);
      seeds -> set_long(
                    "This is some seeds from a yellow wattle bush.\n");
      seeds -> set_weight(1);
      seeds -> set_value(20 + random(50));  /* something to give out */
      move_object(seeds, obj);
    }
  }

  if(arg) return;

  set_short("the city garden");
  set_long(
	"More flowering, yellow wattle bushes stand by the cobblestone\n"+
     "pathway which winds its way west and easts from here. The sounds \n"+
     "of cooing pigeons fills the air as they busily gather food     \n"+
     "that has fallen on the ground. ");

  set_day_desc(
     "The sunlight beams down on you from on high,\npeeking through "+
     "the white fluffy clouds.\n");
  set_night_desc(
     "The moon stares down at you as\n dark sinister clouds pass by.\n");

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
	"d/coronos/w/angel/city/gardens/garden2", "north",
	"d/coronos/w/angel/city/gardens/garden10", "south",
	"d/coronos/w/angel/city/gardens/garden5", "west",
	"d/coronos/w/angel/city/gardens/garden7", "east",
  }));
  set_weather(1,4,0);
}
