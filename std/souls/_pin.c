#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("aggressively");
  set_origin_view("$[You grab $t by the hair and $a pin $p shoulders to "+
    "the ground|You can't pin the air$]!");
  set_target_view("$e grabs you by the hair and $a pins you to the ground.\n");
  set_other_view("$e $[grabs $t by the hair and $a pins $p shoulders to "+
    "the ground|tries to pin the air to the ground$]!");
}
