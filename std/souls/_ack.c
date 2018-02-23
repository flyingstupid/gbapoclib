#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  set_default_adverb("noisily");
  if(arg) return;
  set_origin_view("You ack $a.");
  set_other_view("$e acks $a.");
}
