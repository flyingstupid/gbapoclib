#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("gnak");
  set_race("human");
  set_gender(1);
  set_short("Gnak, the Bank Keeper");
  set_long(
    "Gnak is a wrinkled old man who looks as if he has been around\n"+
    "for quite some time.  He is a shrewd businessman, and will\n"+
    "take advantage of you if you are not careful.\n"
  );
  set_level(15);
  set_al(0);
  set_wc(9);
  set_ac(5);
  set_hp(80);
  set_max_hp(80);
  set_money(200);
  load_chat( 2, ({
    "Gnak looks around for money to count.\n",
    "Gnak asks: Do you have any money for me to store?\n",
  }));
}
