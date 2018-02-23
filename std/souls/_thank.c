#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("politely");
  set_origin_view("You thank $[$t|everyone$] $a.");
  set_target_view("$e thanks you $a.");
  set_other_view("$e thanks $[$t|everyone$] $a.");
}
