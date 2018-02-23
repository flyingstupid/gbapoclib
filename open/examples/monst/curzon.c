#include <mudlib.h>

inherit MONSTER;

void reset(status arg) {
  object ob;
  int I;

  ::reset(arg);

  if(!present("longsword")) {
    for(I=0; I<2; I++) {
      ob = clone_object("d/coronos/w/angel/city/obj/lsword");
      move_object(ob, this_object());
    }
  }


  set_name("curzon");
  set_gender(1);
  set_race("half elf");

  set_short("Curzon Bain, leader of the Black Guard");
  set_long(
	"Curzon is a seasoned fighter, and leader of the elite black, \n"+
	"guard whose duty it is to guard the members of The Circle.   \n"+
"Curzon has scars down the left side of his face, and an eye  \n"+
"patch to cover his injured eye. His hair and beard are dark  \n"+
"black and long, indicating his his human heritage. His       \n"+
"prefered dress is clearly black and dark tones.\n");
  load_chat(5, ({
	"Curzon nods solemnly.\n",
	"Curzon looks at you.\n",
	"Curzon asks: What are you here for?\n",
	"Curzon says: There are no better fighters than the black guard.\n",
	"Curzon asks: Are you looking to join the black guard?\n",
	"Curzon grumbles.\n",
	"Curzon wonders if it is time for dinner.\n",
  }));

  load_a_chat(10, ({
	"Curzon says: I am better than you.\n",
	"Curzon grumbles.\n",
	"Curzon growls.\n",
	"Curzon expertly parries your blow.\n",
  }));

  set_level(45);
  set_ac(17);
  add_spell_immunity("charm");
  add_spell_immunity("fire");
  add_spell_immunity("lightning");
  add_spell_immunity("death");
  set_magic_resist(200);
  init_command("wield longsword");
  init_command("wield longsword 2 in left hand");

  add_class("fighter");
  add_class("cleric");
  load_spells(15, ({ "cure serious wounds", "heal", "curse", "bless",
	"sts", "cure light wounds", "flame strike", "call lightning",
	"holy word", "holy strike", "meteor swarm", "slay living",
	"harm", "earthquake",
	"cure wounds", "resist cold", 
  }));
}

