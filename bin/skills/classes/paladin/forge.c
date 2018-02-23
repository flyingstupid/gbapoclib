/* Forging Weapons & Armour.
 * (c) Angel, December 1993.
 *
 * This allows players to create standard 'wc' weapons
 * and standard 'ac' items out of metal.
 */

#include <mudlib.h>

#define FILE			"bin/skills/classes/fighter/forge"
#define MAKE_COMPLEXITY       18
#define MOD                   100
#define COUNT_MOD             3

string type, name;
int counter;
object obj;
int wc, ac, weight, value, length;
status wc_flag, ac_flag, start_flag;
status i_made_a_booboo;

status drop(string quit);

string short(status wiz) { return "A piece of metal ore"; }
void long(status wiz) {
  write("A piece of metal which you are trying to forge.\n");
  return;
}

id(str) { return str == "ore" || str == "Forging"; }

/**************************************************************************
 * Starting and Guts of the Fun 
 */


status forge(string str) {
  mixed items;
  int i;
  status weapon;

  wc = 0; ac = 0; wc_flag = 0; ac_flag = 0;
  if(!str) {
    notify_fail("Forge what?\n");
    return 0;
  }
  if(present("Forging", this_player())) {
    object ob;
    ob = present("Forging", this_player());
    write("You stop your "+ob->query_job()+" and start a "+str+".\n");
    ob->drop("quit");
    forge(str);
    return 1;
  }


  if(!present("metal", this_player()) &&
     !present("ore", this_player())) {
    write("You need some basic metal or ore to forge that!\n");
    return 1;
  }

  destruct(present("ore", this_player()));
  items = ({ 
          /* NAME             WC         TYPE          WT      VALUE  LENGTH */

          "sickle",            9,       "slash",       4,        400,      24,
          "dagger",            8,       "slash",       4,        275,      15,
          "dirk",              8,       "slash",       4,        400,      12,
          "knife",             6,       "slash",       4,        90,       12,
          "scimitar",         10,       "slash",       5,        520,      36,
          "broadsword",       12,       "slash",       5,        1100,     42,  
          "falchion",         12,       "slash",       5,        1100,     42,
          "khopesh",          11,       "slash",       5,        770,      42,
          "longsword",        13,       "slash",       6,        1500,     42,
          "shortsword",       10,       "slash",       5,        520,      24,
          "rapier",           12,       "pierce",      5,        1100,     48,
          "sabre",            10,       "slash",       5,        520,      45,
          "cutlass",          11,       "slash",       5,        770,      36,
          "halberd",          13,       "pierce",      6,        1500,     60,  
          "pike",             12,       "pierce",      5,        1100,     60,  
          "lance",            10,       "pierce",      5,        520,      150,
          "ranseur",          11,       "pierce",      5,        770,      96,
          "spear",            10,       "pierce",      5,        520,      70,
          "trident",          10,       "pierce",      5,        520,      50,
          "club",              9,       "crush",       4,        400,      36,
          "flail",            10,       "crush",       5,        520,      48,
          "hammer",           11,       "crush",       5,        770,      24,
          "war hammer",       11,       "crush",       5,        770,      30,
          "staff",            12,       "crush",       5,        1100,     80,
          "rod",              12,       "crush",       5,        1100,     80,
          "mace",             12,       "crush",       5,        1100,     36,
          "battle axe",       12,       "cleave",      5,        1100,     48,  
          "hand axe",          8,       "cleave",      4,        275,      24,
          "axe",              10,       "cleave",      5,        520,      30,
          "twohandedsword",   14,       "cleave",      7,        1600,     72,
          "bastardsword",     13,       "cleave",      6,        1500,     54,
          "morning  star",     9,       "cleave",      4,        400,      24,
          "morningstar",       9,       "cleave",      4,        400,      24,
          "claymore",         14,       "cleave",      7,        1600,     72
  });
  if(member_array(lower_case(str), items) > -1) {
    i = member_array(lower_case(str), items);
    name   = items[i];
    wc     = items[i + 1];
    type   = items[i + 2];
    weight = items[i + 3];
    value  = items[i + 4];
    length = items[i + 5];
    wc_flag = 1;
  }

  else {
    items = ({ "chainmail",   3,        "armour",      5,        800,
               "platemail",   4,        "armour",      6,        1600,
               "fieldplate",  4,        "armour",      5,        2500,
               "fullplate",   4,        "armour",      5,        2500,
               "shield",      1,        "shield",      3,        200,
               "boots",       1,        "boots",       2,        200,
               "gauntlets",   1,        "gloves",      1,        300,
               "helm",        1,        "helm",        1,        300,
               "helmet",      1,        "helm",        1,        300
    });
    if(member_array(lower_case(str), items) > -1) 
      i = member_array(lower_case(str), items); 
    else {
      notify_fail("You cannot make a "+str+".\n");
      return 0;
    }
    name   = items[i];
    ac     = items[i + 1];
    type   = items[i + 2];
    weight = items[i + 3];
    ac_flag = 1;
    value  = items[i + 4];
  }
  write("You begin to forge a "+name+".\n");
  say((string)this_player()->query_name()+" begins to forge a "+name+".\n");
  obj = clone_object(FILE);
  move_object(obj, this_player());
  obj -> start_making
           (name, type, weight, value, wc, ac, wc_flag, ac_flag, length);
  return 1;
}

status start_making(string name, string type, 
                    int weight,  int value,   
                    int wc,      int ac,         
                    status wc_flag, status ac_flag, int length) {
  int chance_to_make, chance_to_fail, difference;
  string tmp1, tmp2;

  if(wc_flag) {
    obj = clone_object(WEAPON);
    chance_to_make = (int)environment()->query_weapon_smith();
  }    
  else {
    obj = clone_object(ARMOUR);
    chance_to_make = (int)environment()->query_armouring();
  }

  if(sscanf((string)environment()->query_race(), "%sdwarf", tmp1))
    chance_to_make += 4;
  if((string)environment()->query_race("gnome"))
    chance_to_make += 2;

  if(!present("forge", environment(environment())) ||
     !present("forge", environment()))
    chance_to_fail += 10;

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
  obj -> set_weight(weight);
  obj -> set_value(value);
  if(ac)
    obj -> set_ac(ac);
  if(wc) {
    obj -> set_wc(wc);
    obj -> set_length(length);
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
      obj -> set_short("A "+name);
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
    else obj -> hit_armour(MOD * difference);
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
      "You discontinue your forging of the "+(string)obj->query_name()+
      " to join the melee.\n");
      drop("quit");
      return 1;
    }
    tell_object(environment(), 
      "You continue to forge your "+(string)obj->query_name()+".\n");
    counter += 1;
    if(ac_flag)
      call_out("finish_making", 60 + (int)obj->query_ac());
    else
      call_out("finish_making", 60 + (int)obj->query_wc());
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
string query_job()  { return (string)obj->query_name(); }


