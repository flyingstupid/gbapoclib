#include <mudlib.h>
inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Cannon");
  set_plural("Cannons");
  set_race("human");
  set_gender(1);
  set_short("Cannon, the forger");
  set_long(
    "Cannon, the forger is a tall man, and stands just above six\n"+
    "feet tall. He is a human and has bright blonde hair. He\n"+
    "stands in front of the forge all day making weapons.\n");
  set_level(15);
  set_al(20);
  set_wc(20);
  set_ac(12);
  set_hp(350);
  set_max_hp(350);
  set_money(1600);
  load_chat( 2, ({
    "Cannon asks: What can I make for you?\n",
  }));
}

