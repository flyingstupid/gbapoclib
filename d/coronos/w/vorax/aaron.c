#include <mudlib.h>
inherit MONSTER;
  void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("aaron");
  set_race("human");
  set_gender(1);
  set_short("Aaron, the Postal Worker");
  set_long(
    "Aaron is a tall human, in his twenties.  He stands tall and proud.\n"+
    "He takes pride in what he does, and he does it well.  Your mail will\n"+
    "be in good hands with Aaron.\n"
  );
  set_level(15);
  set_al(25);
  set_wc(9);
  set_ac(5);
  set_hp(80);
  set_max_hp(80);
  set_money(200);
  load_chat(2, ({
    "Aaron says: Would you like to leave any mail?",
  }));
}
