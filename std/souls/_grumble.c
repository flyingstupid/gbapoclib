#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("unhappily");
  set_adverb_required(1);
  set_origin_view("You grumble $a$[ to $t$].");
  set_target_view("$e grumbles $a to you.");
  set_other_view("$e grumbles $a$[ to $t$].");
}
