#include <mudlib.h>

inherit MONSTER;

void reset(status arg) {
  object sack, corn;
  string *races;
  ::reset(arg);

  if(!present("bag")) {
    sack = clone_object(CONTAINER);
    sack -> set_name("sack");
    sack -> set_plural("sacks");
    sack -> set_short("a sack");
    sack -> set_long("The sack is made from tough material and could\n"+
		     "carry quite a lot.\n");
    sack -> set_weight(3);
    sack -> set_max_weight(20);
    sack -> set_value(250);
    move_object(sack, this_object());
  }

  if(!present("corn", sack)) {
    corn = clone_object(FOOD);
    corn -> set_name("corn");
    corn -> set_short("a bushel of corn");
    corn -> set_long("There is at least 100 pieces of corn here.\n");
    corn -> set_weight(5);
    corn -> set_value(100);
    corn -> set_strength(50);
    corn -> set_consumer_msg("The corn tastes very fresh, but after eating "+
    "a whole bushel you feel sick.\n");
    corn -> set_room_msg("@@query_name:$this_player()$@@ eats a whole bushel "+
    "of corn at once!\n");
    move_object(corn, sack);
  }


  if(arg) return;


    set_name("farmer");
    set_plural("farmers");
    set_short("a simple farmer");
    set_long(
	"This simple farmer is on his way to market with his produce.\n");

    set_gender(1);
    set_alignment(random(100));
    set_level(4 + random(3)); /* add a little variation */
    races = ({ "half elf", "halfling", "human", "dwarf", });
    set_race(races[random(sizeof(races))]);
  
    add_money(10 + random(100));


    add_class("fighter");

    load_chat(5, ({
	"Farmer asks: Are you on your way to market?\n",
	"Farmer asks: Any news from the big city?\n",
	"Farmer says: I'd rather be sittin' by the fire.\n",
	"Farmer says: I'd rather be in the fields.\n",
	"Farmer asks: Are you from the big city?\n",
	"Farmer says: Darn mice keep gettin' into the corn.\n",
    }));

    load_a_chat(5, ({
	"Farmer exclaims: Help me! Bandits!\n",
	"Farmer exclaims: I'll report you to the city guard!\n",
	"Farmer tries to run away!\n",
    }));

}




