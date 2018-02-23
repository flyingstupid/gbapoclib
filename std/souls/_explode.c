#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("wildly");
  set_origin_view("You explode $a all over $[$t|the room$]!");
  set_target_view("$e explodes $a all over you!");
  set_other_view("$e explodes $a all over $[$t|the room$]!");
}
