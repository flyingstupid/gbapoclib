#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

    
  set_name("guard");
  set_short("A Castle Guard");
  set_long(
	"This guard is placed on the lower floor of the castle to\n"+
	"protect the vast treasures placed throughout the castle. This\n"+
	"guard is not as strong as those placed on the higher floors of\n"+
	"the castle.\n");
  set_level(12);
  set_gender(1);
  set_race("minotaur");
  set_ac(10);
  set_hp(250);
  set_max_hp(250);
  set_wc(17);
  set_al(-100);
  set_strength(13);
  set_dexterity(14);
  add_money(150);
    
}
  

