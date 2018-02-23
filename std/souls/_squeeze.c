#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("fondly");
  set_origin_view("You squeeze $[$t|everyone$] $a.");
  set_target_view("$e squeezes you $a.");
  set_other_view("$e squeezes $[$t|everyone$] $a.");
}
