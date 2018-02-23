/* raven.c -- newbie */
/* Darkness and Nwstar */

#include <mudlib.h>    
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("raven");
  set_alias("bird");
  set_short("a black raven");
  set_long(
    "This is a coal black raven.  Its feathers are ragged\n"+
    "and its talons are sharp.  It watches you with a cruel\n"+
    "glint in its inkling eyes.  \n");
 
  load_chat(5, ({
    "A raven glares at you with its black eyes.\n",
    "A raven tilts its head to one side.\n",
    "A raven flaps its wings and caws loudly.\n",
    "A raven hops along the ground, pecking at it every so often.\n",
    "A raven flutters over to you and pecks at your foot.\n",
   }));
 
  load_a_chat(40, ({
    "The raven caws furiously.\n",
    "The raven flaps its wings furiously.\n",
    "The raven screeches in anger and tries to fly away.\n",
    }));
  set_attack_msg(({
    "dove straight at", "but missed",
    "buffeted", "with its wings",
    "slapped", "with a wing",
    "flew into", "with full force",
    "pecked", "on the head",
    "scratched", "with its sharp talons",
    "bit", "hard with its black beak",
    }));
 
  set_al(-200);
  set_level(1);
  set_gender(random(2) + 1);
  set_money(9 + random(9));
  set_race("bird");
 
}
