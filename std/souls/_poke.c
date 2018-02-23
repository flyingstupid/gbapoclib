#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("mischievously");
  set_adverb_required(1);
  set_origin_view("You $[poke $a at $t|look around for someone to poke$].");
  set_target_view("$e pokes $a at you.");
  set_other_view("$e $[pokes $a at $t|looks around for someone to poke$].");
}
