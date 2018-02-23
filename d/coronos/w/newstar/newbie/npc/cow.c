/* cow.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("cow");
  set_alias("bovine");
  set_short("a cow");
  set_long(
    "This is a black and white cow.  Her soft brown eyes add to\n"+
    "her placid nature.  Though she has horns, it seems doubtful\n"+
    "that she'd ever use them.  Her cow bell clangs as she moves.\n");
  load_chat(5, ({
    "A cow goes,'Moooo.'\n",
    "A cow swishes her tail back and forth.\n",
    "A cow stares at you and chews her cud.\n",
    "A cow munches on the grass.\n",
    "A cow plods about slowly.\n",
    }));
 
  load_a_chat(40, ({
    "The cow bellows a loud 'MOO'.\n",
    "The cow tramples around in blind rage.\n",
    "The cow threatens with her sharp horns.\n",
    }));
 
  set_attack_msg(({
    "bumped into", "clumsily "
    "nudged", "softly with her nose",
    "whacked", "hard with her tail",
    "charged straight at", "with her sharp horns",
    "kicked", "hard with her hooves",
    "kicked", "in the stomach",
    "chomped down on", "with her teeth",
    }));
 
  set_al(0);
  set_level(1);
  set_gender(2);
  set_plural("cows");
  add_money(8 + random(9));
  set_race("bovine");
  set_heart_ob(this_object());
 
  if(!present("bell")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/cowbell"),
    this_object());
    command("wear bell");
  }
}


 
void monster_heart_beat() {
  object food;
 
  if(present("some hay", this_object())) {
   say("The cow calmly munches on some hay.\n");
   food=(present("some hay", this_object()));
   destruct(food);
   }
}
