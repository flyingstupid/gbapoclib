#include <mudlib.h>
inherit CONTAINER;
 
void reset(status arg) {
  if(arg) return;
  set_name("pouch");
  set_plural("pouches");
  set_alias("leather");
  set_short("a small leather pouch");
  set_long("This small leather pouch is ideal for carrying small\n"+
           "objects.  There is a draw string to close the pouch\n"+
           "tight.\n");
  set_max_weight(3);
  set_value(100);
  set_weight(1);
  set_closed(1);
  set_sell_destruct(1);
}
