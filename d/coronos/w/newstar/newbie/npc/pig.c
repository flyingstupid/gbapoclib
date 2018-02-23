/* pig.c -- newbie */
/* Darkness and Newtar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("pig");
  set_short("a pink pig");
  set_long(
    "This is a little, pink pig with a cork screw tail.\n"+
    "This oinker has a plump, round body and likes nothing\n"+
    "more then to lazy the day away.\n");
 
  load_chat(5, ({
    "A pig eats messily from the trough.\n",
    "A pig oinks softly.\n",
    "A pig snuffles around at the ground.\n",
    "A pig trots around the yard.\n",
    "A pig wallows delightedly in the mud.\n",
    }));
 
  load_a_chat(40, ({
    "A pig squeals in anguish.\n",
    "A pig tries to find a place to hide.\n",
    "A pig runs around, trying to get away.\n",
    }));
  set_attack_msg(({
    "nudged", "softly with its snout",
    "bumped", "lightly with its snout",
    "ran into", "",
    "stepped on", "with a hoof",
    "grazed", "with its hoof",
    "bit", "on the leg",
    "chomped", "hard on the foot",
    }));
 
  set_al(0);
  set_level(1);
  set_plural("pink pigs");
  set_gender(random(2) + 1);
  set_money(9 + random(10));
  set_race("pig");
  set_heart_ob(this_object());
}



void monster_heart_beat() {
  object food;
 
  if(present("carrot", this_object())) {
   say("The pig gobbles up the carrot.\n");
   food=(present("carrot", this_object()));
   destruct(food);
   }
}
