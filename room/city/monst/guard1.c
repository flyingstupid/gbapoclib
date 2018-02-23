#include <mudlib.h>
object sword;
object armour;

inherit MONSTER;
void make_items();
void reset(status arg) {
  ::reset(arg);
  if(arg) make_items();

  else {
    set_name("guard");
    set_short("A city guard");
    set_plural("city guards");
    set_long(
       "This is a simple city guard from the city Tempus.\n"+
       "He is weary from spending long hours at his post.\n"+
       "Although he seems about to fall asleep, you're sure \n"+
       "he knows you're here, and is ready to attack if need be!\n"+
       "He has the look of experience about him.\n");
    set_gender(1);
    set_level(10 + random(3)); /* add a little variation */
    set_race("human");
    add_money(300 + random(100));

    add_class("mage");
    add_class("cleric");
    add_class("thief");
    load_spells(10,({ "magic missile","cure serious wounds","chill touch",}));

    load_chat(5, ({ "Guard says: Ok, move along, no loitering thankyou.\n",
       "Guard wipes the blade of his weapon.\n",
       "Guard looks about himself.\n",
       "Guard looks at you.\n",
       "Guard smiles happily.\n",
       "Guard says: No trouble from you I hope.\n",
    }));

    load_a_chat(6, ({ "Guard exclaims: Hey! That's not allowed!\n",
       "Guard bursts out into tears.\n",
       "Guard says: You'll never get away with this!\n",
       "Guard shouts: Help!! Help me!! Bandits!!\n",
       "Guard exclaims: I'll report you to Earothas!\n",
	"Guard exclaims: Thief! Bandit! Earothas will hear about this!\n",
    }));
    make_items();
  }
}

void init() {
  call_out("chat", 1);
  ::init();
}

void chat() {
  if(!this_player()->query_stealth_on() && !this_player()->query_npc()) {
    tell_object(this_player(), "Guard bows as you arrive.\n");
    say("Guard bows to "+ this_player()->query_name() +".\n", this_player());
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
    sword -> set_alias("sword");
    sword -> set_name(weapon_things[weapon_number][0]);
    sword -> set_short("An iron "+weapon_things[weapon_number][0]);
    sword -> set_long(
          "This simple weapon bears the insignia of the city guard \n"+
          "of the city Tempus. Although well used it is in reasonable "+
          "condition.\n");
    sword -> set_length(weapon_things[weapon_number][1]);
    sword -> set_weight(6);
    sword -> set_plural("iron "+query_name()+"s");
    sword -> set_wc(weapon_things[weapon_number][2]);
    sword -> set_type(weapon_things[weapon_number][3]);
    sword -> set_value(weapon_things[weapon_number][4]);
    move_object(sword, this_object());
    init_command("wield sword");
  }
  if(!present("armour")) {
    armour = clone_object(ARMOUR);
    armour -> set_name("chainmail");
    armour -> set_ac(3);
    armour -> set_type("armour");
    armour -> set_plural("suits of chainmail");
    armour -> set_weight(4);
    armour -> set_value(1200);
    armour -> set_short("A suit of chainmail");
    armour -> set_long(
          "A suit of chainmail armour that bears the crest of the \n"+
          "guards of the city of Tempus. It smells of sweat. Obviously\n"+
          "it has been well used.\n");
    move_object(armour, this_object());
    init_command("wear armour");
  }
  this_object()->set_ac(9 + random(3));   /* just to make sure */
  this_object()->set_wc(14 + random(3));
}
