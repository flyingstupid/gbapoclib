/* Forging Weapons & Armour.
 * (c) Angel, December 1993.
 * Revised Angel, August 1996.
 *
 * This allows players to create standard 'wc' weapons
 * and standard 'ac' items out of metal.
 */

#include <mudlib.h>

#define FILE		      "bin/skills/classes/fighter/forge"
#define BOW                   "objects/bow"
#define ARROW                 "objects/arrow"

#define MAKE_COMPLEXITY       16
#define MOD                   50
#define COUNT_MOD             3

#define DWARF_BONUS           5
#define GNOME_BONUS           3

static string type, name;
static int counter;
static object obj;
static int wc, ac, weight, value, length;
static status wc_flag, ac_flag, start_flag, missile_flag;
static status flag;
static status i_made_a_booboo;

status drop(string quit);

status set_missile_flag(int i) { return flag = i; }
string short(status wiz) {
  if(flag)
    return "A piece of wood";
  else
    return "A piece of metal ore";
}


void long(status wiz) {
  if(flag)
    write("It looks like your trying to craft some sort of missile-weapon.\n");
  else
    write("A piece of metal which you are trying to forge.\n");
  return;
}

status id(string str) {
  return str == "ore" ||
         str == "wood" ||
         str == "spell" ||
         str == "Forging";
}

/**************************************************************************
 * Starting and Guts of the Fun 
 */


status forge(string str, mixed alt_type) {
  mapping items;
  mixed *types;
  string *missile_types;
  int i;
  status weapon;
  object ob;

  wc = 0; ac = 0; wc_flag = 0; missile_flag = 0; ac_flag = 0;
  name = 0;

  if(!str) {
    notify_fail("Forge what?\n");
    return 0;
  }

  if(str == "bow") {
    notify_fail("Craft what kind of bow? Shortbow? Longbow?\n");
    return 0;
  }


  if(alt_type == "bowyer")
    missile_types = ({
    "longbow", "shortbow", "arrow", "bolt", "crossbow",
  });

  if(ob = present("Forging", this_player())) {
    write("You stop your "+ob->query_job()+" and start a "+str+".\n");
    ob->drop("quit");
     forge(str, 0);
    return 1;
  }


  if(str == "arrow" || str == "bolt") {
    if(!present("arrow head", this_player())) {
      notify_fail("You need an arrow or bolt head before you can "+
      "make a "+str+"\n");
      return 0;
    }
  }
  else if(!present("metal", this_player()) &&
     !present("ore", this_player())    &&
     alt_type == "bowyer" &&
     (member_array(str, missile_types) == -1)) {
    write("You need some basic metal or ore to forge that!\n");
    return 1;
  }
  else {
    if(!present("ore", this_player()) &&
       !present("metal", this_player())) {
      write("You need some basic metal or ore to forge that!\n");
      return 1;
    }
  }


  if(alt_type == "bowyer")
  if(member_array(str, missile_types) != -1 &&
     !present("wood", this_player())) {
    notify_fail("You require some wood to craft a "+str+".\n");
    return 0;
  }



/*
  types = ({
	"pierce", "slash", "crush", "cleave",
	"armour", "boots", "amulet", "helm",
  });

  if((int)this_player()->query_bowyer())
    types += missile_types;

  str = lower_case(str);

  if(member_array(str, types) != -1) {
    notify_fail("Forge what kind of "+str+"?\n");
    return 0;
  }
*/

  items = ([
        "sickle"        :  ({   9, "slash",  4,  400, 24,  }),
        "dagger"        :  ({   8, "slash",  4,  275, 15,  }),
        "dirk"          :  ({   8, "slash",  4,  400, 12,  }),
        "knife"         :  ({   6, "slash",  4,   90, 12,  }),
        "scimitar"      :  ({  10, "slash",  5,  520, 36,  }),
        "broadsword"    :  ({  12, "slash",  5, 1100, 42,  }),
        "falchion"      :  ({  12, "slash",  5, 1100, 42,  }),
        "khopesh"       :  ({  11, "slash",  5,  770, 42,  }),
        "longsword"     :  ({  13, "slash",  6, 1500, 42,  }),
        "shortsword"    :  ({  10, "slash",  5,  520, 24,  }),
        "rapier"        :  ({  12, "pierce", 5, 1100, 48,  }),
        "sabre"         :  ({  10, "slash",  5,  520, 45,  }),
        "cutlass"       :  ({  11, "slash",  5,  770, 36,  }),
        "halberd"       :  ({  13, "pierce", 6, 1500, 60,  }),
        "pike"          :  ({  12, "pierce", 5, 1100, 60,  }),
        "lance"         :  ({  10, "pierce", 5,  520, 150, }),
        "ranseur"       :  ({  11, "pierce", 5,  770, 96,  }),
        "spear"         :  ({  10, "pierce", 5,  520, 70,  }),
        "trident"       :  ({  10, "pierce", 5,  520, 50,  }),
        "club"          :  ({   9, "crush",  4,  400, 36,  }),
        "flail"         :  ({  10, "crush",  5,  520, 48,  }),
        "horsemansflail":  ({  10, "crush",  5,  520, 48,  }),
        "footmansflail" :  ({  10, "crush",   5,  520, 48, }),
        "hammer"        :  ({  11, "crush",  5,  770, 24,  }),
        "warhammer"     :  ({  11, "crush",  5,  770, 30,  }),
        "staff"         :  ({  12, "crush",  5, 1100, 80,  }),
        "rod"           :  ({  12, "crush",  5, 1100, 80,  }),
        "mace"          :  ({  12, "crush",  5, 1100, 36,  }),
        "footmansmace"  :  ({  12, "crush",  5, 1100, 36,  }),
        "horsemansmace" :  ({  12, "crush",  5, 1000, 36,  }),
        "battleaxe"     :  ({  12, "cleave", 5, 1100, 48,  }), 
        "handaxe"       :  ({   8, "cleave", 4,  275, 24,  }), 
        "axe"           :  ({  10, "cleave", 5,  520, 30,  }), 
        "twohandedsword":  ({  14, "cleave", 7, 1600, 72,  }), 
        "bastardsword"  :  ({  13, "cleave", 6, 1500, 54,  }), 
        "morning  star" :  ({   9, "cleave", 4,  400, 24,  }),
        "morningstar"   :  ({   9, "cleave", 4,  400, 24,  }),
        "claymore"      :  ({  14, "cleave", 7, 1600, 72,  }),
  ]);

  if(alt_type == "bowyer") { /* ie, we're crafting a bow/arrow only */
    items += ([
        "shortbow"      :  ({   0,  "missile", 0, 1000, 10000, }),
        "longbow"       :  ({   0,  "missile", 0, 1000, 10000, }),
        "crossbow"      :  ({   0,  "missile", 0, 1000, 10000, }),
        "arrow"         :  ({   0,  0,         0,    0,     0, }),
        "bolt"          :  ({   0,  0,         0,    0,     0, }),
    ]);

    if(!types = items[str]) { /* if str does not return valid array */
      notify_fail("You can not make a "+str+"\n");
      return 0;
    }

    if(items[str]) {
      name = str;
      missile_flag = 1;
    }
  }

  else if(types = items[str]) {
      i = 0;
      name = str;

      wc     = types[i];
      type   = types[i + 1];
      weight = types[i + 2];
      value  = types[i + 3];
      length = types[i + 4];

      wc_flag = 1;
  }

  else if((int)this_player()->query_armouring()) {
    items = ([ "chainmail" : ({ 3,        "armour",      5,        800,  }),
               "platemail" : ({ 4,        "armour",      6,        1600, }),
               "fieldplate": ({ 4,        "armour",      5,        2500, }),
               "fullplate" : ({ 4,        "armour",      5,        2500, }),
               "shield"    : ({ 1,        "shield",      3,        200,  }),
               "boots"     : ({ 1,        "boots",       2,        200,  }),
               "gauntlets" : ({ 1,        "gloves",      1,        300,  }),
               "helm"      : ({ 1,        "helm",        1,        300,  }),
               "helmet"    : ({ 1,        "helm",        1,        300   }),
    ]);

    if(types = items[str]) {
       i = 0;
       name = str;
       ac     = types[i];
       type   = types[i + 1];
       weight = types[i + 2];
       value  = types[i + 3];
       ac_flag = 1;
    }
  }
  
  if(!name) {
    write("You can not make a "+ str +".\n");
    return 1;
  }

  write("You begin to make a "+name+".\n");
  say((string)this_player()->query_name()+" begins to make a "+name+".\n");
  obj = clone_object(FILE);
  if(missile_flag)
    obj -> set_missile_flag(1);


  if(present("ore", this_player()) && alt_type != "bowyer")
    destruct(present("ore", this_player()));
  else { 
    if(present("wood", this_player()))
      destruct(present("wood", this_player()));
    if(str == "bolt" || str == "arrow")
      destruct(present("arrow head", this_player()));
  }

  move_object(obj, this_player());
  obj -> start_making
(name, type, weight, value, wc, ac, wc_flag, ac_flag, length, missile_flag);
  return 1;
}

status start_making(string name, string type, 
                    int weight,  int value,   
                    int wc,      int ac,         
                    status wc_flag, status ac_flag,
                    int length, status missile_flag) {
  int chance_to_make, chance_to_fail, difference;
  string tmp1, tmp2, race;


  if(wc_flag) {
    obj = clone_object(WEAPON);
    chance_to_make = (int)environment()->query_weapon_smith();
  }    

  if(ac_flag) {
    obj = clone_object(ARMOUR);
    chance_to_make = (int)environment()->query_armouring();
  }

  if(missile_flag) {
    if(name == "bolt" || name == "arrow")
      obj = clone_object(ARROW);
    else
      obj = clone_object(BOW);
    chance_to_make = (int)environment()->query_bowyer();
  }

  race = (string)this_player()->query_race();

  if(!missile_flag) {
    if(sscanf(race, "%sdwarf%s", tmp1, tmp2))
      chance_to_make += DWARF_BONUS;
    if(sscanf(race, "%sgnome%s", tmp1, tmp2))
      chance_to_make += GNOME_BONUS;
  }

/*
  if(!missile_flag) {
    if(!present("forge", environment(environment())) ||
       !present("forge", environment()))
      chance_to_fail += 10;
  }
*/

  if(chance_to_make) chance_to_make = random(chance_to_make);
  chance_to_fail = random(MAKE_COMPLEXITY);
  difference = chance_to_fail - chance_to_make;

  if(chance_to_make < chance_to_fail) {
    weight += random(weight / 2);
    value -= random(value/4);
    if(wc_flag)
      wc -= random(wc/3);
    if(ac_flag && ac > 1)
      ac -= 1;
    i_made_a_booboo = 1;
  }
      
  obj -> set_name(name);

  if(!missile_flag) {
    obj -> set_weight(weight);
    obj -> set_value(value);
  }

  if(ac)
    obj -> set_ac(ac);

  if(wc) {
    obj -> set_wc(wc);
    obj -> set_length(length);
  }
  if(missile_flag) {
    if(name == "longbow" || name == "shortbow")
      obj -> set_ammunition("arrow");
    else if(name == "crossbow")
      obj -> set_ammunition("bolt");
  }

  if(sscanf(name, "%ssword", tmp1))
    obj -> set_alias("sword");

  obj -> set_type(type);

  if(type == "boots" || type == "gloves") {
    obj -> set_short("A pair of "+name);
    if(i_made_a_booboo)
      obj -> set_long("A badly crafted pair of metal "+name+", made by "+
                     (string)environment()->query_name()+".\n");
    else
      obj -> set_long("A finely designed pair of metal "+name+", made by "+
                     (string)environment()->query_name()+".\n");
  }

  else if(type == "shield") {
    obj -> set_short("A shield");
    if(i_made_a_booboo)
      obj -> set_long("A badly designed shield, made by "+
                     (string)environment()->query_name()+".\n");
    else
      obj -> set_long("A finely designed shield, made by "+
                     (string)environment()->query_name()+".\n");
  }
   
  else {
 
    if(ac_flag) {
      obj -> set_short("A suit of "+name);
      if(i_made_a_booboo) {
        obj -> set_long("A badly designed suit of "+name+", made by "+
                       (string)environment()->query_name()+".\n");
      }
      else
        obj -> set_long("A finely designed suit of "+name+", made by "+
                       (string)environment()->query_name()+".\n");
    }

    else {
      if(name[0] == "a"[0]) obj -> set_short("An "+name);
      else obj -> set_short("A "+name);
      if(i_made_a_booboo)
        obj -> set_long("A badly crafted "+name+", made by "+
                       (string)environment()->query_name()+".\n");
      else
        obj -> set_long("A finely crafted "+name+", made by "+
                       (string)environment()->query_name()+".\n");      
    }
  }

  if(i_made_a_booboo) {
    if(wc) obj -> hit_weapon(MOD * difference); 
    if(ac) obj -> hit_armour(MOD * difference);

    if(!obj) {
      remove_call_out("start_making");
      remove_call_out("finish_making");
      return 1;
    }

  }

  call_out("finish_making", ac);
  return 1;
}

status finish_making() {
  if(counter < COUNT_MOD) {
    if(environment()->query_attack()) {
      tell_object(environment(),
      "You discontinue your making of the "+(string)obj->query_name()+
      " to join the melee.\n");
      drop("quit");
      return 1;
    }
    if(!missile_flag)
      tell_object(environment(), 
      "You continue to forge your "+(string)obj->query_name()+".\n");
    else
      tell_object(environment(),
      "You continue to craft your "+(string)obj->query_name()+".\n");
    counter += 1;
    if(ac_flag)
      call_out("finish_making", 60 + (int)obj->query_ac());
    else if(wc_flag)
      call_out("finish_making", 60 + (int)obj->query_wc());
    else
      call_out("finish_making", 70);
    return 1;
  }
  move_object(obj, environment());
  tell_object(environment(),
    "You finish making your "+(string)obj->query_name()+".\n");
  destruct(this_object());
  return 1;
}

status drop(string quit) {
  if(quit) {
    remove_call_out("finish_making");
    if(obj) destruct(obj);
    destruct(this_object());
  }
  return 1;
}

string query_name() { return "Forging";                 }
//string query_job()  { return (string)obj->query_name(); }
string query_job() {
  if (!obj)  return "unknown object";
  if (!obj->query_name() || (obj->query_name() == ""))
    return "unknown object";
  return obj->query_name();
}



