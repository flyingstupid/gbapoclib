#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("affectionately");
  set_origin_view("You $[cuddle $t $a|look around for someone to cuddle$].");
  set_target_view("$e cuddles you $a.");
  set_other_view("$e $[cuddles $t $a|looks around for someone to cuddle$].");
}
