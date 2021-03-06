#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit MONSTER;

object sword;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

    
  /* Royal Guard */
  
  set_name("royal guard");
  set_alias("guard");
  set_short("Royal Guard");
  set_long(
	"This is a Royal Guard. He is the strongest guard and most\n"+
	"powerful guard the minotaurs have.\n");
  set_level(15);
  set_gender(1);
  set_race("minotaur");
  set_ac(12);
  set_hp(400);
  set_max_hp(400);
  set_al(-300);
  set_strength(17);
  add_money(250);
    
  /* Weapon definition */
  
  sword = clone_object(WEAPON);
  sword->set_alias("sword");
  sword->set_name("longsword");
  sword->set_short("A longsword");
  sword->set_plural("longswords");
  sword->set_long(
		"This sword belongs to a royal minotaur guard.\n"+
		"It is one of the best swords you have ever seen!\n");
  sword->set_length(54);
  sword->set_weight(5);
  sword->set_wc(15);
  sword->set_type("slash");
  sword->set_value(3200);
  move_object(sword, this_object());
  init_command("wield sword");
  set_wc(20);
 
}
