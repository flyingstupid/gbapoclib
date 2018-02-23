#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_default_adverb("stupidly");
  set_origin_view(
    "You whap yourself in the head $a while saying, \"Duuuuhh!\"");
  set_other_view(
    "$e whaps $oself in the head $a while saying, \"Duuuuhh!\"");
}
