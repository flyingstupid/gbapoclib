#include <mudlib.h>
inherit MONSTER;

object sword;

void reset(status arg) {
  ::reset(arg);

 if(!present("sword")) {
    sword = clone_object(WEAPON);
    sword -> set_name("claymore");
    sword -> set_alias("sword");
    sword -> set_wc(16);
    sword -> set_length(72);
    sword -> set_weight(5); /* +2 sword! */
    sword -> set_value(4000);
    sword -> set_short("a claymore");
    sword -> set_long(
	"A large twohanded sword. The blade appears to be made from\n"+
	"a red metal, possibly meteorite iron. It looks very strong.\n");
    move_object(sword, this_object());
    init_command("wield sword");
    set_level(20);
    set_max_hp(1500);
    set_hp(1500);
  }

  if(arg) return;

  set_name("fire giant");
  set_short("a fire giant");
  set_gender(1);
  set_race("giant");
  set_long(
	"This giant stands some 12 feet tall with a muscular chest\n"+
	"nearly 9 feet across. His skin is coak-black and his hair\n"+
	"flaming red.\n");

  set_level(20);
  add_spell_immunity("fire");
  set_aggressive(1);
}
