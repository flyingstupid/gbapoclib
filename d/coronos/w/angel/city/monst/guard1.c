#include <mudlib.h>
object sword;
object armour;

inherit MONSTER;
void make_items();

void reset(status arg) {
  string *races;
  ::reset(arg);

  if(arg) make_items();

  else {
    set_name("guard");
    set_plural("city guards");
    set_short("A city guard");
    set_long(
       "This is a simple city guard from Ille Coronos.   \n"+
       "He is weary from spending long hours at his post.\n"+
       "Although he seems about to fall asleep, you're   \n"+
	"sure he knows you're here, and is ready to attack\n"+
	"if need be! He has the look of experience about him.\n");

    set_gender(1);
    set_alignment(random(100));
    set_level(10 + random(3)); /* add a little variation */
    set_max_hp(200);
    set_hp(200);

    races = ({ "half elf", "halfling", "human", "dwarf", });
    set_race(races[random(sizeof(races))]);
  
    add_money(300 + random(100));

    add_class("mage");
    add_class("cleric");
    add_class("thief");

    load_spells(10,({ "magic missile",
	"cure serious wounds", "chill touch",
	"acid arrow", "cure light wounds",
	"curse", "bless", "shield",
    }));

    load_chat(5, ({ "Guard says: Ok, move along, no loitering thankyou.\n",
       "Guard wipes the blade of his weapon.\n",
	"Guard says: Welcome to our fair city traveller.\n",
	"Guard asks: What is your business in Ille Coronos?\n",
       "Guard looks about himself.\n",
       "Guard looks at you.\n",
       "Guard smiles happily.\n",
       "Guard says: No trouble from you I hope.\n",
    }));

    load_a_chat(6, ({ "Guard exclaims: Hey! That's not allowed!\n",
	"Guard says: You'll never get away with this!\n",
       "Guard shouts: Help!! Help me!! Bandits!!\n",
       "Guard exclaims: I'll report you to Curzon\n",
	"Guard exclaims: Thief! Bandit! Curzon will hear about this!\n",
    }));

    make_items();
    set_heart_ob(this_object());
  }
}


void monster_heart_beat() {
  object *env, attack;
  int i;

  env = all_inventory(environment());
  for(i=0; i<sizeof(env); i++) {
    if(env[i]->id("guard") &&
      env[i] != this_object() &&
      !query_attack()) {
      if(attack=(env[i]->query_attack())) {
        write("Guard comes to the aid of his friend.\n");
        tell_object(attack, "Guard starts to attack you!\n");
        attack->hit_player(random(query_wc()));
      }
    }
  }
}


void make_items() {
  mixed *weapon_things;
  int weapon_number;

  weapon_things = ({
     ({ "broadsword",     42, 12, "slash",   870,  }),
     ({ "longsword",      42, 13, "slash",   1500, }),
     ({ "twohandedsword", 72, 14, "cleave",  2000, }),
     ({ "shortsword",     24, 10, "slash",   420,  }),
     ({ "scimitar",       36, 10, "slash",   420,  }),
     ({ "claymore",       72, 14, "cleave",  2000, }),
     ({ "khopesh",        42, 11, "slash",   620,  }),
     ({ "rapier",         48, 12, "pierce",  870,  }),
  });

  weapon_number = random(sizeof(weapon_things));
  if(!present("sword")) {
    sword = clone_object(WEAPON);
    sword -> set_name(weapon_things[weapon_number][0]);
    sword -> set_short("An iron "+weapon_things[weapon_number][0]);
    sword -> set_alias("sword");
    sword -> set_long(
          "This fine weapon bears the insignia of the city guard    \n"+
          "of Ille Coronos. Although well used it is in reasonable "+
          "condition.\n");
    sword -> set_length(weapon_things[weapon_number][1]);
    sword -> set_weight(6);
    sword -> set_wc(weapon_things[weapon_number][2]);
    sword -> set_type(weapon_things[weapon_number][3]);
    sword -> set_value(weapon_things[weapon_number][4]);
    move_object(sword, this_object());
    init_command("wield sword");
  }
  if(!present("armour")) {
    armour = clone_object(ARMOUR);
    armour -> set_name("chainmail");
    armour -> set_plural("suits of chainmail");
    armour -> set_ac(3);
    armour -> set_type("armour");
    armour -> set_weight(4);
    armour -> set_value(1200);
    armour -> set_short("A suit of chainmail");
    armour -> set_long(
          "A suit of chainmail armour that bears the crest of the \n"+
          "guards of the city of Ille Coronos. It smells of sweat.\n"+
	   "Obviously it has been well used.\n");
    move_object(armour, this_object());
    init_command("wear armour");
  }

  this_object()->set_ac(9 + random(3));   /* just to make sure */
  this_object()->set_wc(14 + random(3));
}

