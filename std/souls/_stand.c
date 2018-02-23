#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("playfully");
  set_origin_view("You stand on $[$t's|your$] head $a.");
  set_target_view("$e stands on your head $a.");
  set_other_view("$e stands on $[$t's|$p$] head $a.");
}
