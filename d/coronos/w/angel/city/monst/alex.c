#include <mudlib.h>
#define OBJ		"d/coronos/w/angel/city/obj/"
inherit MONSTER;

object rapier, hat, chain;
void reset(status arg) {
  ::reset(arg);

  if(!present("chainmail")) {
    chain = clone_object(OBJ+"elfch");
    move_object(chain, this_object());
  }
  if(!present("rapier")) {
    rapier = clone_object(OBJ+"rapier1");
    move_object(rapier, this_object());
  }
  if(!present("rapier 2")) {
    rapier = clone_object(OBJ+"rapier2");
    move_object(rapier, this_object());
  }

  if(!present("hat")) {
    hat = clone_object(CLOTHING);
    hat -> set_name("hat");
    hat -> set_short("A large feathered hat");
    hat -> set_long(
	"This hat has a huge plume of feathers sprouting\n"+
	"from its brim of royal blood reds and golds. It\n"+
	"is the hat of a rich nobleman.\n");
    hat -> set_weight(1);
    hat -> set_value(1000);
    move_object(hat, this_object());
  }

  set_level(75);
  set_name("alexander");
  set_short("Lord Alexander Celestian");
  set_gender(1);
  set_race("human");
  set_long(
"The simple sight of Alexander commands respect.\n"+
"He has a presence that all feel as he enters a \n"+
"room. Some say it is due to the company he has \n"+
"kept all these years, but some rumours persist \n"+
"(much to his displeasure) that he abuses some  \n"+
"magical item to this end. Alexander has golden \n"+
"brown eyes, long blonde hair that spills to his\n"+
"shoulders, and a smile that always brings cheer\n"+
"into the hearts of those he meets. His smile  \n"+
"is as youthful as a childs, and his manorism  \n"+
"friendly, but you cant help but think he looks\n"+
"like a 'spanish peacock. Alexander is has the office\n"+
"of diplomatic co-ordinator within The Circle.\n");

  add_class("fighter");
  add_class("mage");
  add_class("cleric");
  add_class("thief");
  set_alignment(500);
  set_magic_resist(200);

  load_chat(5, ({
"Alexander smiles happily\n",
"Alexander polishes his rapier.\n",
"Alexander says: Greetings to your, fair ciizen.\n",
"Alexander preens the feather in his hat.\n",
"Alexander asks: From where do you hail?\n",
"Alexander asks: Do you follow the great Bahamut?\n",
"Alexnder smiles brightly.\n",
"Alexander preens his mostache.\n",
"Alexander says: Greetings.\n",
"Alexander says: Is this your first time here?\n",
  }));

 load_a_chat(5, ({
"Alexander parries your blows.\n",
"Alexander says: My faith is stronger than yours.\n",
"Alexander prays to Bahamut.\n",
  }));

    init_command("wear chainmail");
    init_command("wield rapier");
    init_command("wield rapier");
    init_command("wield rapier 2 in left hand");
    init_command("wear hat");

    set_wc(60);
    set_ac(40);

}

status query_no_steal() { return 1; }
