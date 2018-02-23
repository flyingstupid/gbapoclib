#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  set_default_adverb("wholeheartedly");
  if(arg) return;
  set_origin_view("You applaud $[$t $]$a.");
  set_target_view("$e gives you a round of applause $a.");
  set_other_view("$e applauds $[$t $]$a.");
}
