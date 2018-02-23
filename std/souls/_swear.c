#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("profusely");
  set_origin_view("You swear $a in a dozen different languages.");
  set_other_view("$e swears $a in a dozen different languages.");
}
