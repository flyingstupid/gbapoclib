#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

    
  /* Light Elemental */
  
  set_name("elemental");
  set_short("Light Elemental");
  set_long(
	"This Light Elemental is here to guard the entrance to the upper\n"+
	"levels of Minotaur Castle.\n");
  set_level(13);
  set_gender(1);
  set_race("elemental");
  set_aggressive(1);
  set_ac(7);
  set_hp(250);
  set_max_hp(250);
  set_wc(18);
  set_al(-300);
  add_money(150);
    
}
  

