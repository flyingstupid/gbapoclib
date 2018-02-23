#include <mudlib.h>
inherit MONSTER;

reset (arg) {
  ::reset(arg);
  if(arg) return;
  set_level(10);
  set_al(0);
  set_name("tiger");
  set_alias("hedge");
  set_short("Tiger shaped hedge");
  set_long("This is a rather large hedge, which has expertly been trimmed"+
     " in the shape\nof a tiger. It seems to be watching you.\n");
  set_hp(170);
  set_wc(12);
  set_ac(10);
}
