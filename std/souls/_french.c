#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view(
    "You $[give $t a REAL kiss..it lasts a long time...|"+
    "look around for someone to kiss.$]");
  set_target_view(
    "$e gives you a deep passionate kiss..it seems to take forever...");
  set_other_view(
    "$e $[gives $t a deep passionate kiss..it seems to take forever...|"+
    "looks around for someone to kiss.$]");
}
