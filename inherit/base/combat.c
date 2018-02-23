/* Modular living.c System
 * Angel, Dec. 1996.
 * COMBAT.c 
 */

#pragma strict_types
#pragma save_types
#pragma combine_strings


#include <mudlib.h>
#include <combat.cfg>
#include <spell.h>
#include <ansi.h>



int level_drained;           /* number of levels 'drained' */
status ghost;                /* Is the being a ghost? */  
status dead;                 /* Is the being dead? **/

static status no_wimpy;       /* Is the being restricted from wimpy? */
status hp_displ;

int whimpy;                  /* Number of hp being will run at */
mapping weapon_prof;          /* list of weapon profs and skills */

static string custom;        /* Custom direction for wimpy exit */

static int spell_time;
static int armour_class;     /* Measure of protection */  
static object *armour_worn;  /* list of armour being worn */
static int ac_bonus;       
static int npc_ac;

static int right_wc;         /* right weapon */  
int experience;              /* Experience poitns earned by being */
int alignment;               /* Numerical alignment of being */ 
static object right_weapon;
static string right_weapon_type;
static int right_weapon_bonus;
static string *right_attack_msg;
static int npc_wc;

static int left_wc;          /* left weapon */ 
static object left_weapon;
static string left_weapon_type;
static int left_weapon_bonus;
static string *left_attack_msg;
static int npc_wc_l; 

static object primary_attack;     /* main opponent */  
static object *secondary_attacks; /* list of other opponents */  

static string *sec_att_names;


/************************************************************************/
/* Sets */
string *set_right_attack_msg(string *msg) { 
  return right_attack_msg = (msg) ? msg : ({});
}

status set_hp_displ(status s) { return hp_displ = s; }

string set_custom(string s)   { return custom   = s; }

string *set_attack_msg(string *msg) {
  return set_right_attack_msg(msg);
}

string *set_left_attack_msg(string *msg) { 
  return left_attack_msg = (msg) ? msg : ({});
}

string set_right_weapon_type(string s) { return right_weapon_type = s;    }
string set_left_weapon_type(string s)  { return left_weapon_type = s;     }

int set_wimpy(int i)        { return whimpy   = i;                 }
int set_ac(int i)           { npc_ac = i; return armour_class = i; }
int set_armour_class(int i) { npc_ac = i; return armour_class = i; }

int set_ac_bonus(int i) {
# ifdef LOG_SET_AC_BONUS
    log(LOG_SET_AC_BONUS, ac_bonus, i);
# endif /* LOG_SET_AC_BONUS */^
  return ac_bonus = i;
}

int set_right_weapon_bonus(int i)      { return right_weapon_bonus = i;    }
int set_left_weapon_bonus(int i)       { return left_weapon_bonus = i;     }
int set_left_wc(int i)                 { npc_wc_l = i; return left_wc = i; }
int set_right_wc(int i)                { npc_wc = i; return right_wc = i;  }
int set_wc(int i)                      { npc_wc = i; return right_wc = i;  }


object *set_armour_worn(object *arr) {
  return armour_worn = (arr) ? arr : ({});
}

object set_right_weapon(object ob)     { return right_weapon = ob;        }
object set_left_weapon(object ob)      { return left_weapon = ob;         }
object set_primary_attack(object ob)   { return primary_attack = ob;      }

object *set_secondary_attacks(object *arr) {
  return secondary_attacks = (arr) ? arr : ({});
}



mapping set_weapon_prof(mapping arr) {
  return weapon_prof = (arr) ? arr : ([]);
}

mapping query_weapon_prof()      { return weapon_prof;       }

status set_ghost(status i)    { return ghost    = (i) ? 1 : 0; }
status set_dead(status i)     { return dead     = (i) ? 1 : 0; }
status set_no_wimpy(status i) { return no_wimpy = (i) ? 1 : 0; }



/***************************************************************************/
/* Queries */
int query_level_drained()        { return level_drained;     }
int query_wimpy()                { return whimpy;            }
int query_ac()                   { return armour_class;      }
int query_armour_class()         { return armour_class;      }
int query_ac_bonus()             { return ac_bonus;          }

int query_wc()                   { return  right_wc;     }
int query_right_wc()             { return right_wc;          }
int query_left_wc()              { return left_wc;           }

int query_weapon_proficiency(string str){  
  if(!sizeof(weapon_prof)) weapon_prof = ([ ]);
  return weapon_prof[str]; 
}  


status two_weapons_wielded() {
  if(right_weapon && left_weapon) return 1;
  else return 0;
}

status query_hp_displ()          { return hp_displ;          }
status query_ghost()             { return ghost;             }
status query_no_wimpy()          { return no_wimpy;          }
status query_dead()              { return dead;              }

status query_secondary_attacker(object ob) {
  return (member_array(ob, secondary_attacks) == -1) ? 0 : 1;
}

status query_armour(object ob) {
  return (member_array(ob, armour_worn) == -1) ? 0 : 1;
}

status query_sec_att_name(string str) {
  if(!sec_att_names) sec_att_names = ({});
  return (member_array(str,sec_att_names) != -1) ? 1 : 0;
}


object *query_armour_worn()      { return armour_worn;       }
object query_right_weapon()      { return right_weapon;      }
object query_left_weapon()       { return left_weapon;       }

object query_attack()            { return primary_attack;    }
object query_primary_attack()    { return primary_attack;    }
object *query_secondary_attacks(){ return secondary_attacks; }
object *query_alt_attackers()    { return secondary_attacks; }

object query_armour_type(mixed arg) {
  object *obj, ob;
  string type;

  type = (objectp(arg)) ? (string)arg->query_type() : arg;
  obj = filter(armour_worn,"filter_armour_type",this_object(),type);
  ob = (sizeof(obj)) ? obj[0] : 0;
  return ob;
}



string query_custom()            { return custom;            }
string query_right_weapon_type() { return right_weapon_type; }
string query_left_weapon_type()  { return left_weapon_type;  }

string query_attacker() {
  return (primary_attack) ? (string)primary_attack->query_name() : 0;
}


/**********************************************************************/
/* Adjust various */
int adj_level_drained(int i) {
# ifdef LOG_SET_LEVEL_DRAINED^
    log(LOG_SET_LEVEL_DRAINED, level_drained, level_drained+i)
# endif /* LOG_SET_LEVEL_DRAINED */
 return level_drained += i;
}

int adj_wimpy(int i)        { return whimpy  += i;      }

int adj_ac(int i)           { return armour_class += i; }
int adj_armour_class(int i) { return armour_class += i; }
int adj_ac_bonus(int i)     { return ac_bonus     += i; }


int adj_right_wc(int i)                { return right_wc += i;           }
int adj_right_weapon_bonus(int i)      { return right_weapon_bonus += i; }
int adj_left_wc(int i)                 { return left_wc += i;            }
int adj_left_weapon_bonus(int i)       { return left_weapon_bonus += i;  }


/***************************************************************************/
/* Add/Remove Stuff */

void add_weapon_proficiency(string str, int skill){  
  if(str) weapon_prof[str] = skill;
}  
  
void remove_weapon_proficiency(string str){  
  if(str && query_weapon_proficiency(str))
    weapon_prof = m_delete(weapon_prof, str);  
}     

static status filter_armour_type(object ob, string type) {
  if(!ob) return 0;
  if((string)ob->query_type() == type) return 1;
  return 0;
}

void add_armour(object ob){  
  if(!query_armour_type(ob) && ob) armour_worn += ({ ob, });
}  


/*********************************************************************/
/* 
  sec_att_names is an array of player names attacking this object,
  It has two purposes:
  1. It stores the name, to stop the player tactic of cutting the
     connection to stop a fight with a monster.

 
  2. It stores the players capitalized name to indicate that that
     player_cap_name attacked me first. Player killers are made only if
     they are the first player. (In otherwords if the name is stored
     as a lower case name, then I attacked first)
 */


void add_sec_att_name(string str) {
  if(!sec_att_names) sec_att_names = ({ });
  if(member_array(str, sec_att_names) == -1) 
    sec_att_names += ({ str, });
}

status add_secondary_attacker(object ob) {
  int i;
  string killer_name, killer_cap_name;
  object hider;

  if(ob == this_object()) return 0;
  this_player()->set_i_initiated_attack(this_object());

  if((status)ob->query_no_kill_flag()) {
    if(sizeof((mixed *)this_player()->query_loaded_spell()))
      this_player()->unload_spell();
    return 0;
  }
  if(!query_secondary_attacker(ob)) {
    if(ob && !ob->query_npc() && (killer_name = (string)ob->query_name(1))) {
      killer_cap_name = capitalize(killer_name);
      if(!sec_att_names) sec_att_names = ({});
      if(!this_object()->query_npc() &&
          ob->query_secondary_attack(this_object())
      && !ob->query_sec_att_name(killer_cap_name)) { 
        if((i = member_array(killer_name, sec_att_names)) != -1) {
          sec_att_names = sec_att_names[0..(i-1)]
                        + sec_att_names[(i+1)..(sizeof(sec_att_names)-1)];
        }
        if(member_array(killer_cap_name, sec_att_names) == -1) {
          sec_att_names += ({ killer_cap_name, });
        }
      }
      else  {
        if((i = member_array(killer_cap_name, sec_att_names)) != -1) {
          sec_att_names = sec_att_names[0..(i-1)]
                        + sec_att_names[(i+1)..(sizeof(sec_att_names)-1)];
        }
        if(member_array(killer_name, sec_att_names) == -1) {
          sec_att_names += ({ killer_name, });
        }
      }
    }
  }
  if(!this_object()->query_npc() && ob && !ob->query_npc()) {
#ifdef PK
//#ifdef PK_MOD /* THE PLAYER KILL FLAG */
    if((THIS_OBJECT_WIZ^((ob->query_security_level()) ? 1 : 0))
    || (this_object()->query_level() < 10)
    || (int)ob->query_level() < 11
    || ((int)ob->query_level() < ((int)this_object()->query_level()-8)
    && ((int)ob->query_level() < 40 && (int)this_object() < 40)
    && !ob->query_secondary_attacker(this_object()))) {
      return 0;
    }
  }
#else /* !PK */
    return 0;
  }
#endif /* !PK */

  if(!query_secondary_attacker(ob) && ob) secondary_attacks += ({ ob, });


  if((hider = (object)this_object()->query_hide_in_shadows_object())) {
    tell_object(this_object(), "You turn to face "+ob->query_name()+" who "+
    "notices you approach from the shadows.\n");

    tell_object(ob, "You notice "+this_object()->query_name()+" as "+
    this_object()->query_pronoun()+" begins "+this_object()->query_possessive()+
    "attack on you.\n");
    destruct(hider);
  }

  /* for disguise people */


  return 1;
}

void remove_secondary_attacker(object ob) {
  string killer_name;
  int i;

  if(ob && (killer_name = (string)ob->query_name(1))) {
    if(!sec_att_names) sec_att_names = ({});
    if((i = member_array(killer_name, sec_att_names)) != -1) {
      sec_att_names = sec_att_names[0..(i-1)]
                     + sec_att_names[(i+1)..(sizeof(sec_att_names)-1)];
    }
    killer_name = capitalize(killer_name);
    if((i = member_array(killer_name, sec_att_names)) != -1) {
      sec_att_names = sec_att_names[0..(i-1)]
                     + sec_att_names[(i+1)..(sizeof(sec_att_names)-1)];
    }
  }
  if(ob == primary_attack) primary_attack = 0;
  if((i = member_array(ob, secondary_attacks)) != -1) {  
    secondary_attacks = secondary_attacks[0..i-1]
                      + secondary_attacks[i+1..sizeof(secondary_attacks)-1];
  }
}



/***************************************************************************/
/* level draining stuff 
 * Previously it drained a level, but with max_exp giving level then it
 * was changed to drain 1 str, 1 con instead.
 */

void restore_level() {  
  if(!level_drained) return;
  level_drained -= 1;  
  this_object() -> set_strength((int)this_object()->query_strength() + 1);
  this_object() -> set_constitution((int)this_object()->query_constitution()+1);
} 
 
void drain_level() {  
  if((int)this_object()->query_strength() == 1 ||
     (int)this_object()->query_constitution() == 1) {
    this_object()->death();
    return;
  }
  level_drained += 1;  
  this_object()->set_strength((int)this_object()->query_strength() -1);
  this_object()->set_constitution((int)this_object()->query_constitution()-1);
}  



/*************************************************************************/
/* wimpy */
void random_move() {
  object here;
  string *exits;

  here = environment();  
  if(no_wimpy) {
    tell_object(this_object(),"Something stops you from running!\n");
    return;  
  }
  if(this_object()->query_horse_object()) {
    command("dismount", this_object());
  }

  if(custom) {
    if((int)this_object()->query_wisdom() >= random(25)) {
      if(command(custom)) {
        tell_object(this_object(),"You keep your cool and leave "+
                                   custom +".\n");
      }
      else {
        tell_object(this_object(),"You cannot run "+custom+".\n");  
      }
    }  
    else {  
      tell_object(this_object(),"You fail to flee "+ custom +"!\n");
    }
    return;
  }
  if(!(exits = (string *)environment()->query_open_exits())) {
    if(!(exits = (string *)environment()->query_dest_dir())) {
      if(!this_object()->query_npc())
        say(this_object()->query_name()+" tried, but failed to run away.\n",
            this_object());
        tell_object(this_object(),"You try to run away, but fail!\n");
      return;
    }
  }
  if(!sizeof(exits)) {
    tell_object(this_object(),"There is no obvious way to run.\n");
    if(!this_object()->query_npc())
     say(this_object()->query_name()+" tried, but failed to run away.\n", this_object());
    return;
  }
  command(exits[(random(sizeof(exits)/2)*2) + 1], this_object());
  if(here == environment()) {
    if(!this_object()->query_npc())
     say (this_object()->query_name()+" tried, but failed to run away.\n", this_object());
    tell_object(this_object(),"You try to run away, but fail!\n");
  }  
  else {
    if(!this_object()->query_npc())
     say(this_object()->query_name()+" runs for "+this_object()->query_possessive()+" life!\n");
    tell_object(this_object(),"You run for your life!!\n");
  }
}



/************************************************************************/  
/* insta-kill */

void death() {
  object corpse, coins, ob;
  object *inv;
  int i, wt;
  object alt;
  string party;
  int z;
  string killer_name;

  this_object()->set_hp(20);
  dead = 1;  
    if(!this_object()->query_npc()) {
    say(this_object()->query_name() + " died.\n", this_object());

    if(this_player() != this_object()) {  
      check_shout(this_player()->query_name()+
      " howls in triumph at the death of "+this_object()->query_name()+"!!!\n");

#ifdef  PK_MOD
      if(!(ob=present("bounty license", this_player()))) {
        if(this_object() == (object)this_player()->query_i_initiated_attack())
        PK_OFFICE->add_villan((string)this_player()->query_name(1),
			(string)this_object()->query_name(1), "murdering "+
			(string)this_object()->query_name());
        tell_object(this_player(), "That was not a lawful act.\n");
      }
      else {
        if(!(status)PK_OFFICE->query_villian(this_object()->query_name(1))) {
          if(this_object() == (object)this_player()->query_i_initiated_attack())
          PK_OFFICE->add_villian((string)this_player()->query_name(1),
			(string)this_object()->query_name(1),
			"murdering "+this_object()->query_name());
          tell_object(this_player(), "That was not a lawful act.\n");
        }
      }
#endif /* PK_MOD */
    }   
    else {
      check_shout(this_player()->query_name()+
                  " has killed "+this_object()->query_objective()+"self!!!\n");
    }  
  }

  /* update attackers exp & alignment */

  if(this_player() != this_object()) {
    if(ob = present("party_object", this_player())) {
      ob -> share_exp((int)this_object()->query_exp()/10);
    }
    else {
      this_player()->add_exp((int)this_object()->query_exp()/10);
    }
    this_player()->add_alignment(-ADDED_ALIGNMENT);
  }

  /* update this persons exp */

  experience -= (((int)this_object()->query_level() < 20) ? experience/3 : 600000);

  for(z = 1; (alt = present(GUILD_OB+" "+z, this_object())); z++) {
    alt->player_death();
  }
  this_object()->set_hp(10);
  corpse = clone_object(CORPSE);  
  inv = all_inventory();  
  for(i = 0; i < sizeof(inv); i++) {
    if(!inv[i]->drop(1)) {
      if(!inv[i]) continue;
      move_object(inv[i], corpse);
      wt += (int)inv[i]->query_weight();
    }  
  }
  corpse->set_max_weight(wt);
  if(this_object()->query_money()) {
    coins = clone_object(MONEY);
    coins->set_money((int)this_object()->query_money());
    move_object(coins, corpse); 
    this_object()->set_money(0);
  }
  move_object(corpse, environment());  
  this_object()->recalc_carry();
  this_object()->recalc_wc();
  this_object()->recalc_wc();

  /* fix attacker objects */

  for(i = 0; i < sizeof(secondary_attacks); i++) {
    if(secondary_attacks[i]) {
      secondary_attacks[i]->stop_fight(this_object());
    }
  }
  primary_attack = 0;
  secondary_attacks = ({});
  sec_att_names = ({});

  if(this_player() != this_object())
    write("You killed "+this_object()->query_name()+".\n");
  if(!this_object()->second_life()) {
    say(this_object()->query_name()+" died.\n", this_object());
    destruct (this_object());  
  }
}

/* do damage without making attacker pointers */

static int do_damage(int dam) {
  int i;
  int size;
  object attacker;

  if(!primary_attack) set_heart_beat(1); /* start heart of npcs */
  this_object()->set_stealth_on(0); /* stealth_on = 0 */
  this_object()->set_disguise_on(0); /* disguise_on = 0 */
  this_object()->set_invis(0);
  this_player()->set_invis(0);
  this_player()->set_stealth_on(0);
  if(ghost && !dead) {
    tell_object(this_object(), this_player()->query_name() +
    "'s attack passes right through you!\n");
    write("You pass straight through "+ this_object()->query_name() +"!\n");
    return 0;
  }
  if(dead) return 0;  
  if(random(THIS_PLAYER_COM) < random((int)this_object()->query_dexterity())) {
    dam -= random((int)this_object()->query_dexterity()/5 +1);
  }
  else {
    dam += random(THIS_PLAYER_COM/5 + 1); 
  }
  dam -= random(armour_class + 1);  
  if(dam < 1) return 0;  

#ifdef DESTROY_ARMOUR
  if((i = sizeof(armour_worn))) {
    i = random(i);
    if(armour_worn[i])
      tell_object(this_object(),"Your "+
      (string)armour_worn[i]->query_name()+" absorbs some damage.\n");
    if(!this_object()->query_npc() && armour_worn[i])
      armour_worn[i]->hit_armour(random(dam));
  }
#endif /* DESTROY_ARMOUR */

  /* check to see if net link is still on */  
  
  if(!this_object()->query_npc() && !query_ip_number(this_object())) {
    write((string)this_object()->query_name()+" is not here!\n"+
          "You cannot kill a player who is not logged in.\n");  
    if(this_object()->query_hp() < 20) this_object()->set_hp(20);
    this_object()->stop_fight();
    if(this_player()) this_player()->stop_fight();  
    return 0;
  }

  if(environment(this_object())->query_ooc_room()) {
    if(this_object()->query_hp() < 20) this_object()->set_hp(20);
    this_object()->stop_fight();
    if(this_player()) this_player()->stop_fight();
    return 0;
  }

/* players hit harder for a little while */
  if(!this_player()->query_npc()) dam += 20;
  this_object()->adj_hp(-dam);
  if(!this_object()) return 0; /* adj_hp() can also cause death */
  if(dam && hp_displ) {
    tell_object(this_object(), 
      BOLD+"** HP: "+this_object()->query_hp()+"/"+
      this_object()->query_max_hp()+" **"+OFF+"\n");
  }
  if((int)this_object()->query_hp() > 0) return dam;
  death();
  return dam;  
}



/****************************************************************************/
/* hit player */

int hit_player(int dam) {
  int i;
  string file;

  if(this_player() != this_object()) {
    if(environment(this_player())->query_no_fight()) {
      write("Fighting is not allowed here.\n");
      this_object()->stop_fight(this_player());
      this_player()->stop_fight(this_object());
      return 0;
    }
#ifdef LOG_SPECIAL_HIT /* use to detect illegal calls to hit_player */
    if(previous_object() && !living(previous_object())) {
      file = file_name(previous_object());
      sscanf(file,"%s#%d",file,i);
      switch(file) {
        case "obj/shadows/healem":
        case "obj/shadows/stoneskin":
        case "skills/thief/bs":
        case "skills/thief/steal":
        case "obj/shadows/hit_back":
        case "skills/mage/cloudkill":
          /* these are currently known objects that call this fn */
        break;

        default:
          log_file(LOG_SPECIAL_HIT,file +"\n");
        break;
      }
    }
#endif /* LOG_SPECIAL_HIT */

  }
  if(this_object()->add_secondary_attacker(this_player())) {
    if(!primary_attack || !present(primary_attack, environment())) {
      primary_attack = this_player();
    }
  }
  return do_damage(dam);
}


/************************************************************************/
/* stop fight */


varargs void stop_fight(object attacker) {
  if(!attacker) attacker = primary_attack;
  remove_secondary_attacker(attacker);
  if(attacker) attacker->remove_secondary_attacker(this_object());
}



/**************************************************************************/
/* Attack Sequence
 * This fn is called at the end of the heart beat to see if we need to 
 * attack anyone around here 
 */

void attack() {
  int dam;
  mixed *loaded_spell;
  string file;
  string pname;
  int i, extra_attack, size;
  int rhit, lhit;
  string weapon_type;  
  object alt; int z;
  object tmp_att;
  object ob;
  int myInt, yourDisguise;


  if(this_object()->check_spell("Hold"))          return;
  if((status)this_object()->query_no_kill_flag()) return;

  loaded_spell = (mixed *)this_object()->query_loaded_spell();


  /* this will stop the fight between these two, but not others */
  if(primary_attack && primary_attack->query_ghost()) {
    primary_attack -> stop_fight(this_object());
    this_object()  -> stop_fight(primary_attack);
  }

  /***************************************************************/
  /* evaluate our primary attacker */

  if(!primary_attack || !present(primary_attack,environment())) {
    for(i = 0; i < sizeof(secondary_attacks); i++) {
      if(secondary_attacks[i]) {
        if((primary_attack = present(secondary_attacks[i],environment()))) { 
          if(!primary_attack->query_ghost()) break;
        }
      }
      else { /* remove zeros (dested attacks) */
        secondary_attacks = secondary_attacks[0..i-1]
                          +secondary_attacks[i+1..sizeof(secondary_attacks)-1];
        i--;
      }
    }

    if(!primary_attack) {
      if(this_object()->query_npc()) return;
      if(!sizeof(loaded_spell)) return; /* no attack in room */

      else {
        if(!AREA_EFFECT && !TARGET && !PASSIVE) {
          write("You stop casting your "+ SPELL_NAME +" spell.\n");
          this_object()->unload_spell();
          return;
        }
      }
    }
  }


  /***************************************************************/
  /* no fight check */
  if(environment()->query_no_fight() && sizeof(loaded_spell)) {
    write("You can't use your powers in here!.\n");
    this_object()->unload_spell();
    if(primary_attack) {
      stop_fight(primary_attack);
      primary_attack -> stop_fight(this_object());
    }
    return;
  }



  /**************************************************************/
  /* cast a spell */

  if(sizeof(loaded_spell)) {
    int msg_index;
    if(++spell_time < SPELL_TIME) {
      if(pointerp(PREPARE_MSG)) {
        msg_index = (spell_time <= sizeof(PREPARE_MSG)) 
                  ? spell_time-1
                  : sizeof(PREPARE_MSG)-1;
        write(this_object()->process_msg(PREPARE_MSG[msg_index]));
      }
      if(pointerp(PREP_MSG_ROOM)) {
        msg_index = (spell_time <= sizeof(PREP_MSG_ROOM))
                  ? spell_time-1
                  : sizeof(PREP_MSG_ROOM)-1;
        say((string)this_object()->process_msg(PREP_MSG_ROOM[msg_index]));
      }
      return;
    }
    spell_time = 0;
    this_object()->cast_spell_at_target();
#ifdef EITHER_SPELL_OR_ATTACK_IN_HEART_BEAT
    return; 
#endif
  }




  /***************************************************************/
  /* a thiefs hide in shadows can delay or stop a fight */

  if(primary_attack && primary_attack->query_hide_in_shadows_object()) {
    if(random((int)this_object()->query_intelligence())
     < random((int)primary_attack->query_hide_in_shadows()+1)) {
      tell_object(primary_attack,
        this_object()->query_name()+" can't seem to find you, and "+
	"seems to give up the search.\n");
      primary_attack -> stop_fight(this_object());
      stop_fight(primary_attack);
      return;
    }
    destruct((object)primary_attack->query_hide_in_shadows_object());
    tell_object(primary_attack, this_object()->query_name() +" notices you "+
    "and turns to attack!\n");
  }




  /***************************************************************/
  /* a thiefs disguise can fool to stop a fight */

  if(!this_object()->query_aggressive() &&
    primary_attack                      && 
    primary_attack->query_disguise_on()) {

    pname = lower_case((string)primary_attack->query_name()); /* use current name */
    if(!sec_att_names) sec_att_names = ({});

    myInt        = random((int)this_object()->query_intelligence() * DISGUISE_DIFF);
    yourDisguise = random(PRIMARY_DISGUISE+1);

    /* if i don't recognise your current name */
    if(member_array(capitalize(pname), sec_att_names) == -1) {

      /* attacker disguises well! */
      if(myInt < yourDisguise) {
        tell_object(primary_attack,
        "Your diguise seems to fool "+this_object()->query_name()+", who "+
        "seems to just give up the search for you.\n");
        this_object()  -> stop_fight(primary_attack);
        primary_attack -> stop_fight(this_object());
        return;
      }
      /* attacker fails his disguise */
      else {
        tell_object(primary_attack,
        this_object()->query_name() +" sees straight through your disguise!\n");

        /* if lower case pname, then subst it with capital pname */
        if((i = member_array(pname,sec_att_names)) != -1) {
          sec_att_names[i] = capitalize(pname);
        }
        else {
          sec_att_names += ({ capitalize(pname), });
        }
        primary_attack -> toggle_disguise();
      }
    }

    /* if i remember your ugly face! */
    tell_object(primary_attack, this_object()->query_name() +" remembers your face!\n");
    primary_attack -> toggle_disguise();
  }
 
  else {
    if(this_object()  -> query_aggressive() &&
       primary_attack -> query_disguise_on()) {
       tell_object(primary_attack,
       this_object()->query_name()+" doesn't care if you're disguised or not, "+
       this_object()->query_objective()+" attacks you out of malice.\n");
       primary_attack->toggle_disguise();
    }
  }

  if(this_object()->query_hide_in_shadows_object()) return;
  if(this_object()->query_disguise_on())            return;





  /*******************************************************/
  /* right weapon attacks */

  if(right_weapon) {
    rhit = (int)right_weapon->hit(primary_attack);
#ifdef LOG_WEAPON_HIT
    if(rhit) {
      file = file_name(right_weapon);
      sscanf(file,"%s#%d",file,i);
      switch(file) {
        default:^M
          log_file(LOG_WEAPON_HIT,file +" amt: "+ rhit +" hp\n");
        break;
      }
    }
#endif
    weapon_type = (right_weapon->query_type()) 
                ? (string)right_weapon->query_type()
                : "default";
  }

  /*********************************************************/
  /* multiple attacks (with right weapon) */
  if(this_object()->query_multi_attack()) {
    extra_attack = MULTI_ATTACK_RATE;
  }
  if(right_weapon)
    if((string)right_weapon -> query_type() == "missile") extra_attack = 0;

  for(z = 1; (alt = present(ALT+" "+z, this_object())); z++) {
    extra_attack += (int)alt->query_extra_attack();
  }
  for(z = 1; (alt = present(GUILD_OB+" "+z, this_object())); z++) {
    extra_attack += (int)alt->query_extra_attack();
  }
  if(extra_attack > MAX_MULTI_ATTACK) extra_attack = MAX_MULTI_ATTACK;

  for(i = 0; i <= extra_attack; i++) {  
    dam = ((right_wc + rhit) * 2 + this_object()->query_combat())/3;
    dam -= i;
    dam = (dam > 0) ? random(dam) + 1 : 0;
    if(!primary_attack) return; 

    /* is the person we're attacking immune to our weapon? */
    if(right_weapon) {
      if((primary_attack->query_spell_immunity(weapon_type)) ||
        (primary_attack->query_spell_immunity("non enchanted weapons") &&
         !right_weapon->query_enchanted())) {
        dam = 0;
      }
    }
    if(!right_weapon) {
      if(primary_attack->query_spell_immunity("non enchanted weapons")) 
        dam = 0;
    }

    dam = (int)primary_attack->hit_player(dam);
    this_object()->add_exp(dam);   /* get experience for just attacking */
    this_object()->attack_msg(dam, weapon_type, primary_attack, "right");
    if(right_weapon)
      right_weapon->query_dam(dam, primary_attack);
#ifdef DESTROY_WEAPON 
    if(right_weapon && !this_object()->query_npc())
      right_weapon->hit_weapon(dam);
#endif 
    if(primary_attack && this_object()->query_multi_attack()) {
      if(random((int)this_object()->query_multi_attack()) <
         random(PRIMARY_DEX*MULTI_FREQ)) break;
    }
    else if(primary_attack) {
      if(random((int)this_object()->query_combat()) <
         random(PRIMARY_DEX*MULTI_FREQ)) break;
    }
    else {
      break;
    }
  }

  /***************************************************/
  /* multiple opponents (with right weapon) */


  if(primary_attack && this_object()->query_multi_opponent()) {
    for(i = 0; i < sizeof(secondary_attacks); i++) {
      if((tmp_att = secondary_attacks[i])
      && present(tmp_att,environment())
      && primary_attack != tmp_att) {
        if(random((int)this_object()->query_multi_opponent()) 
       < random((int)tmp_att->query_dexterity()*MULTI_FREQ)) break;
          dam = ((right_wc + rhit) * 2 + (int)this_object()->query_combat())/3;
          dam = (dam > 0) ? random(dam) + 1 : 0;  
          if((tmp_att->query_spell_immunity(weapon_type)) ||
             (tmp_att->query_spell_immunity("non enchanted weapons") &&
              !right_weapon->query_enchanted())) {
              dam = 0;
          }
          dam = (int)tmp_att->hit_player(dam);
          this_object()->add_exp(dam);   /* get experience for just attacking */
          this_object()->attack_msg(dam, weapon_type, tmp_att, "right");
          if(right_weapon)
            right_weapon->query_dam(dam, tmp_att);
#ifdef DESTROY_WEAPON 
          if(right_weapon && !this_object()->query_npc())
            right_weapon->hit_weapon(dam);
#endif
      }
    }
  }

  /********************************************/
  /* left weapon attack */

  if(primary_attack && this_object()->query_two_weapon() && left_weapon) {
    if(random((int)this_object()->query_two_weapon()) >= random(PRIMARY_DEX)) {
      if(left_weapon)  lhit = (int)left_weapon->hit(primary_attack);
      dam = ((left_wc + lhit) * 2 + (int)this_object()->query_combat())/3;
      dam = (dam > 0) ? random(dam) + 1 : 0;
      if(tmp_att)
      if((tmp_att->query_spell_immunity(weapon_type)) ||
        (primary_attack->query_spell_immunity("non enchanted weapons") &&
         !left_weapon->query_enchanted())) {
        dam = 0;
      }
      dam = (int)primary_attack->hit_player(dam);
      this_object()->add_exp(dam);   /* get experience for just attacking */
      weapon_type = (left_weapon) 
                  ? (string)left_weapon->query_type()
                  : "default";
      this_object()->attack_msg(dam, weapon_type, primary_attack, "left");
      if(left_weapon)
        left_weapon->query_dam(dam, primary_attack);
#ifdef DESTROY_WEAPON 
      if(left_weapon && !this_object()->query_npc()) left_weapon->hit_weapon(dam);
#endif 
    }
  }
}


/* here ends the attack sequence */

int right_wc_bonus() {
  int bonus, z;
  object alt;

  bonus = (int)this_object()->query_race_right_wc_bonus();

  for(z = 1; (alt = present(ALT+" "+z, this_object())); z++) {
    bonus += (int)alt->right_weapon_class_bonus();
  }
  for(z = 1; (alt = present(GUILD_OB+" "+z, this_object())); z++) {
    bonus += (int)alt->right_weapon_class_bonus();
  }
  bonus += right_weapon_bonus;
  return bonus;
}


int left_wc_bonus() {
  int bonus, z;
  object alt;

  bonus = (int)this_object()->query_race_left_wc_bonus();

  for(z = 1; (alt = present(ALT+" "+z, this_object())); z++) {
    bonus += (int)alt->left_weapon_class_bonus();
  }
  for(z = 1; (alt = present(GUILD_OB+" "+z, this_object())); z++) {
    bonus += (int)alt->left_weapon_class_bonus();
  }
  bonus += left_weapon_bonus;
  return bonus;
}


int ac_bonus() {
  int bonus, z;
  object alt;

  bonus = (int)this_object()->query_race_ac_bonus();

  for(z = 1; (alt = present(ALT+" "+z, this_object())); z++) {
    bonus += (int)alt->armour_class_bonus();
  }
  for(z = 1; (alt = present(GUILD_OB+" "+z, this_object())); z++) {
    bonus += (int)alt->armour_class_bonus();
  }
  bonus += ac_bonus;
  return bonus;
}

void recalc_wc() {  
  int i, bonus;
  object *inv;
  string class;

  right_weapon = 0;
  left_weapon = 0;
  inv = all_inventory();
  for(i = 0; i < sizeof(inv); i++) {
    if(inv[i]->query_wielded("right")) {
      if(right_weapon) {  
        inv[i]->dewield();
        continue;
      }

      right_weapon = inv[i];
      right_wc = (int)right_weapon->query_wc();

      if(!sizeof(weapon_prof)) weapon_prof = ([]);
      
      if(!bonus=query_weapon_proficiency((string)right_weapon->query_name())){
        if((status)this_object()->query_class("fighter")) {
          right_wc -= 3;
        }
        else if(this_object()->query_class("thief")  ||
		 this_object()->query_class("ranger") ||
                this_object()->query_class("paladin")) {
          right_wc -= 4;
        }
        else if(this_object()->query_class("cleric")) {
          right_wc -= 5;
        }
        else {
          right_wc -= 6;
        }
      }
      bonus /= 4;
      right_wc += right_wc_bonus() + bonus;
      set_right_attack_msg((string *)inv[i]->query_attack_msg());
    }
    else if(inv[i]->query_wielded("left")) {
      if(left_weapon) {
        inv[i]->dewield();
        continue;
      }
      left_weapon = inv[i];
      left_wc = (int)left_weapon->query_wc();
      if(!bonus=query_weapon_proficiency((string)left_weapon->query_name())){
        if(this_object()->query_class("fighter")) {
          right_wc -= 3;
        }
        else if(this_object()->query_class("thief") ||
               this_object()->query_class("ranger")) {
          right_wc -= 4;
        }
        else {
          right_wc -= 6;
        }
      }
      bonus /= 4;
      left_wc += left_wc_bonus() + bonus;
      set_left_attack_msg((string *)inv[i]->query_attack_msg());
    }
  }
  if(!right_weapon) {
    right_wc = WEAPON_CLASS_HANDS;
    if(this_object()->query_unarmed()) {
      right_wc += (int)this_object()->query_unarmed();
      if(right_wc > 30) /*    /* unarmed 57 == wc 30 */
        right_wc = 30 + (right_wc-30)/4;
      else if(right_wc > 20)  /* unarmed 27 == wc 20 */
        right_wc = 20 + (right_wc-20)/3;
      else if(right_wc > 10)  /* unarmed 7  == wc 10 */
        right_wc = 10 + (right_wc-10)/2;
    }
  }
  if(this_object()->query_npc()) {
    right_wc = npc_wc   + right_wc_bonus();
    left_wc  = npc_wc_l + left_wc_bonus();
  }
}


void recalc_ac() {  
  int i;  
  object *inv;  
  
  armour_class = 0;  
  armour_worn = ({});
  inv = all_inventory();
  for(i = 0; i < sizeof(inv); i++) {
    if(inv[i]->armour_class() > 0 && inv[i]->query_worn()) {
      if(query_armour_type(inv[i])) {
        inv[i]->drop(1);
        continue;
      }
      armour_class += (int)inv[i]->armour_class();  
      armour_worn += ({ inv[i], });
    }
  }
  armour_class += ac_bonus();
  if(this_object()->query_npc()) {
    armour_class = npc_ac + ac_bonus();
  }
}



/*************************************************************************/
void attack_msg(int dmg, string type, object who, string side) {  
   string *msg;
   int dam, size;  
   string str;

   if(!who) return; /* attacker dested */

   if(dmg < 0) dmg = 0;
   msg = (left_attack_msg && side == "left" && sizeof(left_attack_msg))
       ? left_attack_msg



       : (right_attack_msg && side == "right" && sizeof(right_attack_msg))
       ? right_attack_msg

       : (type == "slash")  
          ? ({  "missed",          "",
                "lightly touched", "with a light graze",         
                "wounded",         "with a weak blow",  
                "cut",             "with a fairly deep wound",  
                "sliced",          "with a strike to the head",  
                "slashed",         "with a slice to the chest",  
                "devestated",      "with a severe wound to the body",  
                "mutilated",       "\b, severely disabling a limb"})

      : (type == "crush")  
      ?      ({ "missed",          "", 
                "grazed",          "with next to no force",  
                "bruised",         "slightly, with a weak strike",  
                "hit",             "in the body",  
                "swatted",         "\b, doing a fair amount of damage",  
                "cracked",         "with a hard hit to the body",
                "smashed",         "across the head with a devestating blow",
                "crushed",         "into a bloody mess"})
  
      : (type == "thrust" || type == "pierce")  
      ?      ({ "missed",           "",
                "poked",            "without breaking the skin",
                "prodded",          "with little effect",                  
                "stabbed",          "through the leg",  
                "thrust deep into", "drawing a great amount of blood",  
                "gouged",           "with a viscous wound to the chest",  
                "impaled",          "with a very deep thrust to the chest",  
                "speared",          "straight through the body"})

      : (type == "cleave")  
      ?     ({ "missed",           "",
                "cut",            "with a slight graze",  
                "cut",            "somewhat, with a slow strike",  
                "strikes",        "with an attack to the body",  
                "cleaved",        "\b, bringing out a hunk of flesh",  
                "mutilated",      "with a chop to the torso",  
 "cleaved",        "through the chest with devastating force",
                "nearly chopped", "\b\'s head off with a stunning blow"})

      : (type == "spell")
      ?    ({ "missed",          "who resisted the arcane energies",
              "lightly touched", "with a small burst of power",  
               "bruised",         "with a burst of magical power",
               "wounded",         "with a release of magical power",  
               "swatted",         "with arcane energies",  
               "smashed",         "with a burst arcane energies",  
               "devestated",      "with Arcanus Energeia",  
               "mutilated",       "severely with Arcanus Energeia"})

      :      ({ "missed",         "", 
                "brushed",        "slightly",  
                "grazed",         "barely doing damage",  
                "kicked",         "with some force",  
                "tackled",        "with a hard charge",  
                "pummled",        "with a solid blow",  
                "clobbered",      "with a vicious kick to the head",  
                "body slammed",   "with great force into the ground"});
  
  size = sizeof(msg);
  dam = ((dmg+MSG_DAM-1)/MSG_DAM > (size/2)-1) 
      ? ((size/2)-1)
      : ((dmg+MSG_DAM-1)/MSG_DAM);  
  dam *= 2;

  str = (left_weapon && side == "left")
      ? " using your left "+(string)left_weapon->query_name()
      : (right_weapon && side == "right" && type != "missile")
      ? " using your right "+(string)right_weapon->query_name()
      : "";

  if(this_player() == who) {
    write("You "+ msg[dam] +" yourself"+ ((msg[dam+1] == "") ? "" : " ") +
          msg[dam+1] + str +
         ((THIS_PLAYER_WIZ) ? " ["+dmg+"pts]" : "")+".\n");
    say(this_object()->query_name()+" "+msg[dam]+" "+who->query_possessive()+
        "self"+ ((msg[dam+1] == "") ? "" : " ") + msg[dam+1] +".\n");
  }
  else { 
    write("You "+ msg[dam] +" "+ who->query_name() +
          ((msg[dam+1] == "") ? "" : " ") + msg[dam+1] + str +
          ((THIS_PLAYER_WIZ) ? " ["+dmg+"pts]" : "")+".\n");
    say(this_object()->query_name()+" "+msg[dam]+" "+who->query_name()+
        ((msg[dam+1] == "") ? "" : " ") + msg[dam+1] +".\n", who);
    tell_object(who,this_object()->query_name() +" "+ msg[dam] +" you"+
               ((msg[dam+1] == "") ? "" : " ") + msg[dam+1] +
               ((who->query_security_level()) ? " ["+dmg+"pts]" : "")+".\n");
  }
}  


/**************************************************************************/

void heal_self(int h) {
  int i;
  string *tmp;

  tmp = (string *)this_object()->query_classes();
  
  if(h <= 0) return;
#ifdef LOG_HEAL
  log(LOG_HEAL,"Old Hp: "+hp+" pts + Heal: "+h+" pts",0);
#endif /* LOG_HEAL */
  this_object()->adj_hp(h);
  if(this_object()->query_hp() > this_object()->query_max_hp())
    this_object()->set_hp((int)this_object()->query_max_hp());
  for(i = sizeof(tmp); i--; ) {
    call_other(this_object(), "adj_all_"+ tmp[i], h);
  }
}

