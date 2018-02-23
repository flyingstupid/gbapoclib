/* canary.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("canary");
  set_alias("bird");
  set_short("a canary");
  set_plural("canaries");
  set_long(
    "This is a little, pet canary that belongs to the farmer's\n"+
    "wife.  The feathers are a bright, lemon yellow except for\n"+
    "the stomach, which is white.  These birds love to sing all\n"+
    "day long.\n");
  load_chat(5, ({
    "A canary sings a sweet song as loud as it can.\n",
    "A canary flutters around.\n",
    "A canary looks at you and chirps cheerfully.\n",
    "A canary preens its feathers carefully.\n",
    "A canary stretches its wings.\n",
   }));
 
  load_a_chat(40, ({
    "The canary chirps in alarm.\n",
    "The canary frantically tries to fly away.\n",
    "The canary flutters around helplessly.\n",
    }));

  set_attack_msg(({
    "dove at", "",
    "wings buffeted", "in the face",
    "slapped", "with a wing",
    "scratched", "lightly on the hand",
    "flew into", "with full force",
    "pecked", "on the head",
    "bit", "with its beak",
    }));
 
  set_al(200);
  set_level(1);
  set_gender(random(2) + 1);
  set_race("bird");
}
