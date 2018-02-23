#include <ansi.h>
#include <mudlib.h>
inherit WEAPON;

  void reset(status arg) {
  if(arg) return;

  set_name("dirk");
  set_alias("shining dirk");
  set_info("There is a bright sheen to this short dirk.\n");
  set_light(2);
  set_short("a shining blue dirk");
  set_long("This is a short dirk. It glimmers in the light as if on fire. It is\n\
quite lovely to look at.\n");
  set_length(13);
  set_type("slash");
  set_wc(7);
  set_weight(4);
  set_value(110);
}
