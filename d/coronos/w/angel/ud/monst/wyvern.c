#include <mudlib.h>

#define OBJ		"d/coronos/w/angel/ud/obj"
#define NAME		(string)this_player()->query_name()

#define DEX		(int)query_attack()->query_dexterity()
#define COMBAT		(int)query_attack()->query_combat()

inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("wyvern");
  set_short("A huge wyvern");

  set_long(
"This horrible, huge black creature, akin to a small dragon, \n"+
"has a very long tail with a sharp point on it's end like a  \n"+
"scorpion. The whole beast looks very frightenning.\n");
  set_race("wyvern");
  set_alias("dragon");
  set_gender(2);
  set_alignment(-200);

  set_aggressive(1);
  set_level(30);
  add_class("thief");
  add_class("fighter");
  set_max_hp(2000);
  set_hp(2000);

  set_magic_resist(75);

  load_chat(5, ({
	"Wyvern glances at you with casual regard.\n",
	"Wyvern stretches her wings.\n",
	"Wyvern looks at you with red eyes.\n",
	"Wyvern ignores you.\n",
  }));

  load_a_chat(5, ({
	"Wyvern glaps her wings.\n",
	"Wyvern cries in pain.\n",
	"Wyvern claws at you.\n",
	"Wyvern lashes out with her tail.\n",
	"Wyvern scrapes the walls with her claws.\n",	
	"Wyvern screaches out.\n",
  }));

  set_attack_msg(({
	"bruises",	"softly with her tail",
	"grazes",	"with her sharp claws",
	"scrapes",	"with her razor claws",
	"crushes", 	"with her huge wings",
	"smashes",	"with her sharp teeth",
	"devestates",	"with her claws",
	"pierces",	"with her tail",
  }));

  set_heart_ob(this_object());
  set_dead_ob(this_object());
}

void monster_heart_beat() {
  object ob;
  if(!query_attack()) return;

  if((random(DEX) + random(COMBAT)) < random(query_wc())) {
    if(query_attack()->query_spell_immune("poison")) {
      tell_object(query_attack(), 
	"Wyvern pierces your body with her tail, but you resist the poison.\n");
    }
    else {
      if(present(query_attack()))
      if(!present("Poison", query_attack())) {
        tell_object(query_attack(),
        	"Wyvern poisons you as she stabs you with her tail!\n");
        ob = clone_object("objects/poison");
        move_object(ob, query_attack());
        ob -> init();
      }
    }
    say("Wyvern pierces "+query_attack()->query_name()+" through the body with "+
	"her tail!\n", query_attack());
    query_attack()->adj_hp(-10 + random(20));
  }
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

