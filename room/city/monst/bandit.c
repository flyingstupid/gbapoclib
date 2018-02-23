#include <mudlib.h>
inherit MONSTER;
object armour, cloak, knife;

void make_items();
void reset(status arg) {
  ::reset(arg);
  if(arg) make_items();
  
  set_name("bandit");
  set_race("human");
  set_gender(1);
  set_short("A simple bandit");
  set_long(
     "This bandit is attempting to look rough and tough in an \n"+
     "attempt to steal money from peole. He hasn't yet succeeded. \n"+
     "Bandit is human.\n");
  set_level(2);
  set_hp(60);
  add_money(10 + random(20));
  set_al(-100);
  load_chat(10, ({ "Bandit looks at you with shifty eyes.\n",
     "Bandit sneazes due to the night air.\n",
     "Bandit shivers in the night air.\n",
     "Bandit says: Hey, give me your money.\n",
     "Bandit exclaims: I gotta make a living somehow!\n",
     "Bandit eyes your money pouch.\n",
     "Bandit asks: Please, can you give me your money?\n"
  }));

  load_a_chat(12, ({ "Bandit exclaims: Help! Guards! I'm being robbed!\n",
     "Bandit says: You big meanie.\n",
     "Bandit tries to run away, but fails!\n",
     "Guard cries out for help.\n"
  }));
  msgin  = "sneaks in";
  msgout = "sneaks out";
  set_heart_ob(this_object());
  make_items();
}

void make_items() {
  int i;
  if(!present("armour")) {
    armour = clone_object(ARMOUR);
    armour -> set_name("bracers");
    armour -> set_alias("bands");
    armour -> set_type("armour");
    armour -> set_alt_name("arm bands");
    armour -> set_ac(1);
    armour -> set_weight(2);
    armour -> set_short("A pair of golden arm bands");
    armour -> set_long("These golden bracers have many strange runes \n"+
               "enscribed into its surface. Perhaps they are magical?\n");
    armour -> set_value(200);
    armour -> set_enchanted(1);
    armour -> set_info("These are bracers of defence");
    armour -> set_armour_material("mithril");
    move_object(armour, this_object());
    command("wear armour",this_object());
  }

  if(!present("cloak")) {
    cloak = clone_object("inherit/clothing");
    cloak -> set_name("cloak");
    if(!random(2)) {
      cloak -> set_short("A black hooded cloak");
      cloak -> set_long(
     "A simple black hooded cloak. Ideal for cold n  ights.\n");
    }
    else {
      cloak -> set_short("A grey hooded cloak");
      cloak -> set_long("A simple grey hooded cloak. Ideal for cold nights.\n");
    }
    cloak -> set_weight(1);
    cloak -> set_value(50);
    cloak -> set_sell_destruct(1);
    move_object(cloak, this_object());
    command("wear cloak",this_object());
  }

  if(!present("knife")) {
    for(i=0; i<2; i++) {
      knife = clone_object(WEAPON);
      knife -> set_length(12);
      knife -> set_wc(6);
      knife -> set_weight(3);
      knife -> set_value(110);
      knife -> set_type("slash");
      knife -> set_name("knife");
      knife -> set_short("A knife");
      knife -> set_long("A simple knife. The workmanship is rather average.\n"); 
      move_object(knife, this_object());
    }
    init_command("wield knife");
    init_command("wield knife 2 in left hand");
  }
  this_object()->set_ac(3);
  this_object()->set_wc(6);
}

void monster_heart_beat() {
  string tmp1, tmp2;
  int i;
  object *obj;

  obj = all_inventory(environment());
  for(i=0; i<sizeof(obj); i++) {
    if(obj[i] -> id("corpse")) {
      tell_room(environment(), "Bandit takes corpse.\n");
      move_object(present("corpse"), this_object());
    }
  }
}


void catch_tell(string str) {
  string tmp1, tmp2, tmp3, tmp4;
  int i;

  if(sscanf(str, "%s%s%s%s\n", tmp1, tmp2, tmp3, tmp4)) {
    if(sscanf(tmp2, "%d coins", i)) {
      tell_room(environment(), "Bandit says: Thanks buddie.\n"+
          "Bandit leaves for the pub.\n");
      move_object(this_object(), PUB);
    }
  }
  else if(sscanf(str, "%s says: %s\n", tmp1, tmp2)) {
    if(sscanf(tmp2, "hullo%s", tmp3)) {
      tell_room(environment(), 
      "Bandit says: Hi there "+ capitalize(tmp1)+"\n");
    }
    else if(sscanf(tmp2, "bye%s", tmp3)) {
      tell_room(environment(),
      "Bandit says: Byebye "+ capitalize(tmp1) +"\n");
    }
  }
  else if(sscanf(str, "%s leaves%s\n", tmp1, tmp2)) {
    command(tmp2, this_object()); /* follows you */
  }
}
