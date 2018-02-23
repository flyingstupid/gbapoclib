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
  set_name("spider");
  set_alias("spider");
 
  set_short("a spider");
  set_long(
    "This spider is fairly large and furry.  It doesn't look very\n"+
    "threatening though.\n");
  set_level(4);
  set_race("arachnid");
  load_chat(5, ( {
    "A spider hangs from a line of thread.\n",
    "A spider scurries across the floor.\n",    
    "A spider crawls along a wall.\n",
    "A spider seems to stop and look at you.\n",
    "A spider works on a web.\n",
    }));
  set_attack_msg(({
    "touches", "with its leg",
    "bumps", "with its body",
    "scratches", "with its legs",
    "pokes", "with its legs",
    "grazes", "with its fangs",
    "scratches", "with its fangs",
    "scratches deep", "with its fangs",
    }));
  
}
