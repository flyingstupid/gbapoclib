#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("goofily");
  set_origin_view("You ruffle $[$t's hair|your clothes$] $a.");
  set_target_view("$e ruffles you hair $a.");
  set_other_view("$e ruffles $[$t's hair|$p clothes$] $a.");
}
