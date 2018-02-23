#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("gracefully");
  set_origin_view("You bow $a$[ to $t$].");
  set_target_view("$e bows $a$[ before you$]..");
  set_other_view("$e bows $a$[ to $t$].");
}
