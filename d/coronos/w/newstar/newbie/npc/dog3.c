/* dog3.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("dog");
  set_short("a large dog");
  set_plural("large dogs");
  set_long(
    "This is a large, dark brown dog.  He is lean and strong.\n"+
    "He guards with alert ears and watchful eyes.  He is 'man's\n"+
    "best friend', staying close to his master, protecting him\n"
    "from any harm.\n");

  load_chat(5, ({
    "The dog wags his tail.\n",
    "The dog watches you closely.\n",
    "The dog licks his forepaw.\n",
    "The dog walks slowly around the room.\n",
    "The dog sniffs you cautiously.\n",
    }));
 
  load_a_chat(40, ({
    "The dog growls angrily.\n",
    "The dog barks furiously.\n",
    "The dog snarls viciously.\n",
    "The dog howls in rage.\n",
    "The dog bristles and bares his sharp fangs.\n",
    }));

  set_attack_msg(({
    "nudged", "with his nose",
    "bat at", "with his paw",
    "grazed", "slightly on the arm",
    "snapped at", "with his fearful fangs",
    "lunged at", "with gaping jaws",
    "bit", "hard on the leg",
    "tore", "very deep with his sharp teeth",
    }));
 
  set_al(200);
  set_level(3);
  set_gender(1);
  set_race("canine");
 
  if(!present("collar")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/collar"),
    this_object());
    command("wear collar");
  }
}
