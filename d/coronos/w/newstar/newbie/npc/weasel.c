/* weasel -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("weasel");
  set_short("a sneaky weasel");
  set_long(
    "This is crafty little weasel with black beady eyes.\n"+
    "Its has sleak brown fur with white on the underside\n"+
    "and tip of the tail.  Its long, lean body makes it\n"+
    "look very agile.\n");
 
  load_chat(5, ({
    "A weasel chitters at you.\n",
    "A weasel sniffs the air.\n",
    "A weasel glares at you.\n",
    "A weasel scampers across the ground.\n",
    "A weasel licks its chops hungrily.\n",
    }));
 
  load_a_chat(40, ({
    "The weasel squeals in anger.\n",
    "The weasel chitters angrily.\n",
    "The weasel bares its little fangs in full fury.\n",
    "The weasel bristles in rage.\n",
    }));
  set_attack_msg(({
    "nudged", "softly with its nose",
    "bumped", "firmly with its paw",
    "batted at", "with a paw",
    "scratched", "on the leg",
    "nipped", "hard on the arm",
    "bit", "deep with its sharp teeth",
    "chomped", "viciously on the hand",
    }));
 
  set_al(-200);
  set_level(1);
  set_gender(random(2) + 1);
  set_money(10 + random(9));
  set_race("weasel");
 
}
