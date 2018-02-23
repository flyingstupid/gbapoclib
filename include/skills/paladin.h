#ifndef PALADIN_H
#define PALADIN_H
#define PALADIN_HEAL_PERIOD (30 - query_wisdom()/6)

void heal_paladin(int arg) {
   if(random(PALADIN_HEAL_PERIOD)) return;
   if(arg == 0) arg = 1;
   this_object()->adj_all_cleric(arg);
}

void adj_all_paladin(int i) {
  this_object()->adj_all_cleric(i);
}

status query_weapon_spec(string str);

string *weapon_spec;                    /* the array of specialised weapons */
int sword_spec;                         /* bonus for WC w/- sword           */
int crushing_spec;                      /* bonus for WC w/- mace            */
int lance_spec;                         /* bonus for WC w/- lance           */
int shield_spec;                        /* hit for shield                   */


/****************************************************************************/
/* sets */

void add_weapon_spec(string str){
  if(!query_weapon_spec(str) && str) weapon_spec += ({ str, });
}

void remove_weapon_spec(string str){
  int i;
  if((i=member_array(str, weapon_spec)) != -1){
    weapon_spec = weapon_spec[0..i-1] +
    weapon_spec[i+1..sizeof(weapon_spec)-1];
  }
}

int set_sword_spec(int i)    { return sword_spec = i;    }
int set_lance_spec(int i)    { return lance_spec = i;    }
int set_crushing_spec(int i) { return crushing_spec = i; }
int set_shield_spec(int i)   { return shield_spec = i;   }

mixed set_horse_info(string *arr) { 
  return this_object()->add_player_info("paladin's warhorse", arr);
}


/**************************************************************************/
/* query */

int query_sword_spec()    { return sword_spec;    }
int query_lance_spec()    { return lance_spec;    }
int query_crushing_spec() { return crushing_spec; }
int query_shield_spec()   { return shield_spec;   }

mixed query_horse_info()  {
  return this_object()->query_player_info("paladin's warhorse");
}

mixed query_weapon_spec(string str) {
  if(!weapon_spec) weapon_spec = ({});
  if(!str) return weapon_spec;
  return (member_array(str, weapon_spec) == -1) ? 0 : 1;
}


void clear_paladin() {
  object obj;
  sword_spec = 0;
  crushing_spec = 0;
  lance_spec = 0;
  shield_spec = 0;
  weapon_spec = ({});
  this_object()->remove_player_info("paladin's warhorse");
  this_object()->clear_fighter();
  this_object()->clear_cleric();
  this_object()->set_guild_string(0);
  if ( obj = (object)(this_object()->query_paladin_aura_object()) )
    destruct(obj);
} 

void query_paladin_stats() {
  string str;
  object obj;
  obj = this_object();

  write("\n               -=[ Paladin Skills ]=-\n\n");

  str = "Weapons of choice: "+
  implode(query_weapon_spec(0), " ")+"                                   ";
  write(str+"\n\n");

  str  = "Sword spec: "+sword_spec+"                                     ";
  str  = str[0..25];
  str += " Lance spec: "+lance_spec+"                                    ";
  str = str[0..75];
  write(str+"\n");

  str  = "Crushing spec: "+crushing_spec+"                               ";
  str  = str[0..25];
  str += " Shield spec: "+shield_spec+"                                   ";
  str = str[0..50];

  /* Fighter skills for Paladin */
  str += " Multi attack: "+(int)obj->query_multi_attack()+"              ";
  str = str[0..75];
  write(str+"\n");

  str  = "Multi opponent: "+(int)obj->query_multi_opponent()+"           ";
  str  = str[0..25];
  str += " Armouring: "+(int)obj->query_armouring()+"                    ";
  str  = str[0..50];
  str += " Weapon smith: "+(int)obj->query_weapon_smith()+"              ";
  str  = str[0..75];
  write(str+"\n");


  /* Cleric skills for Paladin */
  str  = "Healing sphere: "+(int)obj->query_healing_sphere()+"("+
         (int)obj->query_healing_sphere_points()+")                     ";
  str  = str[0..25];
  str += " Combat sphere: "+(int)obj->query_combat_sphere()+"("+
         (int)obj->query_combat_sphere_points()+")                      ";
  str  = str[0..50];
  str += " Protection sphere: "+(int)obj->query_protection_sphere()+"("+
         (int)obj->query_protection_sphere_points()+")                  ";
  str  = str[0..80];
  write(str+"\n");
}

#endif /* PALADIN_H */

