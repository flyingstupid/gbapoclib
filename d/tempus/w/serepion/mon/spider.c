#include <mudlib.h>
inherit MONSTER;

reset (arg) {
  ::reset(arg);
  if(arg) return;
  set_level(6);
  set_al(0);
  set_name("spider");
  set_alias("hedge");
  set_short("Spider shaped hedge");
  set_long("This is a rather large hedge, which has expertly been trimmed"+
     " in the shape\nof a spider. It seems to be watching you.\n");
  set_hp(90);
  set_wc(8);
  set_ac(7);
}
