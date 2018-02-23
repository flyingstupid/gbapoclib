#include <mudlib.h>

inherit MONSTER;
object food;

void reset(status arg) {
  ::reset(arg);

  if(!present("pigeon food")) {
    food = clone_object(FOOD);
    food -> set_short("A bag of pigeon food");
    food -> set_name("pigeon food");
    food -> set_alias("food");
    food -> set_strength(10);
    move_object(food, this_object());
  }

  if(arg) return;

  set_name("igiloo");
  set_short("Igiloo, the gnome");
  set_long(
    "With a name that is far too long to pronounce by normal people, \n"+
    "Igiloo has adopted a human name to save confusion. Igiloo is an \n"+
    "inventor or sorts, as many gnomes are, but on her off she likes  \n"+
    "to feed the pigeons within the city of Ille Coronos. While \n"+
    "innocent looking, she looks well trained in the arts of battle.\n");
  set_gender(2);
  set_race("gnome");
  set_level(10);


  add_class("thief");
  add_class("cleric");
  add_class("fighter");

  set_magic_resist(25);

  load_spells(25, ({
	"cure wounds", "cure light wounds",
	"bless", "curse",
  }));

  load_chat(10, ({
    "Igiloo says: I like this pigeon.\n",
    "Igiloo asks: Do you like this pigeon?\n",
    "Igiloo says: I made a pigeon feeder once.\n",
    "Igiloo smile happily.\n",
    "Igiloo feeds the pigeons.\n",
    "Igiloo says: Want to feed the pigeons with me?\n",
    "Igiloo smiles because her nose is bigger than yours.\n",
    "Igiloo says: I wonder when the nose measuring competitions are on?\n",
  }));
}


