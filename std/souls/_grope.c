#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("lustfully");
  set_origin_view("You grope $[$t|$oself$] $a.");
  set_target_view("$e gropes you $a.");
  set_other_view("$e gropes $[$t|$oself$] $a.");
}
