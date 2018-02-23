/* dog2.c -- Newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("dog");
  set_short("a brown dog");
  set_plural("brown dogs");
  set_long(
    "This is a medium-sized, brown dog.  She has floppy ears,\n"+
    "curling fur and a bushy tail.  She looks calm and relaxed,\n"+
    "but always keeps an eye on what goes on in the room.\n");
  load_chat(5, ({
    "The dog wags her tail happily.\n",
    "The dog yawns and stretches.\n",
    "The dog lies down in the corner and pants softly.\n",
    "The dog walks around the room.\n",
    "The dog sniffs at you curiously.\n",
    }));
 
  load_a_chat(40, ({
    "The dog growls angrily.\n",
    "The dog barks furiously.\n",
    "The dog lunges, snapping with rage, barely missing flesh.\n",
    "The dog snarls viciously, with hackles raised.\n",
    }));
 
  set_attack_msg(({
    "nudged", "softly with her nose",
    "bat", "with her paw",
    "grazed", "slightly with her teeth",
    "nipped", "on the heels"
    "bit", "on the arm",
    "bit", "deep with her sharp teeth",
    "chomped", "hard on the leg",
    }));
 
  set_al(200);
  set_level(2);
  set_ac(3);
  set_wc(6);
  set_gender(2);
  set_race("canine");
 
  if(!present("collar")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/collar"),
    this_object());
    command("wear collar");
  }
}
 
