#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  set_default_adverb("playfully");
  if(arg) return;
  set_origin_view("You bop $[$t on the head $a|$a to the beat$].");
  set_target_view("$e bops you on the head $a.");
  set_other_view("$e bops $[$t on the head $a|$a to the beat$].");
}
