/* rat.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("rat");
  set_short("a dirty rat");
  set_long(
    "This is a filty dark gray rat with a long pink tail.\n"+
    "Its has a long pointed nose with lots of whiskers and.\n"+
    "glares at you with its beady red eyes.  The smug look\n"+
    "on its face makes you think its been up to no good.\n");
 
  load_chat(5, ({
    "A rat scrurries across the ground.\n",
    "A rat sniffs the air.\n",
    "A rat glares at you with its beady red eyes.\n",
    "A rat chews on its foot.\n",
    "A rat squeaks annoyingly.\n",
    }));
 
  load_a_chat(40, ({
    "The rat squeals in fright.\n",
    "The rat scrurries about in alarm.\n",
    "The rat frantically tries to run away.\n",
    }));
  set_attack_msg(({
    "nudged", "softly with its nose",
    "bumped", "lightly with its paw",
    "grazed", "on the ankle",
    "scratched", "on the leg",
    "nibbled", "hard on the ear",
    "bit", "deep with its teeth",
    "chomped", "painfully on the hand",
    }));
 
  set_al(-150);
  set_level(1);
  set_gender(random(2) + 1);
  set_money(10 + random(10));
  set_race("rat");
}
