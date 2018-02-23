#include <mudlib.h>
inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Sarah");
  set_race("human");
  set_gender(2);
  set_short("Sarah, the cloth maker");
  set_long(
    "Sarah is a very pretty human. She sits in her store all day\n"+
    "and sews cloth for the citizens of Ille Coronos. She has\n"+
    "long brown hair down to the middle of her back and wears\n"+
    "a white dress.\n");
  set_plural("Sarahs");
  set_level(15);
  set_al(20);
  set_wc(20);
  set_ac(12);
  set_hp(350);
  set_max_hp(350);
  set_money(1600);
  load_chat( 2, ({
    "Sarah says: Take a look at the samples of cloth.\n",
    "Sarah points to the cloth samples.\n",
  }));
}

