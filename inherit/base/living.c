#pragma strict_types
#pragma save_types
#pragma combine_strings

#include <mudlib.h>
inherit BASE;
inherit COMMUNICATION_FN;
inherit SPELL_FN;
inherit COMBAT_FN;



#include <living.cfg>      /* configuration */
#include <living.spc>      /* fn prototypes */
#include <compare.h>       /* compare() fun */
#include <tell.h>          /* tell_objects() fun */
#include <shout.h>         /* check_shout() fun  */
#include <skills.h>
#include <ansi.h>
#include <spell.h>


/* 'rename'  some base_obj stuff */

#define invis_name  alt_name

#define POISON_OB present("Poison", this_object())
#define POISON (POISON_OB) ? (int)POISON_OB->query_poison_penalty() : 0

#define THIS_PLAYER_WIZ  ((this_player()->query_security_level()) ? 1 : 0)
#define THIS_OBJECT_WIZ  ((this_object()->query_security_level()) ? 1 : 0)
#define PRIMARY_DEX      (int)primary_attack->query_dexterity()
#define PRIMARY_DISGUISE (int)primary_attack->query_disguise()
#define THIS_PLAYER_COM  (int)this_player()->query_combat()

int level;                   /* Level of being */  


string msgin;                /* Message for walking into a room */  
string msgout;               /* Message for walking out of a room */ 
string mmsgin;               /* Message for magical entry to a room */
string mmsgout;              /* Message for magical exit from a room */

string race;                 /* race of this being */

string *classes;             /* list of classes */

int hp;                      /* Number of hit points of being */  
int max_hp;                  /* Maximum number that hp may reach */
//int experience;              /* Experience poitns earned by being */
int money;                   /* Amount of gold coins possessed by being */
int age;                     /* Number of heartbeats being has existed */
//int alignment;               /* Numerical alignment of being */ 
int gender;                  /* Numerical gender of being... 0 = neuter 
                                                             1 = male  
                                                             2 = female */



static status is_npc;        /* Is the being not a player? */
int is_invis;                /* Use invis_name, short() = 0 */
static status is_alias;      /* Use alias_name */
static status brief;         /* In brief mode */


static object *followers;    /* objects following me */


/*** Primary skills ***/ 
int combat;           /* replaces dex, how well do you attack             */ 
int dexterity;        /* how well you defend against attacks              */ 
int intelligence;     /* do you perceive eg. thief's stealth              */ 
int wisdom;           /* wisdom - resistance to some spells               */ 
int charisma;         /* how good you are at shopping                     */ 
int constitution;     /* how many hit points                              */ 
int strength;         /* how much you can carry, also different to combat */ 

int max_combat;
int max_dexterity;
int max_intelligence;
int max_wisdom;
int max_charisma;
int max_constitution;
int max_strength; 



/*************************************************************************/
/* log */

void log(string file,mixed old, mixed new) {
  if(is_npc || !THIS_PLAYER_WIZ) return; 
  write_file("/log/MAIN/"+ file, "To: "+ query_name(1) +
                ";By: "+(string)this_player()->query_name(1)+
                ((new) ?  ";Old: "+old+";New: "+new : ";"+old)+
                ";Time: "+ctime(time())+";\n");
}

status test_dark() {
  if(set_light(0) > 0) return 0;
  write("It is dark.\n");
  return 1;
}

/*************************************************************************/
/* sets */

int set_level(int i) { 
# ifdef LOG_SET_LEVEL
    log(LOG_SET_LEVEL,level,i);
# endif /* LOG_SET_LEVEL */
  return level = i;
}


string set_msgin(string s)   { return msgin  = (s) ? s : 0;    }
string set_msgout(string s)  { return msgout = (s) ? s : 0;   }
string set_mmsgin(string s)  { return mmsgin  = (s) ? s : DEFAULT_MMSGIN;  }
string set_mmsgout(string s) { return mmsgout = (s) ? s : DEFAULT_MMSGOUT; }


string set_race(string str) {
  string race_type;
  int i;
  int *stats, *max_stats;
  string *stat_name;

# ifdef LOG_SET_RACE
log(LOG_SET_RACE,race,str);
# endif /* end LOG_SET_RACE */

  if(!str) str = "human";

  str = lower_case(str);
  race = str;
  sscanf(str, "%s %s", race_type, str);
  
  stats     = (int *)this_object()->query_start_stats();
  max_stats = (int *)this_object()->query_max_stats();


  if(!stats) 
    stats     = ({  2,  2,  2,  2,  2,  2,  2, });
  if(!max_stats)
    max_stats = ({ 25, 25, 25, 25, 25, 25, 25, });

  stat_name = ({   
      "constitution", "intelligence", "strength",   
      "combat",  "dexterity",    "wisdom", "charisma",
  });   

  if(str != "human") add_language(str);
  for(i=0; i<sizeof(stat_name); i++) {
    if(level < 1) {
      call_other(this_object(),"set_"+stat_name[i],stats[i]);
    }
    call_other(this_object(),"set_max_"+stat_name[i],max_stats[i]);
  }
  return race;
}

int set_hp(int i) { 
# ifdef LOG_SET_HP
    log(LOG_SET_HP, hp, i);
# endif /* LOG_SET_HP */
  return hp = i;
}


int set_max_hp(int i) {
# ifdef LOG_SET_MAX_HP
    log(LOG_SET_MAX_HP, max_hp, i);
# endif /* LOG_SET_MAX_HP */
  return max_hp = i;
}

int set_exp(int i) {
# ifdef LOG_SET_EXP
    log(LOG_SET_EXP, experience, i);
# endif /* LOG_SET_EXP */
  return experience = i;
}

int set_money(int i) {
# ifdef LOG_SET_MONEY
    log(LOG_SET_MONEY, money, i);
# endif /* LOG_SET_MONEY */
  return money = i;
}

int set_age(int i)       { return age        = i; }


int set_alignment(int i) {
# ifdef LOG_SET_ALIGN
    log(LOG_SET_ALIGN, alignment, i);
# endif /* LOG_SET_ALIGN */
  if(!intp(i)) return 0;
  return alignment = i;
}

int set_al(int i) { 
# ifdef LOG_SET_ALIGN
    log(LOG_SET_ALIGN, alignment, i);
# endif /* LOG_SET_ALIGN */
  if(!intp(i)) return 0;
  return alignment = i;
}


int set_gender(int i)    { return gender = ((i==2) ? 2 : ((i==1) ? 1 : 0)); }
int set_invis(int i)     { return is_invis = i;                             }


status set_disguise_on(int i)     { return disguise_on = (i) ? 1 : 0; }

status set_npc(status i)          { return is_npc = (i) ? 1 : 0;   }
status set_alias_status(status i) { return is_alias = (i) ? 1 : 0; }
status set_brief(int i)           { return brief = (i) ? 1 : 0;    }




string *set_classes(string *arr) { return classes = (arr) ? arr : ({}); }

/*** Primary skills ***/
int set_combat(int i)       { return combat       = i; }
int set_dexterity(int i)    { return dexterity    = i; }
int set_intelligence(int i) { return intelligence = i; }
int set_wisdom(int i)       { return wisdom       = i; }
int set_charisma(int i)     { return charisma     = i; }
int set_strength(int i)     { return strength     = i; }

int average_hp_multiplier() {
  int i, j, total;

  if((i = sizeof(classes))) {
    for(total = 0; i--;) { 
      if((j = member_array(classes[i], HP_PER_LEVEL)) != -1) {
        total += HP_PER_LEVEL[j+1];
      }
      else {
        log_file("HP_PER_LEVEL",
          "Class: "+ classes[i] +" is not defined in skills.h\n");
      }
    }
    return total/sizeof(classes);
  }
  return 8;
} 

int set_constitution(int i) {
  max_hp = 60 + i * average_hp_multiplier();
  max_hp -= POISON;
  return constitution = i; 
} 

int set_max_combat(int i)       { return max_combat       = i; }
int set_max_dexterity(int i)    { return max_dexterity    = i; }
int set_max_intelligence(int i) { return max_intelligence = i; }
int set_max_wisdom(int i)       { return max_wisdom       = i; }
int set_max_charisma(int i)     { return max_charisma     = i; }
int set_max_strength(int i)     { return max_strength     = i; }
int set_max_constitution(int i) { return max_constitution = i; }

/**************************************************************************/
/* query */

string query_current_room()      { return file_name(environment()); } 
string query_cap_name()          { return capitalize(query_name()); }

string query_invis_name()        { return invis_name;        }
string query_msgin()             { return msgin;             }
string query_msgout()            { return msgout;            }
string query_mmsgin()            { return mmsgin;            }
string query_mmsgout()           { return mmsgout;           }
string *query_classes()          { return classes;           }

string query_gender_string () {  
  return (gender == 2) ? "female" : (gender == 1) ? "male" : "neuter";
}  
    
string query_pronoun () {  
  return (gender == 2) ? "she" : (gender == 1) ? "he" : "it";
}  

string query_possessive () {  
  return (gender == 2) ? "her" : (gender == 1) ? "his" : "its";
}  

string query_objective () {  
  return (gender == 2) ? "her" : (gender == 1) ? "him" : "it";
}  

string query_race(status arg) {
  string tmp1, tmp2;
  if(!arg) return race;
  return (sscanf(race, "%s %s", tmp1, tmp2)) ? tmp2 : race;
}


varargs string query_name(status real) {
  return (real)
       ? lower_case(name)
       : (this_object()->query_ghost())
       ? DEFAULT_GHOST_NAME
       : (is_invis) 
       ? invis_name
       : (is_alias || disguise_on) 
       ? alias_name
       : (name)
       ? capitalize(name)
       : "";
}

nomask string query_real_name()  { return ((name) ? lower_case(name) : 0); }

int query_level()                { return level;             }
int query_hp()                   { return hp;                }
int query_max_hp()               { return max_hp;            }
int query_exp()                  { return experience;        }
int query_money()                { return money;             }
int query_age()                  { return age;               }
int query_alignment()            { return alignment;         }
int query_al()                   { return alignment;         }
int query_invis()                { return is_invis;          }

/*** Primary skills ***/ 
int query_combat()       { return combat;       }
int query_dexterity()    { return dexterity;    }
int query_intelligence() { return intelligence; }
int query_wisdom()       { return wisdom;       }
int query_charisma()     { return charisma;     }
int query_constitution() { return constitution; }
int query_strength()     { return strength;     }
int query_gender()       { return gender;       }

int query_max_combat()       { return max_combat;       }
int query_max_dexterity()    { return max_dexterity;    }
int query_max_intelligence() { return max_intelligence; }
int query_max_wisdom()       { return max_wisdom;       }
int query_max_charisma()     { return max_charisma;     }
int query_max_constitution() { return max_constitution; }
int query_max_strength()     { return max_strength;     }

status query_npc()               { return is_npc;            }
status query_alias_status()      { return is_alias;          }
status query_brief()             { return brief;             }

status query_followers(object obj) {
  return (member_array(obj, followers) == -1) ? 0 : 1;
}

status query_neuter() { return !gender;     }  
status query_male()   { return gender == 1; }  
status query_female() { return gender == 2; }  

status query_class(string str) {  
  if(!classes) classes = ({});
  return (member_array(str, classes) == -1) ? 0 : 1;
}  


object *query_all_followers()    { return followers;         }




/* primary stats */
void query_primary_stats() {
  string str, stat_str, *stat_name;
  int i;
  stat_name = ({ 
     "strength", "intelligence", "wisdom", "dexterity", 
     "combat", "charisma", "constitution",
  });

  for(i = 0,stat_str = ""; i < sizeof(stat_name); i++) {         
    str = capitalize(stat_name[i]) +".....................................";
    str = " "+str;  /* put a bit of a space in it */
    str = extract(str,0,15);
    str += query(stat_name[i])+"/"+query("max_"+stat_name[i]);
    str += "                               ";
    str = extract(str,0,25);

    if(i==2 || i == 5) str += "\n";
    stat_str += str;
  }
  if(i%2) stat_str += "\n";
  write(stat_str);
}

/**************************************************************************/
/* adj */

int adj_level(int i) {
# ifdef LOG_SET_LEVEL
    log(LOG_SET_LEVEL,level,level+i);
# endif /* LOG_SET_LEVEL */
  if(i > 0) adj_level_drained(-i);
  if(this_object()->query_level_drained() < 0)
    this_object()->adj_level_drained(-(int)this_object()->query_level_drained());
  return level += i; 
}


int adj_hp(int i) {
# ifdef LOG_SET_HP
    log(LOG_SET_HP, hp, hp+i);
# endif /* LOG_SET_HP */
hp = (hp+i > max_hp) ? max_hp : hp + i;
  if(hp < 0) {
    hp = 0;
    this_object()->death();
  }

 return hp;
}

int adj_max_hp(int i) { 
# ifdef LOG_SET_MAX_HP
    log(LOG_SET_MAX_HP, max_hp, max_hp+i);
# endif /* LOG_SET_MAX_HP */
  return max_hp += i;
}

int adj_exp(int i) {
# ifdef LOG_SET_EXP
    log(LOG_SET_EXP, experience, experience+i);
# endif /* LOG_SET_EXP */
  return experience += i; 
}

int adj_money(int i) {
# ifdef LOG_SET_MONEY
    log(LOG_SET_MONEY, money, money+i);
# endif /* LOG_SET_MONEY */^
  return money += i;
}

int adj_age(int i)       { return age        += i; }

void add_alignment(int i) {
  adj_alignment(i);
}

int adj_alignment(int i) {
# ifdef LOG_SET_ALIGN^
    log(LOG_SET_ALIGN, alignment, alignment+i);
# endif /* LOG_SET_ALIGN */
  return alignment += i;
}

void set_followers(object *obj) {
  if(!followers || !sizeof(followers)) followers = ({ });
  if(!sizeof(obj)) return;
  followers = obj;
}

void add_followers(object obj) {
  if(!query_followers(obj) && obj) followers += ({ obj, });
}


/*** Primary skills ***/ 
int adj_combat(int i)       { return combat       += i; }
int adj_dexterity(int i)    { return dexterity    += i; }
int adj_intelligence(int i) { return intelligence += i; }
int adj_wisdom(int i)       { return wisdom       += i; }
int adj_charisma(int i)     { return charisma     += i; }
int adj_strength(int i)     { return strength     += i; }

int adj_constitution(int i) { 
  constitution += i; 
  max_hp = 60 + constitution * average_hp_multiplier();
  max_hp -= POISON;
  return constitution;
} 

/****************************************************************************/
/* adds */  

status add_weight(int wt) {  
/* causes too long evaluation errors on long lists 
  recalc_carry();
 */
  if(wt + weight > strength + 15 + carry_bonus()) return 0;  
  weight += wt;  
  return 1;  
}  

int add_exp(int i) {
# ifdef LOG_SET_EXP^M
    log(LOG_SET_EXP, experience, experience+i);
# endif /* LOG_SET_EXP */
  experience += i;
  return i;
}
 
int add_money(int i) {
     return money += i;
}

void add_class(string str){  
  if(!query_class(str) && str) classes += ({ str, });
  this_object()->add_path("/bin/skills/classes/"+ str +"/");
}  



/****************************************************************************/
/* show age in clock time */  
string show_age(status arg) {  
  int i;
  string str;
  
  str = "Age: ";  
  i = age;  
  if(i/302400) {
    str += (i/302400) + " Weeks ";
    i = i - (i/302400)*302400;
  }
  if(i/43200) {  
    str += (i/43200) +" Days ";  
    i = i - (i/43200)*43200;  
  }  
  if(i/1800) {  
    str += (i/1800) +" hours ";  
    i = i  - (i/1800)*1800;  
  }  
  if(i/30) {  
    str += (i/30) +" minutes ";  
    i = i - (i/30)*30;   
  }  
  str += (i*2) +" seconds.\n";
  if(!arg) write(str);  
  return str;
}  



 
void remove_followers(object obj) {
  int i;
  if((i = member_array(obj, followers)) != -1) {
    followers = followers[0..i-1] + followers[i+1..sizeof(followers)-1];
  }
}


/**********************************************************************/
/* classes array stuff */




void remove_class(string str){  
  int i;
  if((i = member_array(str, classes)) != -1) {  
    classes = classes[0..i-1]+classes[i+1..sizeof(classes)-1];
  }
  this_object()->remove_path("/bin/skills/classes/"+ str +"/");
}     



/****************************************************************************/
/* initialise stuff */


void reset(status arg) {
  if(arg) return;
  msgout     = DEFAULT_MSGOUT;
  msgin      = DEFAULT_MSGIN;
  mmsgout    = DEFAULT_MMSGOUT;
  mmsgin     = DEFAULT_MMSGIN;
  invis_name = DEFAULT_INVISNAME;
  classes = STARTUP_CLASSES;

  followers = ({});


  this_object() -> spell_immune(({}));
  this_object() -> set_loaded_spell(({}));
  this_object() -> set_secondary_attacks(({}));
  this_object() -> set_armour_worn(({}));
  this_object() -> set_right_attack_msg(({}));
  this_object() -> set_left_attack_msg(({}));
  this_object() -> set_languages_known(({ "common", }));
  this_object() -> set_weapon_prof(([]));

}  


/***************************************************************************/
/* long */

void long(status wiz) {  
  string al;
  string str;

  if(query_ghost()) {
    write("You can see right through "+ query_objective() +"!\n");
    return;
  }
  ::long(wiz);

  al = (string)this_object()->query_al_title();
  if(al && !this_object()->query_security())
  sscanf(al,"(%s)",al);
  str = capitalize(query_pronoun());
  if(query_disguise_on()
  && !sizeof(compare("intelligence","disguise",({ this_object(),})))) {
    write(str + " vaguely looks like "+capitalize(query_name(1))+".\n");
}

  if(al && !this_player()->query_security())
    write(str + " is "+ al + "\n");
  if(race && race != "") {
    write(str + 
       ((race[0]=='a'||race[0]=='e'||race[0]=='i'||race[0]=='o'||race[0]=='u')
        ? " is an " + race +".\n"
        : " is a "  + race +".\n"));
  }
  this_object()->show_scar(); 
  str += " ";  
  str += (hp < max_hp/12) 
      ? "looks ready to meet "+query_possessive()+" death.\n"
      : (hp < max_hp/6)
      ? "has been horribly injured.\n"
      : (hp < max_hp/3)
      ? "looks badly wounded.\n"
      : (hp < (max_hp*2/3))
      ? "has sustained some minor wounds.\n"
     : "is "+ (hp == max_hp ? "unscathed and ": "") + "looking strong.\n";
  write(str);
}  

/****************************************************************************/
/* id */

status id(string str) {  
  return (race && str == race) 
      || ::id(str);
}  

/* support parse_command */
string *parse_command_id_list() {
	return (race) ? ::parse_command_id_list() :
	::parse_command_id_list() + ({ race });
}


/***************************************************************************/
/* move_player */

#ifdef DESTRUCT_DOMAIN_MOVE

void domain_destruct(object ob) {
  object *inv;
  int i;

  if(!ob) return;
  inv = all_inventory(ob);
  for(i = 0; i < sizeof(inv); i++) {
    if(!inv[i]->query_domain_safe()) {
      domain_destruct(inv[i]);
      inv[i]->drop(1);
      if(inv[i]) destruct(inv[i]);
    }
  }
}

#endif /* DESTRUCT_DOMAIN_MOVE */


varargs 
status move_player(string dir_dest,mixed optional_dest_ob,status safe) {
  string domain1, domain2, tmp1, tmp2;
  int i, n;
  string dir;
  mixed dest;  
  object *who, *inv, ob, *inv2;  
  status is_light;
  string verb;
  object *following_players, old_room;


  verb = query_verb();

  if(!optional_dest_ob) {  
    if(!sscanf(dir_dest, "%s#%s", dir, dest)) {  
      write("Move to bad dir/dest\n");  
      return 0;  
    }
  }  
  else {  
    dir = dir_dest;  
    dest = optional_dest_ob;  
  }

  if((status)dest->query_inside() && this_player()->query_horse_object()) {
    write("You can't take your steed in there. You'll have to leave it "+
    "outside.\n");
    return 1;
  }

  if((old_room = environment())) {
    if(this_object()->check_spell("Hold")) {
      write("Something prevents you from leaving.\n");
      return 0;
    }
    is_light = (set_light(0) > 0) ? 1 : 0;  
    if(is_light) {
      who = all_inventory(environment());  
#ifdef THIEF_H
      if(stealth_on) who = compare("stealth","intelligence",who);  
#endif /* THIEF_H */
      if(query_invis()) who = compare("invis","intelligence", who);
      
      if(dir == "X")  
        tell_objects(who, this_object()->query_name()+" "+
        this_object()->query_mmsgout()+".\n");
      else {
        if(query_msgout())
          tell_objects(who, this_object()->query_name()+" "+
                            this_object()->query_msgout()+" "+ dir +".\n");
      }
    }
  }
   
  following_players = (object *)this_object()->query_all_followers();
  if(verb && following_players && old_room) {
     move_object(this_object(), dest);
     for(i = 0; i < sizeof(following_players); i++) {
      if(!following_players[i]) continue;
      if(stealth_on || environment(following_players[i]) != old_room) {
        tell_object(following_players[i], (string)this_object()->query_name()
                   +" no longer seems to be here.\n");
        this_object()->remove_followers(following_players[i]);
      }
      else {
        tell_object(following_players[i], "You follow "+
          (string)this_object()->query_name() +" "+ verb +"...\n");
        command(verb, following_players[i]);
        if(environment(following_players[i]) != environment()) {
          this_object()->remove_followers(following_players[i]);
          tell_object(following_players[i], "You seem to lose your way.\n");
        }
      }
    }
  }
  else {
    move_object(this_object(), dest);
  }


  is_light = (set_light(0) > 0) ? 1 : 0;  
  if(is_light) {
    who = all_inventory(environment());  
#ifdef THIEF_H
    if(stealth_on) who = compare("stealth","intelligence",who);  
#endif /* THIEF_H */
    if(query_invis()) who = compare("invis","intelligence", who);
    
    if(dir == "X")  
      tell_objects(who, this_object()->query_name()+" "+
      this_object()->query_mmsgin()+".\n");
    else
      if(this_object()->query_msgin())
        tell_objects(who, this_object()->query_name()+" "+
        this_object()->query_msgin()+".\n");
  } 
  if(is_npc) return 1;
  if(!is_light) {  
    write("It is dark.\n");
    return 1;  
  }  
  ob = environment();  
  if(!present("Blindness")) {
      if(brief)  
          write(ob->short(THIS_PLAYER_WIZ) +".\n");  
      else
      {
          ob->do_vmap(this_player());
          //ob->long(THIS_PLAYER_WIZ);
      }
      show_inventory(ob);
  }
  else {
      write("It is dark.\nYou seem to be Blind!\n");
  }

#ifdef DESTRUCT_DOMAIN_MOVE

  if(objectp(dest)) {
    dest = file_name(dest);
  }  
  sscanf(query_current_room(),"d/%s/%s", domain1, tmp1);
  sscanf(dest,"d/%s/%s", domain2, tmp2);
  sscanf(dest, "/d/%s/%s", domain2, tmp2);
  if(this_player()->query_security_level()) safe = 1;
  if(!safe) {
    if(domain1 != domain2) {
      domain_destruct(this_object());
      write("Some of your equipment is lost in the Time-Domain Transfer.\n");
    }
  }
#endif /* DESTRUCT_DOMAIN_MOVE */

  return 1;
}  
 
status cpr() { 
  this_object() -> unload_spell();
  set_heart_beat(1); 
  write("Heart Started.\n");
  return 1;
} 


/****************************************************************************/
/* Externally Configurable bonuses */

int carry_bonus() {
  int bonus;
  int z;
  object alt;

  bonus = (int)this_object()->query_race_carry_bonus();

  for(z = 1; (alt = present(ALT+" "+z, this_object())); z++) {
    bonus += (int)alt->carry_bonus();
  }
  for(z = 1; (alt = present(GUILD_OB+" "+z, this_object())); z++) {
    bonus += (int)alt->carry_bonus();
  }
  return bonus;
}




/***************************************************************************/
/* carry, ac, wc calculators - these should fix problems */

void recalc_carry(){  
  int i, wt;  
  object *inv;  
 
  weight = 0;
  inv = all_inventory();  
  for(i = 0; i < sizeof(inv); i++){
    if(!inv[i]) continue;
    wt = (int)inv[i]->query_weight();  
    if(((wt+weight) > (strength+15+carry_bonus())) && !inv[i]->drop(1)) {
      tell_object(this_object(),"You cannot carry this much!!\n"+  
                                "You drop "+inv[i]->short()+"\n");
      move_object(inv[i],environment());
    }  
    else{    
      weight += wt;  
    }
  }
}  

 
 

/**************************************************************************/

string pad_str(string prefix,string str,int len) {
  int pad_len, i;
  string pad, tmp_str, new_str;

  pad_len = strlen(prefix);
  pad = "                                             "+
        "                                             ";
  pad = extract(pad,0,pad_len-1);
  str = prefix + str + " "; /* space flags end of string */
  new_str = "";
  if(len < 1 || len > 79) len = 75; /* line length */
  while(str && strlen(str)) {
    if(new_str != "") str = "\n"+ pad+str;
    tmp_str = extract(str,0,len); /* get 1 line */
    for(i = strlen(tmp_str)-1; i >= pad_len && tmp_str[i] != ' '; i--);
    if(i <= pad_len) i = strlen(tmp_str)-2; /* no spaces! */
    tmp_str = extract(str,0,i);
    str = extract(str,i+1);
    new_str += tmp_str;
  }
  return new_str +"\n";
}


string filter_ansi(string str) {
  string rest, tmp;

  str = str +"";
  while(sscanf(str,"%s"+ESC+"%sm%s",str, tmp, rest) == 3) str += rest;
  return str;
}

