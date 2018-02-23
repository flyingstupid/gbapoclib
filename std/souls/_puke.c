#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("violently");
  set_origin_view("You puke on $[$t|your shoes$] $a.");
  set_target_view("$e pukes on you $a.");
  set_other_view("$e pukes on $[$t|$p shoes$] $a.");
}
