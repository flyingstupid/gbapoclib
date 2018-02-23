#include <mudlib.h>
inherit MONSTER;

void make_items();

void reset(status arg) {
  string *races;

  races = ({ "dwarf", "human", "high elf", "grey elf", });

  ::reset(arg);
  if(arg) { make_items(); return; }

  set_alignment(100 + random(1000));

  set_race(races[random(sizeof(races))]);

  set_name("black guard");
  set_alias("guard");

  set_short("a member of the Black Guard");

  set_long(
      "This imposing figure towers above you; a formidable foe who could \n"+
      "out class you in battle with ease. All members of the Black Guard \n"+
      "are hand chosen and are the finest warriors of Ille Coronos. \n");

  set_gender(random(2) + 1);
  set_level(15 + random(10));
  add_class("fighter");

  if(!random(4)) {
    add_class("mage");
    load_spells(20, ({  
		"magic missile",
		"lightning bolt",
		"chill touch",
		"acid arrow",
		"vampiric touch",
		"fire ball",
		"fireshield",
		"coc",
		"enlarge",
		"contagion",
    }));
  }

  if(!random(4)) {
    add_class("cleric");
    load_spells(20, ({ 
		"barkskin",
                "bless",
                "prayer",
                "cure wounds",
                "cure serious wounds",
                "cause blindness",
                "spiritual hammer",
                "holy strike",
                "bless",
                "curse",
		"death curse",
    }));
  }

  load_chat(10, ({ "Black Guard says: Move along.\n",
        "Black Guard asks: What are you doing here?\n",
        "Black Guard says: The Circle doesn't like to be disturbed.\n",
        "Black Guard says: The Circle doesn't like to be disturbed.\n",
        "Black Guard stands tall.\n",
        "Black Guard watches you expertly.\n",
        "Black Guard raises an eyebrow.\n",
        "Black Guard says: Do not loiter citizen.\n",
  }));

  load_a_chat(20, ({
	"Black Guard dodges your blow.\n",
        "Black Guard says: You should not make an enemy of the guards.\n",
        "Black Guard says: You are making a grave mistake.\n",
        "Black Guard parries your blow.\n",
        "Black Guard ignores the pain.\n",
  }));

  add_money(1000);
  set_magic_resist(25 + random(20));
  make_items();
  set_heart_ob(this_object());
}

void monster_heart_beat() {
  object *ob;
  int i;


  if(!present("PLAYER", environment())) return;

  ob = all_inventory(environment());

  for(i=0; i<sizeof(ob); i++) {
    if(ob[i]->query_attack() && ob[i]->query_npc()) {
      if(!this_object()->query_attack()) {
        tell_room(environment(), "Black Guard comes to the aid of "+
        query_possessive()+" ally.\n");
        this_object()->add_secondary_attacker(ob[i]->query_attack());
      }
    }
  }
}




void make_items() {
  object ob;
  mixed *weapon_array, *armour_array;
  int ii;

  weapon_array = ({
        ({ "longsword", 13, 42, "slash", 5, 1800, }),
        ({ "shortsword", 10, 24, "slash", 5, 520, }),
        ({ "twohandedsword", 14, 72, "cleave", 5, 2500, }),
        ({ "falchion", 12, 42, "slash", 5, 1100, }), 
        ({ "sabre", 10, 45, "slash", 5, 520, }),
  });

  ii = random(sizeof(weapon_array));

  if(!present("sword")) {
  ob = clone_object(WEAPON);
  ob -> set_name(weapon_array[ii][0]);
  ob -> set_wc(weapon_array[ii][1]);
  ob -> set_length(weapon_array[ii][2]);
  ob -> set_type(weapon_array[ii][3]);
  ob -> set_weight(weapon_array[ii][4]);
  ob -> set_value(weapon_array[ii][5]);
  ob -> set_short("A black "+weapon_array[ii][0]);
  ob -> set_alias("sword");
  ob -> set_long(
        "A fine black "+weapon_array[ii][0]+" made from a steel and \n"+
        "adamantite alloy. It bears the crest of the black guard   \n"+
        "and a single circle of gold in the hilt.\n");
  move_object(ob, this_object());
  command("wield sword");
  set_wc(24);
  }

  if(!present("armour")) {
  ob = clone_object(ARMOUR);
  ob -> set_name("platemail");
  ob -> set_type("armour");
  ob -> set_short("A suit of platemail");
  ob -> set_plural("suits of platemail");
  ob -> set_long(
        "A suit of finely smithed platemail, made from steel and \n"+
        "an adamantite alloy. This armour is adorned with the    \n"+
        "crest of the Black Guard and emblazoned with a single   \n"+
        "gold circle around it. Only the elite may wear this     \n"+
        "armour, to do so without permission is a crime.         \n");

  ob -> set_ac(4);
  ob -> set_weight(5);
  ob -> set_value(2500);
  ob -> set_armour_material("adamantite");
  move_object(ob, this_object());
  command("wear armour");
  }


  armour_array = ({ 
        ({ "shield", "shield",    }),
        ({ "helmet", "helm",      }),
        ({ "gauntlets", "gloves", }),
        ({ "boots", "boots",      }),
  });
 
  ii = random(sizeof(armour_array));
  if(!present("pair")) {
  ob = clone_object(ARMOUR);
  ob -> set_name(armour_array[ii][0]);
  ob -> set_type(armour_array[ii][1]);
  ob -> set_alias("pair");
  
  if(armour_array[ii][0] == "boots" || armour_array[ii][0] == "gauntlets") {
    ob -> set_short("A pair of "+armour_array[ii][0]);
    ob -> set_plural("pairs of "+armour_array[ii][0]);
    ob -> set_long(
                "A finely smithed pair of "+armour_array[ii][0]+"\n"+
                "made by the smiths of the Black Guard. \n");
  }
  else {
    ob -> set_short("A black "+armour_array[ii][0]);
    ob -> set_long(
                "A finely smithed "+armour_array[ii][0]+" "+
                "made by the armourers of the Black Guard. \n");
  }

  ob -> set_weight(1);
  ob -> set_ac(1);
  ob -> set_value(300);
  ob -> set_armour_material("adamantite");
  move_object(ob, this_object());
  command("wear pair");
  set_ac(12);
  }
}


