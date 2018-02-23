#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg)return;
  set_default_adverb("happily");
  set_adverb_required(1);
  set_origin_view("You smile $a$[ at $t$].");
  set_target_view("$e smiles $a at you.");
  set_other_view("$e smiles $a$[ at $t$].");
}
