#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("deeply");
  set_origin_view("You think $a about a problem.");
  set_other_view("$e's brow furrows up and smoke billows from $p ears "+
    "as $s thinks $a about a problem.");
}
