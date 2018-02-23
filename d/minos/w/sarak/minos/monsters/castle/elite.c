#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit MONSTER;

object sword;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

    
  /* Elite Guard */
  
  set_name("elite guard");
  set_alias("guard");
  set_short("Elite Guard");
  set_long(
	"This is one of the guards. He is much stronger\n"+
	"than the normal guards. He is also wielding a weapon.\n");
  set_level(14);
  set_gender(1);
  set_race("minotaur");
  set_ac(13);
  set_hp(300);
  set_max_hp(300);
  set_al(-300);
  add_money(200);
    
  /* Weapon definition */
  

  sword = clone_object(WEAPON);
  sword->set_alias("sword");
  sword->set_name("bastardsword");
  sword->set_plural("bastardswords");
  sword->set_short("A bastardsword");
  sword->set_long(
		"This sword belongs to an elite minotaur guard.\n"+
		"Whoever got this sword did very well indeed!\n");
  sword->set_length(54);
  sword->set_weight(5);
  sword->set_wc(13);
  sword->set_type("cleave");
  sword->set_value(1800);

  move_object(sword, this_object());
  init_command("wield sword");
  set_wc(18);
 
}
  

