#include <mudlib.h>
#define OBJ		"d/coronos/w/angel/city/obj"

inherit MONSTER;

object ob;
void reset(status arg) {
  ::reset(arg);

  if(arg) return;

  set_name("damon");
  set_short("Lord Damon Portheos, master wizard");

  set_long(
"Damon is the chancellor of the University of Power within the city  \n"+
"of Ille Coronos. Damon has long shoulder length hair, kept neat and \n"+
"tidy, a trimmed moustache, and is in good condition considering that\n"+
"he is in his mid forties. His rich clothing indicate he is someone  \n"+
"of considerable wealth, and his standing, not only within the city, \n"+
"but also within the magical community.\n"+
"Damon is a White Robe mage\n");

  set_heart_ob(this_object());
  set_level(60);
  set_max_hp(2000);
  set_hp(2000);
  set_gender(1);
  add_money(1000);
  set_race("human");
  set_wc(30);
  set_ac(18);

  add_class("mage");
  add_class("cleric");
  set_magic_resist(100);
  add_spell_immune("fire");
  add_spell_immune("death");
  load_spells(80, ({
	"heal", "cure light wounds", "bless", "cure serious wounds",
	"enlarge", "magic missile", "dispel magic", "hold person",
	"fod", "disintegrate", "death spell", "fire shield",
	"ice storm", "contagion", "mks", "meteor swarm", "pwk",
	"hold monster", "fire ball", "lightning bolt", "comet",
  }));

  load_chat(6, ({
	"Damon says: I dont have time for you.\n",
	"Damon asks: Can you make an appointment?\n",
	"Damon scratches his head.\n",
	"Damon says: What are you doing here anyhow?\n",
	"Damon looks at you seriously.\n",
	"Damon wonders about a complex magical formulae.\n",
	"Damon looks at his staff happily.\n",
	"Damon says: You're not one of my students.\n",
  }));

  load_a_chat(5, ({
	"Damon says: You will never get away with this.\n",
  	"Damon says: The black guard will hear about this.\n",
	"Damon asks: What are you doing?\n",
  }));

  set_wimpy(100);
  set_wander(50, 600);
  set_domain("univ");
}


void init() {
  ::init();
  if(!ob) {
    ob = clone_object(OBJ+"/somagi");
    move_object(ob, this_object());
    init_command("wield staff");
    set_wc(30);
  }
}

status query_no_fight() { return 1; }

void monster_heart_beat() {
  if(!random(20) && query_attack()) {
    this_object()->heal_mage(100);
    adj_hp(100);
   tell_room(environment(), "Damon activates his staff, and is revitalized!\n");
  }
}
