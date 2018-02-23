/* chicken.c   The chicken lays eggs at random. */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;

void init() {
  call_out("chat",1);
  ::init();
}
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("chicken");
  set_short("a chicken");
  set_long(
    "This is one of the farm's many chickens that roams freely\n"+
    "around the yard. She has reddish-brown feathers, and bright\n"+
    "yellow beak and feet.\n");
  load_chat(5, ({
    "A chicken clucks.\n",
    "A chicken pecks at the ground.\n",
    "A chicken flutters her wings.\n",
    "A chicken scratches at the ground with a foot.\n",
    "A chicken wanders around, bobbing her head.\n",
   }));
 
  load_a_chat(40, ({
    "The chicken clucks frightendly.\n",
    "The chicken jumps with fright and flutters her wings.\n",
    "The chicken squawks in alarm and tries to fly away.\n",
    }));
 
  set_attack_msg(({
    "missed slightly", "",
    "buffeted", "with her wings",
    "flew into", "awkwardly",
    "slapped", "with a wing",
    "pecked", "at your feet",
    "scratched", "on the arm",
    "bit", "with her beak",
    }));
 
  set_al(0);
  set_level(1);
  set_gender(2);
  set_plural("chickens");
  add_money(8 + random(8));
  set_race("bird");
  set_heart_ob(this_object());  
}



void monster_heart_beat() {
  object EGG;
  int RANDOM;

  RANDOM = 1 + random(599);  

  if(RANDOM==10) {    /* 1 every 600 heartbeats, an egg will be cloned.  */
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/egg"),environment(this_object()));
    say("A chicken clucks loudly and lays an egg.\n");    
  }
}
