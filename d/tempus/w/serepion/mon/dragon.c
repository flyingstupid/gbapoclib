#include <mudlib.h>
inherit MONSTER;

reset (arg) {
  ::reset(arg);
  if(arg) return;
  set_level(14);
  set_al(0);
  set_name("dragon");
  set_alias("hedge");
  set_short("Dragon shaped hedge");
  set_long("This is a rather large hedge, which has expertly been trimmed"+
     " in the shape\nof a dragon. It seems to be watching you.\n");
  set_hp(300);
  set_wc(16);
  set_ac(13);
}
