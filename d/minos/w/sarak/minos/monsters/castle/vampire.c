#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit UNDEAD;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

    
  /* Vampire!! */
  
  set_name("vampire");
  set_short("a young Vampire");
  set_long(
	"This particular vampire is not impressed. You have disturbed\n"+
	"him during one of his meals! Now he plans on killing you!\n");
  set_level(17);
  set_gender(1);
  set_race("human");
  set_aggressive(1);
  set_ac(14);
  set_wc(24);
  set_hp(650);
  set_alias("undead");
  set_drain_chance(5);
  set_max_hp(650);
  set_al(-700);
  add_money(200);
  add_class("mage");
  load_spells(25, ({
    "fire shield",  "resist magic",  "burning hands",
    "chain lightning", "mks", "fire ball", "animate zombie",
  }));  
}
