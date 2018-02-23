#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("PHEW!!");
  set_other_view("$e breathes a sigh of relief.\n");
}
