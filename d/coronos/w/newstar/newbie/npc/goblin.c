/* goblin.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("goblin");
  set_short("a goblin");
  set_long(
    "This is a small goblin.  He has a flat face, a broad nose, pointed\n"+
    "ears, and a wide mouth with sharp fangs.  His eyes are dull red, and \n"+
    "his skin is a orange with a red tint here and there.  He may have \n"+
    "allied himself with the Drow, but more than likely, he is a slave of\n"+
    "the Drow that has been allowed to go on a scouting team above ground.\n");
 
   load_chat(5, ({
    "The goblin scans the area.\n",
    "The goblin walks around.\n",
    }));
 
  load_a_chat(40, ({
    "The goblin screams with rage.\n",
    "The goblin tries to run away.\n",
    "The goblin yells some sort of goblin battle cry.\n",
    }));
 
  set_al(-200);
  set_ac(3);
  set_wc(6);
  set_level(2);
  set_gender(1);
  set_money(40 +random(20));
  set_race("goblin");
  add_class("fighter");
 
 if (!present("tattered boots")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/boots"),
    this_object());
    command("wear boots");
  }
}
