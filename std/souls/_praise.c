#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("thankfully");
  set_origin_view("You $a praise $[$t for $p|everyone for their$] efforts.");
  set_target_view("$e $a praises you for your efforts.");
  set_other_view("$e $a praises $[$t for $p|everyone for their$] efforts.");
}
