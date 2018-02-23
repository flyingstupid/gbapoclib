#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("briefly");
  set_origin_view("You clap $a$[ for $t$].");
  set_target_view("$e claps $a for you.");
  set_other_view("$e claps $a$[ for $t$].");
}
