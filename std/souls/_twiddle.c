#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("patiently");
  set_origin_view("You twiddle your thumbs $a.");
  set_other_view("$e twiddles $p thumbs $a.");
}
