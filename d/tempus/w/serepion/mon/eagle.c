#include <mudlib.h>
inherit MONSTER;

reset (arg) {
  ::reset(arg);
  if(arg) return;
  set_level(8);
  set_al(0);
  set_name("eagle");
  set_alias("hedge");
  set_short("Eagle shaped hedge");
  set_long("This is a rather large hedge, which has expertly been trimmed"+
     " in the shape\nof a eagle. It seems to be watching you.\n");
  set_hp(130);
  set_wc(10);
  set_ac(9);
}
