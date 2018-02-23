#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("farewell");
  set_adverb_required(1);
  set_origin_view("You wave $a$[ to $t$].");
  set_target_view("$e waves $a to you.");
  set_other_view("$e waves $a$[ to $t$].");
}
