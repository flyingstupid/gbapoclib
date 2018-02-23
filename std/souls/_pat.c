#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("patronizingly");
  set_origin_view("You pat $[$t $a on the head|your stomach$].");
  set_target_view("$e pats you $a on the head.");
  set_other_view("$e pats $[$t $a on the head|$p stomach$].");
}
