/* A wandering guard */
#include <mudlib.h>
inherit MONSTER;

void chat();
void make_items();

void reset(status arg) {
  ::reset(arg);
  if(arg) {
    make_items();
    return;
  }
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
  add_class("fighter");
/*
  set_wander(25, 1000);
*/
  load_spells(10, ({ "cure light wounds", "ice storm", "chill touch", }));

  load_chat(5, ({ "Guard says: Ok, move along, no loitering thankyou.\n",
     "Guard wipes the blade of his weapon.\n",
     "Guard looks about himself.\n",
     "Guard looks at you.\n",
     "Guard smiles happily.\n",
     "Guard says: No trouble from you I hope.\n" }));

  load_a_chat(6, ({ "Guard exclaims: Hey! That's not allowed!\n",
     "Guard bursts out into tears.\n",
     "Guard says: You'll never get away with this!\n",
     "Guard shouts: Help!! Help me!! Bandits!!\n" }));
  make_items();
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
  object sword, armour;
  mixed *weapon_data;
  int i;
  weapon_data = ({
     ({ "longsword", "An iron longsword", 13, 42, 5, 1800,   }),
     ({ "shortsword", "An iron shortsword", 10, 24, 5, 520,  }),
     ({ "broadsword", "An iron broadsword", 12, 42, 5, 1100, }),
  });
  i = random(sizeof(weapon_data));
  if(!present("sword")) {
    sword = clone_object("inherit/weapon");
    sword -> set_name(weapon_data[i][0]);
    sword -> set_short("An iron "+weapon_data[i][0]);
    sword -> set_long(weapon_data[i][1]);
    sword -> set_wc(weapon_data[i][2]);
    sword -> set_length(weapon_data[i][3]);
    sword -> set_weight(weapon_data[i][4]);
    sword -> set_value(weapon_data[i][5]);
    sword -> set_type("slash");
    sword -> set_plural("iron "+query_name()+"s");
    sword -> set_alias("sword");
    sword -> set_long(
          "This simple weapon bears the insignia of the city guard \n"+
          "of the city Tempus. Although well used it is in reasonable "+
          "condition.\n");
    move_object(sword, this_object());
    init_command("wield sword");
  }
  if(!present("armour")) {
    armour = clone_object("inherit/armour");
    armour -> set_name("chainmail");
    armour -> set_ac(3);
    armour -> set_type("armour");
    armour -> set_weight(4);
    armour -> set_value(1200);
    armour -> set_short("A suit of chainmail");
    armour -> set_long(
          "A suit of chainmail armour that bears the crest of the \n"+
          "guards of the city of Tempus. It smells of sweat. Obviously\n"+
          "it has been well used.\n");
    armour -> set_plural("suits of chainmail");
    move_object(armour, this_object());
    init_command("wear armour");
  }
  set_ac(9 + random(3));
  set_wc(14 + random(3));
}
