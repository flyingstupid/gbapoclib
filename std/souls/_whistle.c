#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("appreciatively");
  set_origin_view("You whistle $a$[ at $t$].");
  set_target_view("$e whistles $a at you.");
  set_other_view("$e whistles $a$[ at $t$].");
}
