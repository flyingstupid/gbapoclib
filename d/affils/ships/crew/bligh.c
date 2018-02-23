#include <mudlib.h>
inherit MONSTER;

void make_equipment();
void reset(status arg) {
  ::reset(arg);
  if(arg) {
    make_equipment();
    return;
  }

  set_name("captain");  
  set_name("bligh");
  set_alt_name("captain bligh");
  set_short("Captain Bligh");
  set_long(
     "Captain Bligh has been the captain of the Bounty since it \n"+
     "was built early last century. He is a sturdy man, in his mid\n"+
     "forties, and has a wide grin and a sparkle of youth in his   \n"+
     "eyes. ");
  set_race("human");
  set_level(20); 
  set_gender(1);
  set_magic_resist(25);
  add_spell_immunity("fire");
  add_spell_immunity("death");
  add_spell_immunity("lightning");
  add_spell_immunity("drain");
  add_class("fighter");
  add_class("mage");
  add_class("cleric");
  set_spell(({
     "lightning bolt", "fire ball", "chill touch", "ice storm",
     "cure light wounds", "cure serious wounds", "cure critical wounds",
     "bless", "curse", "stone skin", "fire shield", "hold person",
     "vampiric touch",
  }));

  load_chat(5, ({ "Bligh exclaims: Shiver me timbers!\n",
     "Bligh says: Yo-ho-ho and a bottle of rum.\n",
     "Bligh says: Fifteen men on a dead man's chest.\n",
     "Bligh says: Avast me hearties.\n",
     "Bligh smiles happily.\n",
  }));

  load_a_chat(8, ({ "Bligh says: I'll kill ye.\n",
     "Bligh says: You drunken scum.\n",
     "Bligh says: You land lubber.\n",
     "Bligh exclaims: Mutiny!\n",
  }));
  make_equipment();
}

void make_equipment() {
  object ob;

  if(!present("key")) {
    ob = clone_object(TREASURE);
    ob -> set_name("iron key");
    ob -> set_alias("key");
    ob -> set_short("An iron key");
    ob -> set_long(
			"An old rusty iron key.\n");
    ob -> set_weight(1);
    ob -> set_sell_destruct(1);
    ob -> set_value(10);
    move_object(ob, this_object());
  }

  if(!present("rapier")) {
    ob = clone_object(WEAPON);
    ob -> set_wc(15);  /* +3 rapier */
    ob -> set_length(48);
    ob -> set_type("slash");
    ob -> set_weight(6);
    ob -> set_value(2600);
    ob -> set_name("rapier");
    ob -> set_short("A fine rapier");
    ob -> set_long(
     "This fine rapier is made from a blue tinged metal and has a guard \n"+
     "and hilt of gold in the shape of a sea serpent. At the end of the \n"+
     "hilt is an oval blue emerald. \n");
    move_object(ob, this_object());
    command("wield rapier");
    set_wc(25);
  }

  if(!present("uniform")) {
    ob = clone_object(CLOTHING);
    ob -> set_weight(1);
    ob -> set_name("uniform");
    ob -> set_short("A sea captain's uniform");
    ob -> set_long(
     "This uniform is made from fine blue cotton in the design of the \n"+
     "Tempus navy. A golden yanyard hangs from the left lapel which are \n"+
     "decorated with golden tasles. \n");
    ob -> set_value(100);
    move_object(ob, this_object());
    command("wear uniform");
  }
}

void catch_tell(string str) {
}
