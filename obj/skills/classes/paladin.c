/***************************************************************************/
/* Paladin's Guild Object. v1.01 
 * Angel, August 1994 for Heaven7 development
 */


/***************************************************************************/
/* defines */

#include <tell.h>

static status flag, has_holy_sword;
static object horseOb;
static int timer;

#define GOD                   "the All-God"
#define PALADIN_ALIGNMENT     100   /* min alignment for paladin powers    */
#define MAGIC_RESISTANCE      25    /* magic resistance w/- holy sword     */
#define LANCE_MOD             3/2     /* +1 dmg per stat mod bonus           */
#define SWORD_MOD             2
#define CRUSH_MOD             5/2
#define LEVEL_FOR_TWO_HANDED  15
#define HORSE_BONUS		((int)environment()->query_level()/2)

#define MOD1 1
#define MOD2 1

#define DISEASE_WAIT_TIME     3600  /* 1 hour wait to cast cure disease    */
#define EVIL_BONUS            10    /* +10 damage vs evils w/- holy sword  */
#define PENALTY               -5    /* penalty for shield attack left hand */

#define ALIGNMENT             (int)environment()->query_alignment()
#define MSG_DAM               3     /* hp between messages from living.c   */

#define THIS_PLAYER_WIZ    ((this_player()->query_security_level()) ? 1 : 0)


/***************************************************************************/
/* fn configs */
status check_for_holy_sword(object obj);
status check_alignment();
status paladin_armour_types(object obj);
status wear_func(object obj);
int    right_weapon_class_bonus();
int    calc_shield_wc();
void   init_arg();
void   paladin_bonuses();
void   process_alignment(int amount);
void   process_alignment_fun(int amount);
void   kill_paladin();
void   reset_time();


/*********************************************************************/
/* queries */
string query_name()        { return "paladin guild object"; }
string query_object_type() { return "guild_object";         }

status query_auto_load()   { return 1;                      }

int right_weapon_class_bonus() {
  string weapon_name, tmp1, tmp2;
  object weapon;
  int evil_bonus;

  weapon = (object)environment()->query_right_weapon();

  if(weapon) {
    weapon_name = (string)weapon->query_name();
    if(environment()->query_weapon_spec(weapon_name)) {
      if(sscanf(weapon_name, "%slance%s", tmp1, tmp2)) {
        if(environment()->query_horse_object()) {
          if(!random(2)) {
            tell_object(environment(), "You attack valiantly from horseback.\n");
            say(environment()->query_name()+" attacks valiantly from "+
            "horseback!\n", environment());
          }
          return ((int)environment()->query_lance_spec()/LANCE_MOD) + (HORSE_BONUS);
        }
        else
          return ((int)environment()->query_lance_spec() / LANCE_MOD);
      }
      if(weapon->query_type() == "crush") 
        return ((int)environment()->query_crush_spec() / CRUSH_MOD); 
      else {
        if(has_holy_sword) evil_bonus += EVIL_BONUS;
        evil_bonus += ((int)environment()->query_sword_spec() / SWORD_MOD);
        return evil_bonus;
      }
    }
  }
  return 0;
}

/***************************************************************************
 * Same attack fun from living.c                                           
 */

void query_extra_attack() {
  object shield, who;
  string *msg;
  int dam, dmg, size;

  dmg = (int)calc_shield_wc();
  who = (object)environment()->query_attack();

  if(!dmg) return;
  if(!who) return;
  if(!environment()->query_class("paladin")) {
    destruct(this_object());
    return;
  }

  msg = ({
     "missed",   "", 
     "grazed",   "with next to no force",  
     "bruised",  "slightly, with a weak strike",  
     "hit",      "in the body",  
     "swatted",  "\b, doing a fair amount of damage",  
     "cracked",  "with a hard hit to the body",  
     "smashed",  "across the head with a devestating blow",  
     "crushed",  "into a bloody mess",
  });
  

  size = sizeof(msg);
  dmg = (dmg > 0) ? random(dmg) + 1 : 0;  
  dam = ((dmg+MSG_DAM-1)/MSG_DAM > (size/2)-1) 
      ? ((size/2)-1)
      : ((dmg+MSG_DAM-1)/MSG_DAM);  
  dam *= 2;

  tell_object(environment(), "You "+ msg[dam] +" "+ who->query_name() +
          ((msg[dam+1] == "") ? "" : " ") + msg[dam+1] + 
          " with your shield"+
          ((THIS_PLAYER_WIZ) ? " ["+dmg+"pts]" : "")+".\n");
  tell_objects(all_inventory(environment(environment())), 
          environment()->query_name()+" "+msg[dam]+" "+who->query_name()+
          ((msg[dam+1] == "") ? "" : " ") + msg[dam+1] +" with "+
          environment()->query_possessive()+" shield.\n", 
          ({ who, environment(), }));

  tell_object(who, environment()->query_name() +" "+ msg[dam] +" you"+
               ((msg[dam+1] == "") ? "" : " ") + msg[dam+1] +
               " with "+environment()->query_possessive()+" shield"+
               ((who->query_security_level()) ? " ["+dmg+"pts]" : "")+".\n");

  who->hit_player(dam);
}


int calc_shield_wc() {
  int i, j;
  object obj;

  for(i=0; (obj = present("shield "+i, environment())); i++) {
    if(obj->query_worn()) {
      j = ((((int)environment()->query_shield_spec()*MOD1)/MOD2) +
         ((int)obj->query_ac()));
      if(environment()->query_horse_object()) {
        if(!random(2)) {
          tell_object(environment(), "You attack valiantly from horseback.\n");
          say(environment()->query_name()+" attacks valiantly from "+
          "horseback!\n", environment());
        }
        j += HORSE_BONUS;
      }
      return j;
    }
    else {
      return 0;
    }
  }
}

/****************************************************************************
 * A paladin can wield any type of weapon, but certain types gain them 
 * WC bonuses.
 */
status wield_func(object obj) {
  if(((int)obj->query_length() > 60)         &&
     ((string)obj->query_type() != "pierce") &&
     ((int)environment()->query_level() < LEVEL_FOR_TWO_HANDED)) {
     write("The "+obj->short()+" calls into question your personal bravery.\n"+
     "Such a weapon is avoided by all but the most powerful of paladin!\n");
     return 1;
  }
  if(this_player()->query_right_weapon()) {
    write("A paladin never wields two weapons simultaneously.\n"+
     "Such combat is the art of theives and peasants!\n");
    return 1;
  }
  if(check_for_holy_sword(obj)) {
    tell_object(environment(),"You feel your sword has great power for good, against evil...\n");
    has_holy_sword = 1;
  }

  return 0;
}

status check_alignment() {
  if(ALIGNMENT > PALADIN_ALIGNMENT) return 1;
  return 0;
}

void process_alignment(int amount) {
  if(!flag) {
    flag = 1;
    call_out("process_alignment_fun", 1, amount);
  }
}

/* Call out for the effect only */
void process_alignment_fun(int amount) {
  string *message, msg;

  message = ({
     "You donot feel that was a good and wise thing to do.\n",
     "You feel that was not a noble act.\n",
     "You have displeased "+GOD+" with that action.\n",
      GOD+" regards your act with distain.\n",
     "You have discraced the name of "+GOD+" with that action.\n",
     "You feel the wrath of "+GOD+" upon you!\n",
  });

  if(check_alignment()) return;
  if((ALIGNMENT - amount) > 50)
    msg = message[0];
  else if((ALIGNMENT - amount) > 0)
    msg = message[1];
  else if((ALIGNMENT - amount) > -50)
    msg = message[2];
  else if((ALIGNMENT - amount) > -100)
    msg = message[3];
  else if((ALIGNMENT - amount) > -150)
    msg = message[4];
  else
    msg = message[sizeof(message)-1];

  tell_object(environment(), msg);
  if(msg == message[sizeof(message)-1]) {
    say(environment()->query_name()+" is struck with a bolt of lightning "+
     "from the heavens!\n",environment());
    kill_paladin();
  }
}

/**********************************************************************
 * A Paladin must always be pure of heart and noble of stature
 * hence, his alignment must never be 'evil'. If he becomes
 * evil, then the wrath of his God falls upon him, and he dies.
 */
void kill_paladin() {
  if(!environment()) return;
  environment()->set_alignment(PALADIN_ALIGNMENT);
  environment()->death();
  say(GOD+"'s wrath has been appeased.\n",environment());
  flag = 0;
}

status check_for_holy_sword(object obj) {
  object weapon;
  string *holy_sword_ids;
  int i;

  holy_sword_ids = ({
     "holy sword", "holy avenger", "avenger",
  });
  if(obj && check_alignment()) {
    for(i=0; i<sizeof(holy_sword_ids); i++) {
      if(obj->id(holy_sword_ids[i])) {
        environment()->set_magic_resist(MAGIC_RESISTANCE);
        return 1;
      }
    }
  }
  return 0;
}


/************************************************************************
 * A paladin can cure a disease once per hour at 1st level, twice at 5th
 * three times at 10th, etc. Note that when he logs on he must WAIT for
 * the alloted time before he can cure the disease again.
 */
status can_cure_disease() {
  return((time() - timer) > 
     (DISEASE_WAIT_TIME /
     (((int)environment()->query_level()/5)+1))) ? 1 : 0;

}

void reset_time() { timer = time(); }

void reset(status arg) {
  if(arg) return;
  reset_time();
}

string extra_look(status wiz) {
  if(this_player() != environment())
    return (string)environment()->query_name()+" is a Paladin of "+GOD;
  else
    return "You are a Paladin of "+GOD;
}

void init_arg() {
  call_out("paladin_bonuses", 2);
}

void paladin_bonuses() {
  if(environment()) {
    if(present("guild_object 2", environment())) {
      destruct(this_object());
      return;
    }
    clone_object("obj/shadows/paladin")->paladin_aura(environment());
    environment()->add_spell_immunity("disease");
    environment()->add_spell_immunity("fear");
  }
}

void guild_death() {
  string *skills;
  int i;

  skills = ({
     "sword_spec", "lance_spec", 
     "crushing_spec", "shield_spec",
  });
  for(i=0; i<sizeof(skills); i++) {
    call_other(environment(), "set_"+skills[i], 
      call_other(environment(),"query_"+skills[i]));
  }
}

status id(string str) {
  return str == "paladin"      ||
         str == "guild_object";
}

status drop(string quit) { return 1; }
status get(string quit)  { return 1; }

void set_horse(object ob) { horseOb = ob; }
object query_horse()      { return horseOb; }
