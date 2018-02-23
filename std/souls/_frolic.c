#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("merrily");
  set_origin_view("You frolic around $a$[ with $t$].");
  set_target_view("$e frolics around $a with you.");
  set_other_view("$e frolics around $a$[ with $t$].");
}
