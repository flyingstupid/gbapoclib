#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("affectionately");
  set_origin_view("You $[snuggle up to $t $a|look around for someone to "+
    "snuggle up to$].");
  set_target_view("$e snuggles up to you $a.");
  set_other_view("$e $[snuggles up to $t $a|looks around for someone to "+
    "snuggle up to$].");
}
