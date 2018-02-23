#include <mudlib.h>

inherit MONSTER;

object ob;
void reset(status arg) {
  ::reset(arg);

  if(!present("rapier")) {
    ob = clone_object(WEAPON);
    ob -> set_name("rapier");
    ob -> set_type("slash");
    ob -> set_short("A steel rapier");
    ob -> set_long("A fine rapier, made from a strong metal. The hilt is \n"+
		   "in a basket design, inlaid with precious gems and    \n"+
		   "coated in silver. A fine weapon indeed!\n");
    ob -> set_wc(16); /* +4 rapier */
    ob -> set_length(48);
    ob -> set_weight(4);
    ob -> set_value(5000);
    move_object(ob, this_object());
    init_command("wield rapier");
  }
  
  set_wc(30);

  if(arg) return;

  set_name("rachel");
  set_short("Captain Rachel");
  set_long(
	"Rachel is a beautiful woman, standing a little over five and a half \n"+
	"feet tall, with midnight black hair, which curls around her fair    \n"+
	"features. Her lips are red and full, and her eyes reflect some deep \n"+
	"mischief in her soul. While she is a woman, she is no stranger to   \n"+
	"combat, being a master at many weapons. She is the master of her own\n"+
	"will, and her own ship.\n");
  set_gender(2);
  set_level(40);
  set_max_hp(2000);
  set_hp(2000);
  set_ac(17);
  add_class("thief");
  add_class("fighter");
  add_class("cleric");
  load_spells(10, ({
	"cure light wounds",
	"cure critical wounds",
	"call lightning",
	"bless", "curse", "sts", 
  }));
  set_magic_resist(50);
  add_spell_immunity("fire");
  add_spell_immunity("lightning");
  add_spell_immunity("death");
  add_spell_immunity("poison");
}
