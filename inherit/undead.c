/* an undead monster with necessary checks for level drain, 
   disease, and chill touch attacks
 */

#include <mudlib.h>
inherit MONSTER;  
 
int drain_chance;  
int disease_chance;  
int chill_dam, chill_chance;  
   
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
}

status id(string str) {
  return str == "undead"
      || ::id(str);
}  


/* support parse_command */
string *parse_command_id_list() {
	return ::parse_command_id_list() + ({ "undead" });
}
   

void attack() {  
  object att;

  ::attack();  
  if(!(att = query_primary_attack()) || !present(att, environment())) {
    return;
  }

  /* level draining */

  if(random(100) < drain_chance) {  
    if(att->query_spell_immunity("draining")) { 
      tell_object(att, "Sparks fly off you at the touch of "+ 
                       query_name() +"\n");
      say("Sparks fly off "+ att->query_name() +" at the touch of "+  
          query_name() +"\n", att);  
    }
    else {
      att->drain_level();
      tell_object(att, query_name() +" touches you, and you feel your "+
                       "life slipping away...\n");  
      say(att->query_name() +" visibly staggers, weakened by "+
          query_name()+"'s touch.\n",att);  
    }
    return;  
  }  
 
  /* disease contagion */

  if(random(100) < disease_chance) {
    if(att->query_spell_immunity("disease")) {
      tell_object(att,"You sniff, but make a quick recovery.\n");
    }
    else { 
      if(!present("Disease", att)) {  

        move_object(clone_object("objects/disease"), att);  
      }
    }
    return; 
  }  
 
  /* chill touch */

  if(random(100) < chill_chance) {
    if(att->query_spell_immunity("cold")) { 
      tell_object(att, query_name() +"'s chill touch does not effect you.\n");
    }
    else {
      tell_object(att, query_name()+"'s touch is deadly cold.\n");  
      att->hit_player(random(chill_dam));  
    }
    return;
  }  
}  
   
/* Sets for chance to happen */

int set_chill_chance(int c)   { return chill_chance = c;    }  
int set_drain_chance(int c)   { return drain_chance = c;    }  
int set_disease(int d)        { return disease_chance = d;  }  
int set_disease_chance(int d) { return disease_chance = d;  }  
int disease_chance(int d)     { return disease_chance = d;  }  

/* Sets for damage */

int set_chill_dam(int c)      { return chill_dam = c;       }  

/* Queries for chance to happen */

int query_drain_chance()      { return drain_chance;        }  
int query_chill_chance()      { return chill_chance;        }  
int query_disease()           { return disease_chance;      }  

/* Queries for damage */

int query_chill_dam()         { return chill_dam;           }  

void init() {
  ::init();
  set_spell_immune(({ "fear", "charm", "cold", "draining", "darkness", }));
}


string query_object_type() { return "Undead"; }
