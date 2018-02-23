#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("gently");
  set_origin_view("You $[comfort $t $a|look around for someone to comfort$].");
  set_target_view("$e comforts you $a.");
  set_other_view("$e $[comforts $t $a|looks around for someone to comfort$].");
}
