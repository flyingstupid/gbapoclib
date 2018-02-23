/* goat.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("goat");
  set_short("a billy goat");
  set_long(
    "This is a young billy goat with coarse white fur and a\n"+
    "little goatie.  His horns are short but strong.  He looks\n"+
    "awefully mean, so don't turn your back on him.\n");
  load_chat(5, ({
    "The goat walks around.\n",
    "The goat goes 'Maaaaaaa'.\n",
    "The goat watches you warily.\n",
    "The goat eats something off the ground.\n",
    "The goat bleats at you.\n",
    "The goat sniffs at your foot.\n",
    }));
 
  load_a_chat(40, ({
    "The goat glares furiously.\n",
    "The goat bleats in anger.\n",
    "The goat paws at the ground with a hoof.\n",
    }));
 
  set_attack_msg(({
    "nudged", "softly with his nose",
    "grazed", "with his hoof",
    "charged at", "with lowered horns",
    "rammed", "in the rump",
    "bit", "with his teeth",
    "butted", "in the stomach with his horns",
    "bit", "deep with his teeth",
    }));
 
  set_al(0);
  set_level(1);
  set_gender(1);
  set_plural("billy goats");
  set_money(10 + random(10));
  set_race("goat");
  set_heart_ob(this_object());
 
}



void monster_heart_beat() {
  object food;
 
  if(present("some hay", this_object())) {
   say("The goat quickly eats up some hay.\n");
   food=(present("some hay", this_object()));
   destruct(food);
   }
 
  if(present("carrot", this_object())) {
   say("The goat quickly eats up the carrot.\n");
   food=(present("carrot", this_object()));
   destruct(food);
   }
}
