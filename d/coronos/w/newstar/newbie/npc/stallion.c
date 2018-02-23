/* stallion.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("stallion");
  set_short("a black stallion");
  set_long(
    "This is a large, black stallion.  His coat is well groomed and shiny,\n"+
    "and his mane is brushed and healthy. He is a mature stallion, at the\n"+
    "prime of his life.  Lean and muscular, he is the pride of the farm.\n");
 
   load_chat(5, ({
    "The stallion's nostrils flare.\n",
    "The stallion snorts as it nods his head up and down.\n",
    "The stallion rears up onto his hind legs and whinnies.\n",
    "The stallion munches on some hay.\n",
    }));
 
  load_a_chat(40, ({
    "The stallion snorts furiously.\n",
    "The stallion rears up and whinnies loudly.\n",
    "The stallion dances around gracefully.\n",
    }));
 
  set_attack_msg(({
    "missed", " ",
    "nudged", "with his nose",
    "butted", "with his head",
    "kicked", " ",
    "kicked", "hard with his hind legs",
    "trampled", " ",
    "sent", "flying across the room with a good kick",
    }));
 
  set_al(0);
  set_level(8);
  set_wc(11);
  set_ac(6);
  set_max_hp(130);
  set_hp(130);
  set_gender(1);
  set_plural("black stallions");
  set_money(300 +random(50));
  set_race("horse");
  add_class("fighter");
  set_heart_ob(this_object());
 
}


 
void monster_heart_beat() {
  object food;
 
  if(present("carrot", this_object())) {
   say("The stallion eats up the carrot in large chomps.\n");
   food=(present("carrot", this_object()));
   destruct(food);
   }
 
 if(present("some hay", this_object())) {
   say("The stallion eats up some hay in large chomps.\n");
   food=(present("some hay", this_object()));
   destruct(food);
   }
}
