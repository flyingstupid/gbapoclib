#ifndef RANGER_H
#define RANGER_H
#define RANGER_HEAL_PERIOD (40 - query_wisdom()/7)

int bowyer;

void heal_ranger(int arg) {
   if(random(RANGER_HEAL_PERIOD)) return;
   if(arg == 0) arg = 1;
   this_object()->adj_all_ranger(arg);
}

void adj_all_ranger(int i) {
  this_object()->adj_all_mage(i);
  this_object()->adj_all_cleric(i);
}


/****************************************************************************/
/* sets */

int set_tracking(int t) {
  return (int)this_object()->set_stealth(t);
}

int set_bowyer(int t)   { return bowyer = t;   }



/**************************************************************************/
/* query */

int query_tracking() {
  return (int)this_object()->query_stealth();
}

int query_bowyer()   { return bowyer;    }

void clear_ranger() {
  object obj;

  bowyer = 0;
  this_object()->clear_fighter();
  this_object()->clear_cleric();
  this_object()->clear_theif();
  this_object()->clear_mage();
  this_object()->set_guild_string(0);
  if (obj = (object)(this_object()->query_ranger_aura_object())) 
    destruct(obj);
} 

void query_ranger_stats() {
  string str;
  object obj;
  obj = this_object();

  write("\n               -=[ Ranger Skills ]=-\n\n");

  /* Ranger alone abilities */
  str = " Tracking: "+(int)obj->query_tracking()+"                         ";
  str = str[0..25];
  str += " Bowyer: "+(int)obj->query_bowyer()+"                            ";
  str = str[0..50];
  write(str+"\n");


  /* Fighter skills for Ranger */
  str  = " Multi attack: "+(int)obj->query_multi_attack()+"                ";
  str  =  str[0..25];
  str  += " Multi opponent: "+(int)obj->query_multi_opponent()+"           ";
  str  = str[0..50];
  str += " Two Weapon: "+(int)obj->query_two_weapon()+"                       ";
  str  = str[0..75];
  write(str+"\n");


  /* Cleric skills for Paladin */
  str  = " Nature sphere: "+(int)obj->query_nature_sphere()+"("+
         (int)obj->query_nature_sphere_points()+")                         ";
  str  = str[0..25];
  str += " Conjuration: "+(int)obj->query_conjuration()+"("+
         (int)obj->query_conjuration_points()+")                           ";
  str  = str[0..50];
  str += " Charm: "+(int)obj->query_charm()+"("+
         (int)obj->query_charm_points()+")                                 ";
  str  = str[0..75];
  write(str+"\n");
}

#endif /* RANGER_H */

