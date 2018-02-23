#include <mudlib.h>
inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("begger");
  set_race("elf");
  set_gender(1);
  set_short(
    "A poor begger");
  set_long(
    "This elf is in a very bad posistion. He has a cup out in\n"+
    "front of him, that has some coins in it. Even though he\n"+
    "is wearing ripped up clothes, he still looks fairly strong\n");
  set_plural("beggers");
  set_level(10);
  set_al(10);
  set_wc(14);
  set_ac(8);
  set_hp(175);
  set_max_hp(175);
  set_money(100);
  load_chat( 2, ({
    "The begger says: Please sir, spare some money?",
  }));
}
