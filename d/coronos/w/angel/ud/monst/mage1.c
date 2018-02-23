#include <mudlib.h>
#define OBJ "d/coronos/w/angel/ud/obj"

inherit MONSTER;


object bag, gem;
object robe, dagger;
status initialised;

void make_items();

void reset(status arg) { 
  ::reset(arg);



  initialised = 0;
  if(arg) return;

  set_name("mage");
  set_level(40);
  set_gender(1);
  set_short("A drow mage");
  set_long(
	"Before you stands a drow mage of the House of Noquar. While \n"+
	"but a drow male, he has not advanced this far in his ranks to be  \n"+
	"quietly defeated by just any foe. \n");
    

  set_alias("drow");
  set_race("dark elf");

  load_l_chat(5, "elf", ({
    "I wish the dark elves would not make war with the surface dwellers",
    "Tell me, fair traveller. Do you know the ways of magic?",
    "There will be a war soon, between Noquar and Ille Coronos",
    "Bewary of Di'Illan. He is not what he appears to be",
    "The kobold likes scorpion claws. Why don't you befriend him with one?",
    "I see you understand what I mean, young traveller?",
  }));



  add_class("fighter");
  add_class("thief");
  add_class("mage");
  set_magic_resist(95);
  load_spells(30, ({
    "chill touch", "sbf", "death spell", "minor malison", 
    "animate skeleton", "animate zombie", 
    "shadow door",
    "magic missile", "fire rain", "fire ball", "shield", 
    "acid arrow", "energy drain", "hold person",
    "monster summon 1", "monster summon 2", "monster summon 3",
    "enlarge", "contagion", 
    "demand south", "scare", "demand north", "demand east", "demand west",
    "cone of cold",
    "globe of invulnerability",
    "lightning bolt", "fod", "pwk", "pws", "disintegrate",
    "chain lightning", "fire shield", 

  }));
  add_spell_immunity("charm");
  add_spell_immunity("fire");
  add_spell_immunity("death");
}

void init() {
  ::init();
  if(!initialised) make_items();
}

void make_items() {
  int i;

  initialised = 1;
  if(!present("robe")) {
    robe = clone_object(CLOTHING);
    robe -> set_short("a black robe");
    robe -> set_weight(1);
    robe -> set_long(
        "A finely woven black silk robe. From the runes \n"+
        "on the hem you assume it belonged to a wizard.\n");
    robe -> set_value(100 + random(100));
    move_object(robe, this_object());
  }

  if(!present("dagger")) {
    dagger = clone_object(OBJ+"/dagger");
    move_object(dagger, this_object());
  }

  if(!present("bag")) {
    bag = clone_object("objects/bag");
    move_object(bag, this_object());
    bag -> set_name("bag");
    bag -> set_short("A soft leather bag");
    bag -> set_long(
        "This small leather bag has been fashioned from Minotaur hide\n"+
        "and while very tough it is soft to the touch.\n");

    for(i=0; i<6; i++) {
      gem = clone_object("objects/components/gem");
      move_object(gem, bag);
    }
  }
  
  init_command("wield dagger");
  set_wc(30);

}
