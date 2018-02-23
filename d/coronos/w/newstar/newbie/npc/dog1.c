/* dog1.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("puppy");
  set_alias("dog");
  set_short("a little puppy");
  set_plural("little puppies");
  set_long(
    "This is a cute, little puppy dog.  His fur is soft and brown,\n"+
    "perfect for petting.  He stares at you with cute, brown eyes\n"+
    "he wags his little tail.  He just wants to play.\n");

  load_chat(5, ({
    "The puppy licks you happily.\n",
    "The puppy wags his little tail.\n",
    "The puppy yips excitedly.\n",
    "The puppy chews on your foot.\n",
    "The puppy runs around the room playfully.\n",
    }));
 
  load_a_chat(40, ({
    "The puppy whines pitifully.\n",
    "The puppy tries to find some place to hide.\n",
    "The pupppy tries to be threatening with his little growls.\n",
    }));
 
  set_attack_msg(({
    "bumped", "clumsily",
    "nudged", "softly with his nose",
    "bat", "with his little paw",
    "grazed", "slightly with his little paw",
    "gnawed", "on the foot",
    "bit", "hard with his teeth",
    "chomped", "on the leg",
    }));
 
  set_al(200);
  set_level(1);
  set_gender(1);
  set_race("canine");
  set_heart_ob(this_object());
 
  if(!present("collar")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/collar"),
    this_object());
    command("wear collar");
  }
}
 


void monster_heart_beat() {
  object food;
 
  if(present("carrot", this_object())) {
   say("The puppy happily munches on the carrot.\n");
   food=(present("carrot", this_object()));
   destruct(food);
   }
}
