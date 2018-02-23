#include <ansi.h>
#include <mudlib.h>
inherit WEAPON;

  void reset(status arg) {
  if(arg) return;

  set_name("sword");
  set_alias("golden sword");
  set_light(2);
  set_short("a golden longsword");
  set_alt_name("longsword");
  set_long("This is a large gold sword. The hilt is highly detailed, and the blade is\n\
quite sharp and strong.\n");
  set_length(20);
  set_type("slash");
  set_wc(13);
  set_weight(4);
  set_value(2000);
}
