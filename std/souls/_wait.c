#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("patiently");
  set_origin_view("You wait $a$[ for $t$].");
  set_target_view("$e waits $a for you.");
  set_other_view("$e waits $a$[ for $t$].");
}
