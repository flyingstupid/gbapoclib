#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("You hold up one finger and say \"I'll be right back!\"");
  set_other_view("$e holds up one finger and says \"I'll be right back!\"");
}
