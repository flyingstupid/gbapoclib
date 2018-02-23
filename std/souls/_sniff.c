#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("tearfully");
  set_origin_view("You sniff $a.");
  set_other_view("$e sniffs $a.");
}
