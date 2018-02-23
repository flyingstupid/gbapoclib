/* simple orc merchant */

#include <mudlib.h>
inherit MONSTER;
object bag, fruit;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("orc");
  set_race("orc");
  set_short("An orc merchant");
  set_long(
     "This orc is attempting to fit into normal society, taking his \n"+
     "wares to the local market place to sell there.\n");
  set_level(1);
  set_hp(50 + random(15)); /* bit of randomness */
  add_money(5 + random(35));
  set_gender(1);
  set_al(100);   /* yes an honest orc */
  set_ac(3);
  set_wc(5);
  load_spells(10, ({ "cw" }));   /* so he can heal himself */
  
  bag = clone_object("objects/bag");
  bag -> set_weight(1);
  move_object(bag, this_object());
  fruit = clone_object("inherit/food");
  fruit -> set_name("berries");
  fruit -> set_strength(2);
  fruit -> set_value(10);
  fruit -> set_weight(1);
  fruit -> set_eater_mess("Yuck! Only an orc could love such a fruit!\n");
  fruit -> set_short("A cluster of Bha-ghakan berries");
  fruit -> set_long("This fruit bears a resemblance to putrified berries.\n"+
                    "Apparently it is an orcish delicasy.\n");
  move_object(fruit, bag);

  fruit = clone_object("inherit/food");
  fruit -> set_name("berries");
  fruit -> set_strength(2);
  fruit -> set_value(10);
  fruit -> set_weight(1);
  fruit -> set_eater_mess("Yuck! Only an orc could love such a fruit!\n");
  fruit -> set_short("A cluster of Bha-ghakan berries");
  fruit -> set_long("This fruit bears a resemblance to putrified berries.\n"+
                    "Apparently it is an orcish delicasy.\n");
  move_object(fruit, bag);

  fruit = clone_object("inherit/food");
  fruit -> set_name("berries");
  fruit -> set_strength(2);
  fruit -> set_value(10);

  fruit -> set_weight(1);
  fruit -> set_eater_mess("Yuck! Only an orc could love such a fruit!\n");
  fruit -> set_short("A cluster of Bha-ghakan berries");
  fruit -> set_long("This fruit bears a resemblance to putrified berries.\n"+
                    "Apparently it is an orcish delicasy.\n");
  move_object(fruit, bag);
  set_heart_ob(this_object());

  load_chat(6, ({ "Orc says: Hullo there.\n",
     "Orc asks: Do you know the way to the markets?\n",
     "Orc looks about himself.\n",
     "Orc asks: There aren't any bandits here, are there?\n",
     "Orc smiles happily.\n",
     "Orc smiles sadly.\n",
     "Orc shakes you hand.\n",
     "Orc whistles a merry tune.\n"
  }));


  load_a_chat(5, ({ "Orc shouts: Help! Thief! Assassin! Murderer!\n",
     "Orc exclaims: You criminal!\n",
     "Orc bursts into tears.\n",
     "Orc says: Why attack a poor honest merchant?\n",
     "Orc says: Please dont hurt me.\n"
  }));
  load_l_chat(9, "orc", ({ "You haven't seen the bandits have you friend?",
     "I wish the bandits would leave us poor honest merchants alone",
     "I hear the bandits congregate to train under the city somewhere",
     "Someone told me to look in Skandles Downfall, the local pub" }));
}

monster_heart_beat() {
  int i;
  object bandit;

  bandit = all_inventory(environment());
  for(i=0; i<sizeof(bandit); i++) { /* this will be a little NPC combat fun */
    if(bandit[i] -> id("bandit") && living(bandit[i])) {
      bandit[i] -> hit_player(0);
      tell_room(environment(),
          "Orc shouts: Help! Stay away you bandit, robber, thief!\n");
    }
    if(bandit[i] ->id("corpse")) {
      tell_room(environment(), "Orc takes corpse.\n");
      move_object(present("corpse"), this_object());
    }
  }
}

catch_tell(string str) {
  string tmp1, tmp2, tmp3;
  if(sscanf(str, "%s%s%s\n", tmp1, tmp2, tmp3)) {
    if(tmp2 == "you.") {
      tell_object(find_living(lower_case(tmp1)), "Orc hugs you back!\n");
      say("Orc hugs "+ capitalize(tmp1) +".\n", find_living(lower_case(tmp1)));
    }
  }
  else if(sscanf(str, "%s says: hullo%s\n", tmp1, tmp2)) {
      tell_room(environment(), "Orc says: Hullo "+ tmp1 +".\n");
  }
}
