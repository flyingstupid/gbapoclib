#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("shamelessly");
  set_origin_view("You froth $a at $[$t|the mouth$].");
  set_target_view("$e froths $a at you.");
  set_other_view("$e froths $a at $[$t|the mouth$].");
}
