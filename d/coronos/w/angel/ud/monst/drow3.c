#include <mudlib.h>
inherit MONSTER;

#define OBJ	"d/coronos/w/angel/ud/obj"
object gem, sack, staff, arm;

void reset(status arg) {
  int i;
  ::reset(arg);

  if(!present("sack")) {
    sack = clone_object("objects/bag");
    move_object(sack, this_object());
  }
  
  if(present("sack")) {
    for(i=0; i<5; i++) {
      if(!present("gem", sack)) 
        move_object(clone_object("objects/components/gem"), sack);
    }
  }


  if(!arm) {
    arm = clone_object(ARMOUR);
    arm -> set_name("chainmail");
    arm -> set_type("armour");
    arm -> set_armour_material("adamantite");
    arm -> set_ac(3);
    arm -> set_weight(4);
    arm -> set_short("a suit of black chainmail");
    arm -> set_long(
        "A fine suit of chainmail whose links are delicate, yet as \n"+
        "strong as adamantite armour. There is a sigil on the arm  \n"+
        "which identifies the armour as the property of the house  \n"+
        "of Noquar.\n");

    arm -> set_alias("sigil");
    arm -> set_read("You don't understand what it says.\n");
    arm -> set_info("The rune is that of a drow house, Noquar.\n");
    arm -> set_value(1200);
    move_object(arm, this_object());
    init_command("wear armour");
  }

  set_wc(30);
  set_alignment(-1000);
  set_ac(20);

  if(arg) return;

  set_name("faeryl");
  set_gender(2);
  set_short("Faeryl, priestess of Lolth");

  set_level(25);
  set_max_hp(2000);
  set_hp(2000);

  set_magic_resist(90);

  add_spell_immune("poison");
  add_spell_immune("fire");
  add_spell_immune("cold");
  add_spell_immune("lightning");

  set_race("dark elf");
  set_alias("priestess");
  set_alt_name("drow");

  set_long(
"Faeryl is a beautiful dark elf, whose skin glistens with \n"+
"a high black sheen. Her hair is all silvery white, and   \n"+
"her features more beautiful than you thought imaginable  \n"+
"for one of her kind. She is a priestess of Lolth, and a  \n"+
"member of the house of Noquar.\n");

  set_heart_ob(this_object());
  set_dead_ob(this_object());

  add_class("fighter");
  add_class("cleric");

  load_spells(50, ({
	"cure light wounds", "cure critical wounds", "heal",
	"bless", "curse", "barkskin", "sts", "animate zombie",
	"animate skeleton", "fire storm",
	"cause wounds", "cause serious wounds", "cause critical wounds",
	"earthquake", "call lightning",
	"cause blindness", "cause disease", "prayer",
	"flamestrike",
  }));

  load_chat(5, ({
"Faeryl asks: What are you doing here?\n",
"Faeryl says: Women are superior.\n",
"Faeryl says: Males are inferior.\n",
"Faeryl says: The wyvern will be good for the human troops.\n",
"Faeryl says: The surface dwellers do not have a chance.\n",
"Faeryl says: All surface dwellers will fall before us.\n",
  }));

  load_a_chat(2, ({
"Faeryl says: Loth shall have your soul.\n",
"Faeryl laughs at you.\n",
"Faeryl says: You shall surely die.\n",
"Faeryl says: You are no match for me.\n",
  }));

  set_aggressive(1);
}

void monster_died() {
  tell_room(environment(), query_name()+" exclaims: "+
	"This shall not be the last you see of me. Lolth shall \n"+
	"\thave her revenge on you!\n");
}


void monster_heart_beat() {
  if(!random(20) && present(query_attack(), environment()))
    if(present("staff")) 
      init_command((string)staff->query_command_word());
}


void init() {
  ::init();
  if(!present("staff")) {
    staff = clone_object(OBJ+"/staff");
    move_object(staff, this_object());
    init_command("wield staff");
  }
}

status query_no_steal() { return 1; }
