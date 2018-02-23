#include <mudlib.h>
inherit MONSTER;


object hat;
void reset(status arg) {
  ::reset(arg);

  if(!hat) {
    hat = clone_object(CLOTHING);
    hat -> set_name("hat");
    hat -> set_short("A sailor's hat");
    hat -> set_long(
        "A simple cotton hat, in the design that sailors wear to keep \n"+
        "the sun off their heads while on long sea voyages. \n");
    hat -> set_weight(1);
    hat -> set_value(100);
    move_object(hat, this_object());
  }
  init_command("hat");

  if(arg) return;
  set_name("sailor");
  if(!random(2))
    set_alignment(-(random(100)));
  else
    set_alignment(random(100));


  set_level(13);
  set_short("A fine sailor");
  set_long(
        "Dressed in typical sailor atire, this sailor has spent long \n"+
        "days at sea. The sailor looks very weary, and weathered, from\n"+
        "swabbing the decks of the Bounty, climbing the rigging, fixing\n"+
        "the nets, and defending the ship. While the sailor is strong, \n"+
        "the Captain, Bligh, is stronger still.\n");
  set_gender(random(2)+1); /* random gender */
  load_chat(10,({ "Sailor says: Avast there.\n",
        "Sailor smirks.\n",
        "Sailor says: Ho there, land lubber.\n",
        "Sailor watches the waves with loving eyes.\n",
        "Sailor watches you.\n",
  }));
  load_a_chat(10,({ "Sailor exclaims: Captain Bligh! Mutiny!\n",
        "Sailor exclaims: Mutiny, mutiny!\n",
  }));
  add_class("thief");
  set_steal_chance(50);
  add_class("fighter");
  add_class("cleric");
  load_spells(40, ({ "cure light wounds", "bless", "curse", }));
}
