#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("You stomp your feet loudly, in rhythm.\n");
  set_other_view(
"$e stomps $p feet loudly in rhythmetic movements, $p cloak flaps"+
  "behind in colorful waves.\n");
}

