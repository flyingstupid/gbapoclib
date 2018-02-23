/* rabbit.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("rabbit");
  set_short("a rabbit");
  set_long(
    "This is a little furry brown rabbit.  It has a fluffy white\n"+
    "tail, long pointy ears, and soft brown eyes.  It just loves\n"+
    "to steal the vegetables from the farmer's garden.\n");
 
  load_chat(5, ({
    "A rabbit wiggles its nose at you.\n",
    "A rabbit hops around happily.\n",
    "A rabbit looks around and sniffs the air.\n",
    "A rabbit munches on some vegetables.\n",
    "A rabbit stands motionless and listens carefully.\n",
    }));
 
  load_a_chat(40, ({
    "The rabbit squeals with fright.\n",
    "The rabbit tries to run away.\n",
    "The rabbit thumps its hindleg on the ground to warn the others.\n",
    }));
 
  set_attack_msg(({
    "bumped", "with its nose",
    "nudged", "with its paw",
    "grazed", "slightly on the arm",
    "scratched", "on the leg",
    "bit", "with its teeth",
    "raked", "deep with its claws",
    "bit", "hard on the foot",
    }));
 
  set_al(0);
  set_level(1);
  set_plural("rabbits");
  set_gender(random(2) +1);
  set_money(2 + random(10));
  set_race("rabbit");
  set_heart_ob(this_object());
 
}



void monster_heart_beat() {
  object food;
 
  if(present("carrot", this_object())) {
   say("The rabbit nervously crunches on the carrot.\n");
   food=(present("carrot", this_object()));
   destruct(food);
   }
}
