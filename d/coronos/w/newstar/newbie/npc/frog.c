/* frog.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>  
inherit MONSTER;
  
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("frog");
  set_short("a frog");
  set_long(
    "This is a little, green frog with brown spots covering its back.\n"+
    "It stares at you with its big, googly eyes.  It is most at home\n"+
    "in the pond by the farm house.\n");
  load_chat(5, ({
    "The frog ribbits at you.\n",
    "The frog hops around happily.\n",
    "The frog stares at you with its big, googly eyes.\n",
    "The frog flicks its tongue out and eats a fly.\n",
    "The frog jumps up really high.\n",
    }));
 
  load_a_chat(40, ({
    "The frog frantically tries to hop away.\n",
   "The frog is startled by the sudden attacks.\n",
    "The frog croaks and ribbits for help.\n",
    }));
 
  set_attack_msg(({
    "missed", "barely",
    "nudged", "softly",
    "bumped into", "softly",
    "hopped onto", "",
    "smacked", "with a webbed foot",
    "jumped into", "",
    "niped", "hard on the hand",
    }));
 
  set_al(150);
  set_level(1);
  set_gender(random(2) + 1);
  set_money(8 + random(8));
  set_race("amphibian");
 
}
