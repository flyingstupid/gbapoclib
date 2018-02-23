#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("childishly");
  set_origin_view("You taunt $[$t|the room$] $a.");
  set_target_view("$e taunts you $a.");
  set_other_view("$e taunts $[$t|everyone$] $a.");
}
