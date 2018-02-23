#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("aimlessly");
  set_adverb_required(1);
  set_origin_view("You zoom around $[$t $]$a.");
  set_target_view("$e zooms around you $a.");
  set_other_view("$e zooms around $[$t $]$a.");
}
