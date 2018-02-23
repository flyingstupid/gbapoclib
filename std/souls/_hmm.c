#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("thoughtfully");
  set_adverb_required(1);
  set_origin_view("You hmm $a.");
  set_other_view("$e hmms $a.");
}
