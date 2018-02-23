#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  object ob1, ob2;
  ::reset(arg);

  if(!present("axe")) {
    ob1 = clone_object("d/coronos/w/angel/city/obj/baxe");
    move_object(ob1, this_object());
    init_command("wield axe");
  }

  if(!present("armour")) {
    ob2 = clone_object("d/coronos/w/angel/city/obj/leather");
    move_object(ob2, this_object());
    init_command("wear leather");
  }

  set_wc(35);
  set_ac(20);

  if(arg) return;

  set_name("karak");
  set_short("Karak, the minotaur");
  set_long(
	"Karak is a large, hulking beast of a minotaur, standing over \n"+
	"seven feet tall, and weighing over 250 pounds. While his     \n"+
	"brutish manorisms may seem offensive, Karak is really quite  \n"+
	"a nice minotaur at heart; when he is not angry.\n"+
	"Karak is a member of the Black Guard\n");

  set_race("minotaur");
  set_gender(1);
  set_level(30);
  set_max_hp(1700);
  set_hp(1700);
  set_wc(35);
  set_ac(20);

  set_magic_resist(75);
  add_spell_immunity("fire");
  add_spell_immunity("lightning");
  add_spell_immunity("death");

  add_class("fighter");
  add_class("cleric");
  add_class("thief");

  load_spells(75, ({ "bless", "curse", "fire storm",
	"earthquake", "call lightning", "cause light wounds",
	"heal", "harm", "cause serious wounds",
	"cure light wounds",
	"cure serious wounds", 
	"cure critical wounds",
	"cause blindness", "hold person", "charm person",
  }));

  load_chat(10, ({ "Karak asks: Hab eu seem big Kerzon human?\n",
	"Karak says: You little person.\n",
	"Karak asks: Why eu wook so little?\n",
	"Karak asks: Where is Kerzon human?\n",
	"Karak says: I hab lost Kerzon human.\n",
	"Karak looks around.\n",
	"Karak sniffs.\n",
  }));

  load_a_chat(10, ({ "Karak says: Me angry now.\n",
	"Karak says: You bad person.\n",
	"Karak says: Me not like eu now.\n",
	"Karak says: Ouch, you hurt'd me.\n",
  }));
  set_wander(90, 1000);
  set_wimpy(200);
}

