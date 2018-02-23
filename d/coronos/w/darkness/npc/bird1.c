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
  set_name("pigeon");
  set_alias("pigeon");
 
  set_short("a pigeon");
  set_long(
    "This is a little pigeon, eating seed from the bird feeder.\n");
  set_level(1);
  set_race("bird");
  load_chat(5, ( {
    "The pigeon looks at you and chirps.\n",
    "The pigeon eats some seed.\n",
    "The pigeon stretches its wings.\n",
    "The pigeon chirps.\n",
    }));
  set_attack_msg(({
    "nudges softly", "with its wing",
    "nudges", "with its wing",
    "bumps", "with its wing",
    "pokes", "with its beak",
    "grazes", "with its beak",
    "scratches", "with its beak",
    "scratches deep", "with its beak",
    }));
  
}
