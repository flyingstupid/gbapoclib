#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("lovingly");
  set_origin_view("You $[fondle $t $a|look around for someone to fondle$].");
  set_target_view("$e fondles you $a.");
  set_other_view("$e $[fondles $t $a|looks around for somone to fondle$].");
}
