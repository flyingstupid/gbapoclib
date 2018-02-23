#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if(arg) return;
  set_origin_view("You grin and go, 'heh heh heh.'");
  set_other_view("$e grins and goes, 'heh heh heh.'");
}
