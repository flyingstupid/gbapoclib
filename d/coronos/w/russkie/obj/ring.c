#include <ansi.h>
#include <mudlib.h>
inherit ARMOUR;

  void reset(status arg) {
  if(arg) return;

  set_name("ring");
  set_short("a shimmering gold ring");
  set_long("\
This is a small, shimmering gold ring. It has a golden aura about\n\
it. Small flakes of diamonds cover the top of the ring.\n");
  set_ac(1);
  set_info("An aura of protection surrounds the ring.\n");
  set_value(600);
  set_type("ring");
  set_weight(2);
  set_enchanted(1);
}
