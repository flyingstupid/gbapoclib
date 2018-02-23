#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  set_default_adverb("profoundly");
  if(arg) return;
  set_origin_view("Your mind boggles $a at the concept.");
  set_other_view("$e's mind boggles $a at the concept.");
}
