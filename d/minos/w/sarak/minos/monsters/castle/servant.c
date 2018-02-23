#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

    
  set_name("servant");
  set_short("Minotaur Servant");
  set_long(
	"This is one of several servants found throughout\n"+
	"the castle. They are here to serve the king.\n");
  set_level(10);
  set_gender(2);
  set_race("minotaur");
  set_ac(9);
  set_hp(200);
  set_max_hp(200);
  set_wc(15);
  set_al(-50);
  set_aggressive(0);
  add_money(100 + random(50));
    
}
  

