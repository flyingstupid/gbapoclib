/* mare.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("mare");
  set_alias("horse");
  set_short("a gray mare");
  set_long(
    "This is a lovely speckled gray mare.  Her long flowing mane and\n"+
    "tail are jet black, as are her long slender legs.  Her smooth body\n"+
    "is sleek and elegant with a slim, arching neck.  She is definitely\n"+
    "built for speed and prized for her beauty.\n");
  load_chat(5, ({
    "A mare nickers softly.\n",
    "A mare regards you calmly.\n",
    "A mare nuzzles your arm, wanting some attention.\n",
    "A mare lowers her head and snorts softly.\n",
    "A mare lifts her head and twitches her ears toward you.\n",
    "A mare shakes out her flowing mane.\n",
    "A mare steps lightly about the room.\n",
    }));
 
  load_a_chat(40, ({
    "The mare rears up in alarm and paws the air with sharp hooves.\n",
    "The mare's eyes show white as she whinnies with fright.\n",
    "The mare tosses her head, shying away.\n",
   })); 
 
  set_attack_msg(({
    "missed", "barely with her hooves",
    "nudged", "lightly with her soft nose",
    "snapped at", "barely missing the face",
    "nipped", "painfully on the arm",
    "bit down on", "with her teeth",
    "kicked", "hard with her sharp hooves",
    "lashed out at", "landing a solid kick in the chest",
    }));
 
  set_al(200);
  set_level(3);
  set_gender(2);
  set_plural("gray mares");
  set_money(85 + random(10));
  set_race("horse");
  set_heart_ob(this_object());
 
}



void monster_heart_beat() {
  object food;
 
  if(present("some hay", this_object())) {
   say("The mare daintly nibbles on some hay.\n");
   food=(present("some hay", this_object()));
   destruct(food);
   }
 
  if(present("carrot", this_object())) {
   say("The mare daintly nibbles on the carrot.\n");
   food=(present("carrot", this_object()));
   destruct(food);
   }
}
