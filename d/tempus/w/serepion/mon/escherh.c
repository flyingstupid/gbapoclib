#include <mudlib.h>
inherit MONSTER;

reset (arg) {
  ::reset(arg);
  if(arg) return;
  set_level(12);
  set_al(0);
  set_name("human");
  set_alias("hedge");
  set_short("Human shaped hedge");
  set_long("This is a rather large hedge, which has expertly been trimmed"+
     " in the shape\nof a human. It seems to be watching you.\n");
  set_hp(230);
  set_wc(14);
  set_ac(11);
}
