#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("tenderly");
  set_origin_view("You nibble $[$a on $t's ear|on your fingernails$].");
  set_target_view("$e nibbles $a on your ear.");
  set_other_view("$e nibbles $[$a on $t's ear|on $p fingernails$].");
}
