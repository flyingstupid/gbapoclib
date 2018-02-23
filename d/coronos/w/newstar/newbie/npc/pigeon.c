/* pigeon.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("pigeon");
  set_alias("bird");
  set_short("a pigeon");
  set_long(
    "This is a pigeon with grey and black feathers.  A few streaks of\n"+
    "white can also be seen on the wings.  Its beak and feet are bright\n"+
    "orange-red.\n");
  load_chat(5, ({
    "A pigeon flutters its wings.\n",
    "A pigeon pecks at the ground.\n",
    "A pigeon walks around, bobbing its head.\n",
    "A pigeon grooms its feathers carefully with its beak.\n"
    "A pigeon coos at you softly.\n",
    }));
 
  load_a_chat(40, ({
    "The pigeon coos with fright and tries to fly away.\n",
    "The pigeon flaps its wings frantically.\n",
    "The pigeon flutters around on the ground helplessly.\n",
    }));
 
  set_attack_msg(({
    "bumped", "with its beak",
    "nudged", "with its beak",
    "buffeted", "around the head with its wings",
    "whacked", "in the face",
    "slapped", "sharply with a wing",
    "pecked at", "with its beak",
    "bit", "hard on the hand",
    }));
 
  set_al(0);
  set_level(1);
  set_plural("pigeons");
  set_gender(random(2) + 1);
  set_money(8 + random(9));
  set_race("bird");
 
}
