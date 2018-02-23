#include <mudlib.h>
inherit MONSTER;

void make_items();

void reset(status arg) {
  ::reset(arg);

  if(!present("staff", this_object()) && arg) make_items();

  if(arg) return;

  set_name("tenser");
  set_race("human");
  add_class("mage");
  set_gender(1);
  set_short("Magus Tenser");
  set_level(28);
  set_ac(28);
  set_wc(30);
  set_long(
     "Contrary to most magic-users, Tenser has always been a lover of \n"+
     "battle. Occasionally he will seemingly forget his spells and charge\n"+
     "into melee with his staff, depending on his magical protections to \n"+
     "preserve him. In many ways, it is felt that his temperament was    \n"+
     "better suited to be a fighter.\n");
  add_spell_immunity("fire");
  add_spell_immunity("lightning");
  set_magic_resist(20);

  load_spells(20, ({ "fire ball", "fire shield", 
     "lightning bolt", "chain lightning",
     "stone skin", "ice storm", "mks", "death spell", "disintegrate",
     "burning hands", "chill touch", "energy drain", "monster summon 3", 
  }));

  make_items();
}


void make_items() {
  object staff;

  staff = clone_object(MAGIC_WEAPON);
  staff -> set_name("staff");
  staff -> set_length(80);
  staff -> set_protection("lightning");
  staff -> set_type("crush");
  staff -> set_short("A hardwood staff");
  staff -> set_long(
    "This staff has seen many battles. Its tough hardwood keeping it \n"+
    "sturdy and unbroken. Along its length are also many runes of power.\n"+
    "Perhaps this staff is quite magical?\n");
  staff -> set_read("The runes mean nothing to you.\n");
  staff -> set_wc(15);  /* +3 staff */  
  staff -> set_weight(6);
  staff -> set_info("Tenser's staff. It protects the wielder from lightning");
  staff -> set_value(3000); /* because of enchantment */

  staff -> set_enchanted(1);
  move_object(staff, this_object());
  command("wield staff",this_object());
  this_object()->set_wc(30);
}

