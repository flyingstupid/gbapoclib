/* duck.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("duck");
  set_alias("bird");
  set_short("a duck");
  set_long(
    "This is a white duck with an orange bill. These birds\n"+
    "love nothing more then to swim around the pond using their\n"+
    "little orange webbed feet.\n");
  load_chat(5, ({
    "A duck quacks at you loudly.\n",
    "A duck swims happily around the pond.\n",
    "A duck waddles along the shore, looking for something to eat.\n",
    "A duck wiggles its tail.\n",
    "A duck flutters its wings and shakes the water off its back.\n",
    }));
 
  load_a_chat(40, ({
    "The duck quacks frantically.\n",
    "The duck tries to fly away.\n",
   "The duck flutters about blindly.\n",
    }));

  set_attack_msg(({
    "bumped", "lightly with its bill",
    "nudged", "softly with its orange bill",
    "buffeted", "with its wings",
    "slapped", "in the face with its wings",
    "nipped", "on the hand",
    "pecked", "on the feet",
    "bit", "hard on the rump",
    }));
 
  set_al(0);
  set_level(1);
  set_plural("ducks");
  set_gender(random(2) + 1);
  set_money(8 + random(8));
  set_race("bird");
 
}
