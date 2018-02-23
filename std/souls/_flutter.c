#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("suggestively");
  set_origin_view("You flutter your eyelids $a$[ at $t$].");
  set_target_view("$e flutters $p eyelids $a at you.");
  set_other_view("$e flutters $p eyelids $a$[ at $t$].");
}
