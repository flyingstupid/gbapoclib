#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("You go HEE!!");
  set_other_view("$e goes HEE!!");
}
