#include <mudlib.h>
inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("guard");
  set_race("human");
  set_gender(1);
  set_short("A City Guard");
  set_long(
  "This City Guard stands proud as the keeper of the gate by the\n"+
  "beach.  Unarmoured and unarmed, he doesn't look very threatening.\n"+
  "Looks can be decieving though, so watch your step around this one.\n");
  set_level(5);
  set_al(20);
  set_wc(9);
  set_ac(5);
  set_hp(80);
  set_max_hp(80);
  set_money(200);
  load_chat(2, ({
  "The Guard says: State your business here.\n",
  }));
}
