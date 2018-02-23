/* pony.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("pony");
  set_alias("horse");
  set_short("a pony");
  set_long(
    "This is a little, cream-coloured pony with a white mane\n"+
    "and tail.  His rolly-polly body and short, little legs\n"+
    "fit his jolly demeanor perfectly.\n");
 
  load_chat(5, ({
    "The pony trots around merrily.\n",
    "The pony neighs in greeting.\n",
    "The pony twitches his ears toward you expectantly.\n",
    "The pony nudges you, looking for something sweet to eat.\n",
    "The pony snorts happily.\n",
    "The pony looks at you with liquid, brown eyes.\n",
    "The pony tosses his head.\n",
    }));
 
  load_a_chat(6, ({
    "The pony neighs frightendly.\n",
    "The pony rears in alram.\n",
    }));
  set_attack_msg(({
    "nudges", "softly with his nose",
    "bumps", "with his nose",
    "nudges", "with a hoof",
    "kicks", "with his hoof",
    "bites", "with his teeth",
    "kicks", "hard with his hind legs.\n",
    "bites", "deep with his teeth",
    }));
 
  set_al(200);
  set_level(1);
  set_gender(1);
  set_race("horse");
  set_heart_ob(this_object());
}



void monster_heart_beat() {
  object food;
 
  if(present("some hay", this_object())) {
   say("The pony happily munches on the hay.\n");
   food=(present("some hay", this_object()));
   destruct(food);
   }
 
  if(present("carrot", this_object())) {
   say("The pony happily munches on the carrot.\n");
   food=(present("carrot", this_object()));
   destruct(food);
   }
 
}

