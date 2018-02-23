#include <mudlib.h>
inherit ARMOUR;

void reset(status arg) {
  if(arg) return;

  set_type("ring");
  set_short("A gold ring");
  set_name("ring");
  set_weight(1);
  set_ac(1);
  set_value(400);
  set_info(
        "This is a simple goldring.\n");
  set_long(
        "This is a fairly large ring. The former owner must have been \n"+
        "a quite fat man. On the inside you can see the name Handlfoot \n"+
        "engraved in the gold.\n");
  set_sell_destruct(1);
}
