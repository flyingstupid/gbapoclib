#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("madly");
  set_origin_view(
    "You race $a around the room $[and give $t|"+
    "giving everyone$] a high five!");
  set_target_view("$e jumps $a into the air and gives you a high five!");
  set_other_view("$e races $a around the room $[and gives $t|"+
    "giving everyone$] a high five!");
}
