#include <mudlib.h>
inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Denon");
  set_race("human");
  set_gender(1);
  set_short("Denon, the armourer");
  set_long(
    "Denon, the armourer has a stern look on his face as he\n"+
    "pounds away on the forge to make some armour. He is not\n"+
    "not very tall and is only about five and a half feet tall.\n");
  set_plural("Denons");
  set_level(15);
  set_al(20);
  set_wc(20);
  set_ac(12);
  set_hp(350);
  set_max_hp(350);
  set_money(1600);
  load_chat( 2, ({
    "Denon says: What can I do for you today?\n",
  }));
}

