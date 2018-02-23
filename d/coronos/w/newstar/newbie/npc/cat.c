/* cat.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("cat");
  set_alt_name("kitty cat");
  set_alias("kitty");
  set_short("a kitty cat");
  set_plural("kitty cats");
  set_long(
    "This is a fluffy, white kitty cat with big, blue eyes\n"+
    "and a little, pink nose.  Though she looks lazy, she is\n"+
    "actually very quick and agile.\n");
 
  load_chat(5, ({
    "The cat purrs contently.\n",
    "The cat meows plaintively, wanting some attention.\n",
    "The cat pads softly around the room.\n",
    "The cat looks at you calmly, swishing her tail back and forth.\n"
    "The cat swats at passing fly.\n",
    "The cat rubs up against your leg.\n",
    }));
 
  load_a_chat(40, ({
    "The cat meows pitifully.\n",
    "The cat looks very frightend.\n",
    "The cat hisses and spits angrily.\n",
    "The cat arches her back, with raised hackles.\n",
    }));

  set_attack_msg(({
    "nudged", "softly with her nose",
    "bumped", "with her nose",
    "swiped at", "with her paw",
    "scratched", "lightly on the arm",
    "bit", "deep on your leg",
    "raked", "deep with her sharp claws.\n",
    "chomped", "hard with her sharp teeth",
    }));
 
  set_al(200);
  set_level(1);
  set_gender(2);
  add_money(10 + random(14));
  set_race("feline");
 
}
