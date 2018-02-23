#include <mudlib.h>

inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
if (arg) return;
set_name("Detective Joe Friday");
set_alias("joe");
  set_gender(1);
set_race("Californian");

set_short("Detective Joe Friday");
  set_long(
"Detective Joe Friday is a veteran whom nothing surprises anymore.\n"+
"His dry, sarcastic sense of humor is surpassed only by his strange\n"+
"and inexplicable speech patterns. Nevertheless, he is a sharp and\n"+
"formidable opponent to wrongdoers in Ille Coronos.\n");
  load_chat(5, ({
"Joe Friday checks with his boss on a case.\n",
"Joe Friday says: 'Just the facts, ma'am.' I LOVE saying that!\n",
"Joe Friday dunks his doughnut in his coffe.\n",
"Detective Friday says: Ille Coronos is a cesspool of crime,\n"+
"and it's my intent to clean it up.\n",
"Joe Friday says: The young people of today make me sad, with \n"+
"with their long hair and beatnik ways!\n",
"Joe Friday says: It was Colonel Mustard, in the Conservatory,\n"+
"with the lead pipe!\n",
"Joe Friday says: Just say NO to drugs!\n",
"Joe Friday paces the floor, waiting for a lead to come in.\n",
  }));

  load_a_chat(10, ({
"You're no better than the rest of the vermin in this town.\n",
"Joe Friday says: You're in a world of trouble now, mister!\n",
"Joe Friday says: Does your mother know what you've become?\n",
"You powers are weak, old man!  At last the circle is complete....\n",
"Detective Friday says: Do you know what happens when you kill a cop?\n",
"Detective Friday says: I fought the Germans in the Great War,\n"+
"and you are no German.\n",
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

