#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("You finally get the idea and give an 'ah' of comprehension.");
  set_other_view("$e finally gets the idea and gives an 'ah' of comprehension.");
}
