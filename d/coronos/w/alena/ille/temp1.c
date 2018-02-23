#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  if(!present("bird")) {
    object bird;
    int i;

    for(i=0; i<5; i++) {
      bird  = clone_object(MONSTER);
      bird -> set_name("bird");
      bird -> set_short("a small bird");
      bird -> set_long(
		"He's very small and yellow all over. His song \n"+
		"is among the most beautiful you've ever heard.\n");
      bird -> set_gender(1);
      bird -> set_race("bird");
      bird -> set_level(1);
      bird -> load_chat(2, ({
		"Bird pecks around.\n",
		"Bird says: Cheep cheep!\n",
		"Bird looks up at you.\n",
		"Bird hops around.\n",
		"Bird flaps his wings.\n",
	      }));

      move_object(bird, this_object());
    }
  }


    if (arg) return;

    set_short("East Temple");
    set_long(
	"A short path of large white stone blocks marks the way     \n"+
        "to and from the towering edifice of the Temple of the All-God\n"+
	"to the south. To the west, people bustle and hurry about their \n"+
	"business; quite a contrast to the serenity of the small gardens of\n"+
	"flowers by the roadside here.\n");

	set_items(({
	"flowers", 
	"Beautiful blossoms flower all year round in this garden by the\n"+
	"temple. The gardener must be skilled indeed!",

	"stone#blocks#stone blocks#path",
	"The path is made from large white stone blocks. Chiseled into\n"+
	"the sides are patterns of dwarven design. Perhaps they had some\n"+
	"hand in building the city?",

	"patterns", 
	"The patterns are typical of the dwarven culture of the Northern Realms",
	
	"edifice#temple",
	"You can see the temple doors from here. They bear a large symbol",
	
	"symbol#doors#temple doors",
	"A large silver crucifix bears twin dragons entwined in a figure eight\n"+
	"about the centr",
  }));

  set_smell(
      "You smell nothing but the fresh scent of flowers.\n");

  set_listen(
      "You hear the rustling leaves as a breeze blows by.\n");

  set_weather(2, 4, 0);

  set_exits(({
	"/d/coronos/w/angel/city/temple/entrance.c","south",
        "d/coronos/w/alena/ille/m_1", "north",

    }));
}
