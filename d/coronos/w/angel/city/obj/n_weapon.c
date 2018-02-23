#include <mudlib.h>

inherit WEAPON;

void reset(status arg) {
  if(arg) return;
  set_type("thrust");
  set_name("pike");

  set_short("a pike");
  set_long(
"This long weapon is a long shaft of wood with a blade of   \n"+
"sleel at its end. It looks like a good weapon for a footman\n"+
"in the infantry of some army.\n");

  set_length(60);
  set_weight(7);
  set_wc(13);
  set_value(1);
  set_sell_destruct(1);
}

