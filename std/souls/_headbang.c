#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("wildly");
  set_origin_view("You $[bang your head into $t|headbang$] $a.");
  set_target_view("$e hits you in the head $a");
  set_other_view("$e $[bangs $p head into $t|headbangs$] $a.");
}
