#include <mudlib.h>

#define OBJ		"d/coronos/w/angel/ud/obj"
#define NAME		(string)this_player()->query_name()

#define DEX		(int)query_attack()->query_dexterity()
#define COMBAT		(int)query_attack()->query_combat()

inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("green dragon");
  set_short("an ancient green dragon");

  set_long(
"The green dragon is several hundred feet in length, from tip to tail.\n"+
"It's huge teeth seem razor sharp and its scales as tough as steel. \n"+
"Plumes of toxic gas seem to sprout of its nostrils as it breathes.\n");

  set_race("dragon");
  set_gender(2);
  set_alignment(-500);

  set_level(40);
  add_class("thief");
  add_class("fighter");
  add_class("mage");
  add_class("cleric");

  set_max_hp(1700);
  set_hp(1700);

  set_magic_resist(75);

  load_chat(15, ({
	"Green dragon snores loudly.\n",
  }));

  load_a_chat(5, ({
	"Green dragon slaps her wings.\n",
	"Green dragon cries in pain.\n",
	"Green dragon claws at you.\n",
	"Green dragon lashes out with her huge claws.\n",
	"Green dragon scrapes the walls with her claws.\n",	
	"Green dragon buffets you with her wings.\n",
  }));

  set_attack_msg(({
	"bruises",	"softly with her tail",
	"grazes",	"with her sharp claws",
	"scrapes",	"with her razor claws",
	"crushes", 	"with her huge wings",
	"smashes",	"with her sharp teeth",
	"devestates",	"with her claws",
	"pierces",	"with her teeth",
  }));

  set_dead_ob(this_object());
}

void init() {
  ::init();
  if((int)this_player()->query_level() < 10) {
    tell_object(this_player(), "You flee in terror!\n");
    say(NAME+" flees in terror!\n", this_player());
    this_player()->random_move();
    return;
  }
}

void monster_died() {
  tell_room(environment(),
	query_name()+" drops something as she dies.\n");
  move_object(clone_object(OBJ+"/gem"), this_object());
}

