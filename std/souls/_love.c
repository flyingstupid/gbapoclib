#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("You tell your true feelings to $[$t.|... yourself!$]");
  set_target_view("$e whispers to you sweet words of love.");
  set_other_view("$e whispers softly to $[$t.|... $oself!$]");
}
