#pragma strict_types
#pragma save_types
#pragma combine_strings

#include <mudlib.h>
inherit LIVING;


#include <monster.spc>
#include <humanoid.h>
#include <spell.h>  /* Must come after monster.spc */


#define HEALING_TIME       60  /* 60 hearbeats */ 
#define STOLEN_TIME       180  /* 180 heart beats call reset(1) */  
#define FILE_SIZE         (int)MASTER->master_file_size

#define MAX_WANDER_TIME	  4000

status move_at_reset;   /* True will make the monster wander at reset. */  
status aggressive;      /* True will make monster attack on sight. */  

int stolen;             /* has something been stolen */ 
//int healing;            /* heart_beats since last healing */  
  
string *remembered_names;
string *chat_head;       /* list of chat strings. */  
int chat_chance;         /* chance at each heart beat to chat */
  
string *a_chat_head;     /* list of attack chats */  
int a_chat_chance;       /* chance at each heart beat to use attack chat */
  
string *l_chat_head;     /* list of chats spoken in language */
string chat_language;    /* language chats spoken in */
int l_chat_chance;       /* chance each heart beat to chat */
  

object dead_ob;          /* alternative objects to call fn */  
object init_ob;  
object heart_ob;  
  
int random_pick;        /* Chance to pick up items every heart_beat. */  

int wander;             /* wander at this many heart beats */  
int wander_time;        /* Counter for wandering */  
 
int new_spell_chance;   /* chance each heart beat to cast spell */
string *new_spells;     /* list of 'player' spell commands */ 

int spell_chance;       /* chance each heart beat to cast spell */
mixed *default_spell;   /* specialized spell of monster */

int steal_chance;       /* chance per init to steal */

status no_kill_flag;   /* won't allow attacks on monster */

static string skill_cmd; /* current skill command */

static string wander_file; /* file string he can wander */

/***************************************************************************/ 
  


void reset(status arg) {  
  ::reset(arg);
  if(arg) {  
    if(stolen) {
      if(environment()) environment()->reset(1); 
    }    
    stolen = 0;
    if(move_at_reset) random_move();  
    return;  
  }  
  is_npc = 1;  
  msgin = "arrives";
  msgout = "leaves";
  remembered_names = ({ });
  enable_commands();  
  add_class("fighter");
  /* all monsters start off as a fighter, add or subtract the ones u want */
  add_action("communicate","say");  
  add_action("change_language", "speak");
  add_action("skills", "", 1);
  default_spell = allocate(SPELL_ALLOCATE);
}  

  

/*************************************************************************/
/* sets */

object set_heart_ob(object ob) { return heart_ob = ob; }  
object set_dead_ob(object ob)  { return dead_ob = ob;  }  
object set_init_ob(object ob)  { return init_ob = ob;  }  

int set_random_pick(int r)     { return random_pick = r; }  
int set_steal_chance(int s)    { return steal_chance = s; }
int query_steal_chance()       { return steal_chance; }
status set_no_kill_flag(status s) { return no_kill_flag = (s) ? 1 : 0; }

status set_move_at_reset(status i) { return move_at_reset = (i) ? 1 : 0; }  
status set_aggressive(status a)    { return aggressive = (a) ? 1 : 0; }  

string set_name(string n) {  
  set_living_name(lower_case(n));  
  set_short(capitalize(n));
  set_alt_name(lower_case(n));
  return ::set_name(capitalize(n));
}  

string set_domain(string file) { return wander_file = file; }
string query_domain()          { return wander_file;        }

/*** set level will automatically set monster to bare minimum requirements ***/ 
  

int set_level(int l) {  
   int *monster_exp; 
 
   if(!intp(l) || l < 1) l = 1; 
   level = l;  
   combat = l;       dexterity = l; strength = l; charisma = l; 
   intelligence = l; wisdom = l;    constitution = l; 

   /* Adding a spot for our classes -Critical */

   /* Pointman Class skills set*/
   if(query_class("pointman")){
   fighting = l;  protecting = l;   preparing = l;
   two_weapon = l;  multi_attack = l;    multi_opponent = l;
   }
   
   /*Medic Class skills set*/
   if(query_class("medic")){
   mhealing = l; preventing = l; enhancing = l; healing = l;
   }
   
   /*Scout Class skills set*/
   if(query_class("scout")){
   exploring = l; surviving = l; evading = l;
   stealth = l; locks = l; climb = l; backstab = l;
   traps = l;
   }
   
   /*Techman class skills set*/
   if(query_class("techman")){
   creating = l; destroying = l; sensing = l; 
   }
   
   /*** set thief skills ***/  
   if(query_class("thief")) { 
     stealth = l; locks = l; steal = l; climb = l; backstab = l; 
     appraisal = l; traps = l; 
   }
 
   /*** set fighting skills ***/ 
   if(query_class("fighter")) { 
     two_weapon = l; unarmed = l; multi_attack = l; multi_opponent = l;
   } 

   /*** set cleric skills ***/ 
   if(query_class("cleric")) { 
     healing_sphere = l; necromancy_sphere = l; combat_sphere = l; 
     stellar_sphere = l; protection_sphere = l; nature_sphere = l; 
     divination_sphere = l; 
     adj_all_cleric(l*2);
   }
 
   /*** set mage skills ***/ 
   if(query_class("mage")) {
     illusion = l; charm = l; conjuration = l; abjuration = l; 
     necromancy = l; evocation = l; divination = l; alteration = l; 
     adj_all_mage(l*2);
   } 
 
   /*** set psionicist skills ***/ 
 
/*
   if(query_class("psionicist")) {
     clairsentient = l; psycokinetic = l; psycoportive = l; 
     psycometabolic = l; telepathic = l; metapsionic = l; 
     max_psionic_points = 6 * l; 
   }
*/

   heal_self(10000); 
 
   /*** set weapon class ***/ 
 
   set_right_wc(l+5); 
   if(query_right_wc() > 30) set_right_wc(30); 
 
   /*** set armour class ***/ 
 
   if(l < 14) 
     armour_class = l/2 + 3; 
   else 
     armour_class = l - 3; 
   if(armour_class > 17) armour_class = 17; 
 
   /*** set hit points and spells points? ***/ 
 
   if(l < 5) 
     hp = l * 10 + 40; 
   else if(l < 10) 
     hp = l * 50 - 150; 
   else if(l < 15) 
     hp = l * 100 - 600; 
   else if(l < 20) 
     hp = l * 200 - 2000; 
   else if(l < 25)  
     hp = l * 300 - 3900; 
   else 
     hp = 3500; 
   max_hp = hp; 
 
   /*** set experience points ***/ 
 
   monster_exp = ({ 
                676,    1014,   1522,   2283,   3425,   5138, 
               7707,   11561,  17341,  26012,  39018,  58527, 
              87791,  131687, 197530, 296296, 444444, 666666, 
            1000000, 1500000,2000000,2500000,3000000,3500000, 
            4000000, 4500000 
                 }); 
 
   if(l > sizeof(monster_exp) - 1) { 
     experience = monster_exp[sizeof(monster_exp) - 1]; 
     experience += (l - (sizeof(monster_exp) - 1)) * 500000; 
   } 
   else 
     experience = monster_exp[l]; 
 
   /*** high level monsters do additional damage ***/ 
 
/*** removed so monsters will cast their normal spells!
  if(l > 15) {
    spell_chance = ((l - 14)*10 > 75) ? 75 : (l - 14)*10; 
    TARGET_MSG   = "A fireball erupts, cast directly at you!\n"; 
    ROOM_MSG     = "@@query_name:$this_player()$@@ casts a fireball at "+        
                   "@@query_name:$this_object()$@@.\n"; 
    IMMUNE_TYPE  = "fire"; 
    SPELL_TYPE   = "evocation"; 
    SPELL_DAM    = (l - 14) * 5 + random((l - 14) * 5); 
    SPELL_LEVEL  = l;
    SPELL_COST   = 2; * spell strength runs out eventually *
  } 
  ****/
	return level;
}  
  

void add_class(string str) {
  ::add_class(str);

  
  /*Adding our classes to this list too -Critical */
  /* Pointman Class skills set*/
   if(query_class("pointman")){
   fighting = level;  protecting = level;   preparing = level;
   two_weapon = level;  multi_attack = level;    multi_opponent = level;
   }
   
   /*Medic Class skills set*/
   if(query_class("medic")){
   mhealing = level; preventing = level; enhancing = level; healing = level;
   }
   
   /*Scout Class skills set*/
   if(query_class("scout")){
   exploring = level; surviving = level; evading = level;
   stealth = level; locks = level; climb = level; backstab = level;
   traps = level;
   }
   
   /*Techman class skills set*/
   if(query_class("techman")){
   creating = level; destroying = level; sensing = level; 
   }
  
   /*** set thief skills ***/  
   if(query_class("thief")) { 
     stealth = level; locks = level; steal = level; climb = level; 
     backstab = level; appraisal = level; traps = level; 
   }
 
   /*** set fighting skills ***/ 
   if(query_class("fighter")) { 
     two_weapon = level; unarmed = level; multi_attack = level;
     multi_opponent = level;
   } 

   /*** set cleric skills ***/ 
   if(query_class("cleric")) { 
     healing_sphere = level; necromancy_sphere = level;
     combat_sphere = level; stellar_sphere = level;
     protection_sphere = level; nature_sphere = level; 
     divination_sphere = level; 
     adj_all_cleric(level*2);
   }
 
   /*** set mage skills ***/ 
   if(query_class("mage")) {
     illusion = level; charm = level; conjuration = level; abjuration = level; 
     necromancy = level; evocation = level; divination = level;
     alteration = level; 
     adj_all_mage(level*2);
   } 
 
   /*** set psionicist skills ***/ 
/*
   if(query_class("psionicist")) {
     clairsentient = level; psycokinetic = level; psycoportive = level; 
     psycometabolic = level; telepathic = level; metapsionic = level; 
     max_psionic_points = 6 * level; 
   }
*/
}


void set_wander(int chance, int time) {  
   wander = time;  
   set_heart_beat(1); 
}  

/************************************/
/* old way for spells */
 
int set_chance(int c)    { return spell_chance = c; }  
int set_spell_dam(int d) { return SPELL_DAM = d; }  
  
string set_spell_mess1(string m) { return TARGET_MSG = m; }  
string set_spell_mess2(string m) { return ROOM_MSG = m; }  
string set_spell_type(string t)  { return IMMUNE_TYPE = t; }  
 
string set_spell_skill_type(string str) { 
   string *spell_skills; 
 
   spell_skills = ({ 
     "healing_sphere", "necromancy_sphere", "combat_sphere", 
     "stellar_sphere", "protection_sphere", "nature_sphere", 
     "divination_sphere", "illusion", "charm", "conjuration", 
     "abjuration", "necromancy", "evocation", "divination", 
     "alteration", 
                  }); 
 
   if(!str || member_array(str, spell_skills) == -1) { 
     str = spell_skills[random(sizeof(spell_skills))]; 
   } 
   return SPELL_TYPE = str; 
}  
 
/**************************************/
/* new way */

void set_spell(mixed *arr) {
  int i;

  default_spell = allocate(SPELL_ALLOCATE); 
  for(i = 0; i < sizeof(arr); i++) {
    if(!stringp(arr[i])) continue;
    switch(arr[i]) {
      case "target":                    TARGET      = arr[++i];     break;
      case "name": case "spellname":    SPELL_NAME  = arr[++i];     break; 
      case "school": case "sphere":     SPELL_TYPE  = arr[++i];     break;
      case "cost":                      SPELL_COST  = arr[++i];     break;
      case "damage":                    SPELL_DAM   = arr[++i];     break;
      case "msg target":                TARGET_MSG  = arr[++i];     break;
      case "msg room":                  ROOM_MSG    = arr[++i];     break;
      case "msg caster":                CASTER_MSG  = arr[++i];     break;
#ifdef OLD_AREA_EFFECT
      case "area":                    AREA_EFFECT = this_object();  break;
#else
      case "area":    AREA_EFFECT = all_inventory(environment());   break;
#endif
      case "immune":                    IMMUNE_TYPE = arr[++i];     break;
      case "level": case "spell level": SPELL_LEVEL = arr[++i];     break;
      case "spell object":              SPELL_OBJ   = arr[++i];     break;
      case "time": case "cast time":    SPELL_TIME  = arr[++i];     break;
      case "casting msg":               PREPARE_MSG = arr[++i];     break;
      case "casting msg room":        PREP_MSG_ROOM = arr[++i];     break;    
      case "component":                 COMPONENT   = arr[++i];     break;
      case "passive":                   PASSIVE     = 1;            break;
      case "aggressive":                PASSIVE     = 0;            break;
      case "chance":                   spell_chance = arr[++i];     break;
    }
  }
}


/* can call player spells */

void load_spells(int c, string *s) { 
  sizeof(s); 
  new_spells = s; 
  new_spell_chance = c; 
} 
 

/*************************************************************************/
/* query */

status query_no_kill_flag() { return no_kill_flag; }
  




/***********************************************************************/
/* heart beat */

static status filter_players(object ob) {
  if(living(ob) && !ob->query_npc()) return 1;
  return 0;
}

void heart_beat() {  
  string tmp1, tmp2;
  int player_here, i;
  string cmd;
  object *inv;
  
  if(!environment()) {
    set_heart_beat(0);
    return;
  }
  adj_age(1);  
  if(heart_ob) heart_ob->monster_heart_beat();  

  if(!environment()) return;
  inv = all_inventory(environment());
  player_here = sizeof(filter(inv,"filter_players",this_object()));
  if(stolen) {
    if(stolen++ > STOLEN_TIME) reset(1);
  }
  if(!player_here) {
    if(hp < max_hp) {
      if(healing++ > HEALING_TIME) {
        healing = 0;
        heal_self(1);
      }     
    }
    else if(!wander && !stolen) { 
      set_heart_beat(0);  
      return; 
    }
    if(wander) {  
/*
      if(age > MAX_WANDER_TIME) {
        set_heart_beat(0);
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
          if(inv[i]) destruct(inv[i]);
        }
        destruct(this_object());
        return;
      }
*/
      if(wander_time++ > wander && !random(4)) {
        random_move();  
        if(wander_file)
          if(!sscanf(
            file_name(environment()), "%s"+wander_file+"%s", tmp1, tmp2)){
            say(query_name(0)+" leaves for "+create_room->short()+".\n");
            move_object(this_object(), query_create_room());
          }
      } 
    }
    return;
  }
  if(primary_attack && present(primary_attack, environment())) {
    if(a_chat_chance > random(100) + 1) {  
      tell_room(environment(), a_chat_head[random(sizeof(a_chat_head))]);  
    }
    if(spell_chance > random(100) + 1) {
      if(objectp(SPELL_TYPE)) { /* wand */
        if((int)SPELL_TYPE->query_charges() > SPELL_COST) {
          set_loaded_spell(default_spell);
          SPELL_TYPE->adj_charges(-SPELL_COST);
        }
      }
      else if(query(SPELL_TYPE+"_points") > SPELL_COST) {
        set_loaded_spell(default_spell);
        call_other(this_object(),"adj_"+SPELL_TYPE+"_points",-SPELL_COST);
      }
    }
    if(new_spell_chance > random(100) + 1) { 
    /** stuff goes in here to make a monster cast the spell!
        same spells as players cast
    ******/
      if(new_spells && sizeof(new_spells))
        init_command(new_spells[random(sizeof(new_spells))]);
    } 
    if(query_wimpy() && hp < max_hp/5) random_move();  
  }  
  else {
    if(chat_chance > random(100) + 1) {  
      tell_room(environment(), chat_head[random(sizeof(chat_head))]);  
    }
    if(l_chat_chance > random(100) + 1) {  
      command("speak "+chat_language);
      command("say "+l_chat_head[random(sizeof(l_chat_head))]);
    }  
  }  
  if(random_pick > random(100) + 1) {  
    pick_any_obj();  
  }  
  attack();  
}  

  
/**************************************************************************/  
 
status init_command(string cmd) {
      status cmd_flag;
      
      if(sscanf(cmd, "%s %s", skill_cmd, cmd)) {
        cmd = skill_cmd +" "+ cmd;
      }
      else {
        skill_cmd = cmd;
      }
      cmd_flag = command(cmd, this_object());
      skill_cmd = 0;
      return cmd_flag;
}
  



/***************************************************************************/  
/***   Load Chats and Attack chats.   ***/  
 
void load_chat(int chance, string *strs) {  
   if(!sizeof(strs)) return;     /* Just ensure that it is an array. */  
   chat_head = strs;  
   chat_chance = chance;  
}  
  
void load_a_chat(int chance, string *strs) {  
   if(!sizeof(strs)) return;     /* Just ensure that it is an array. */  
   a_chat_head = strs;  
   a_chat_chance = chance;  
}  
  
/***   Load language chat - Zilanthius ***/  
  
void load_l_chat(int chance, string lang, string *strs) {  
   if(!sizeof(strs)) return;     /* Just ensure that it is an array. */  
   l_chat_head = strs;  
   l_chat_chance = chance;  
   chat_language = lang;  
   add_language(chat_language);
   if(!chat_language){  
     if(race)  
       chat_language = lower_case(race);  
     else  
       chat_language = "common";  
   }  
}    
  
  
/****************************************************************************/
  
status second_life() {  
  if(dead_ob) return (status)dead_ob->monster_died(this_object());  
}  
  

/****************************************************************************/
  
void pick_any_obj () {  
  object ob;  
  int weight;  
  
  ob = first_inventory(environment());  
  while (ob) {  
    if(ob->get() && ob->short()) {  
      weight = (int)ob->query_weight();  
      if(!add_weight(weight)) {  
        say (query_name()+" tries to take "+ob->short()+" but fails.\n");  
        return;  
      }  
      move_object(ob, this_object());  
      say(query_name() +" takes "+ ob->short() +".\n");  
      return;  
    }  
    ob = next_inventory(ob);  
  }  
}  

/************************************************************************/


void init() {  
  string who;

  ::init();
  if(this_player() == this_object()) return;  
  if(init_ob && init_ob->monster_init(this_object())) return;  
  if(primary_attack) set_heart_beat(1);     /* Turn on heart beat */  
  if(!this_player()->query_npc()) {  
    if(!this_player()->query_entering()) {
      who = (string)this_player()->query_name(1);
      if(!sec_att_names) sec_att_names = ({});
      if(member_array(who, sec_att_names) != -1
      || (who && member_array(capitalize(who), sec_att_names) != -1)){
        add_secondary_attacker(this_player());
      }
    }
    set_heart_beat(1);  
    if(aggressive) { 
      string rname;

      rname = (string)this_player()->query_name(1);
      if(query_class("thief")) stealth_on = 1; /* needed for bs */
      if(this_player()->query_stealth_on()) {
        if(sizeof(compare("stealth","intelligence", ({ this_object(), })))) {
          if(query_class("thief")) {
            skill_cmd = "backs";
            command("backs "+ rname, this_object());
            skill_cmd = 0;
          }
          add_secondary_attacker(this_player()); /* get ready to attack */
        }
      }
      else if(this_player()->query_invis()) {          
        if(sizeof(compare("invis","intelligence", ({ this_object(), })))) {
          if(query_class("thief")) {
            skill_cmd = "backs";
            command("backs "+ rname, this_object());
            skill_cmd = 0;
          }
          add_secondary_attacker(this_player()); /* get ready to attack */
        }
      }
      else {
        if(query_class("thief")) {
          skill_cmd = "backs";
          command("backs "+ rname, this_object());
          skill_cmd = 0;
        }
        add_secondary_attacker(this_player()); /* get ready to attack */
      }  
    }  
    else { /* not aggressive */
      if(query_class("thief") && random(100) < steal_chance) { 
        steal_from_player(this_player(),0);
      }
    }
  }  
}
  
  
/*** stealing from a monster, call "steal" if something is stolen... ***/ 
 
void steal() { 
  stolen = 1; 
  set_heart_beat(1);
} 
 
void steal_from_player(object who, mixed item) {
  object *inv;
  int i;
  string item_name;

  if(!item) {
    inv = all_inventory(this_player());
    if(!(i = sizeof(inv))) return;
    i = random(i);
    if(!(item_name = (string)inv[i]->query_name())) return;
  }
  else if(objectp(item)) {
    item_name = (string)item->query_name(1);
  }
  else if(stringp(item)) {
    item_name = item;
  }
  else {
    return;
  }
  skill_cmd = "steal";
  command("steal "+ item_name +" from "+ (string)who->query_name(1));
  skill_cmd = 0;
}

/************************************************************************/ 

/* load function added by Crombie, Sept 8, 1993 */

void load_monster(mixed name, int lev, string race) {
  int i, size;

  if(!stringp(name)) {
    for(i = 0, size = sizeof(name); i < size; i++) {
      if(!stringp(name[i])) continue;
      switch(name[i]) {
        case "name":             set_name(name[++i]);          break;
        case "level":            set_level(name[++i]);         break;
        case "alias":            set_alias(name[++i]);         break;
        case "race":             set_race(name[++i]);          break;
        case "hp":               set_hp(name[++i]);            break;
        case "exp":              set_exp(name[++i]);           break;
        case "al":               set_al(name[++i]);            break;
        case "short":            set_short(name[++i]);         break;
        case "long":             set_long(name[++i]);          break;
        case "altname":          set_alt_name(name[++i]);      break;
        case "alt_name" :        set_alt_name(name[++i]);      break;
        case "wc":               set_right_wc(name[++i]);      break;
        case "ac":               set_ac(name[++i]);            break;
        case "aggressive":       set_aggressive(1);            break;
        case "whimpy":           set_wimpy(1);                 break;
        case "move_at_reset":    set_move_at_reset(1);         break;
        case "chance":           set_chance(name[++i]);        break;
        case "heart_ob":         set_heart_ob(this_object());  break;
        case "mess1":            set_spell_mess1(name[++i]);   break;
        case "spell_mess1":      set_spell_mess1(name[++i]);   break;
        case "mess2":            set_spell_mess2(name[++i]);   break;
        case "spell_mess2":      set_spell_mess2(name[++i]);   break;
        case "dam":              set_spell_dam(name[++i]);     break;
        case "spell_dam":        set_spell_dam(name[++i]);     break;
        case "spell_type":       set_spell_type(name[++i]);    break;
        case "spell_skill_type": set_spell_skill_type(name[++i]);     break;
        case "gender":           set_gender(name[++i]);        break;
        case "deadob":           set_dead_ob(this_object());   break;
        case "randompick":       set_random_pick(name[++i]);   break;
        case "init_command" :    init_command(name[++i]);      break;
        case "random_pick":      set_random_pick(name[++i]);   break;
        case "magic_resist" :    set_magic_resist(name[++i]);  break;
        case "add_money" :       add_money(name[++i]);         break;
        case "money" :           add_money(name[++i]);         break;
      }
    }
  }  
  else {
    set_name(name);
    set_level(lev);
    set_race(race);
  }
}


/*********************************************************************/

/*
int hit_player(int dmg) {
  if((status)environment(this_player())->query_no_fight()) {
    if(this_player()) this_player()->stop_fight(this_object());
    stop_fight(this_player());
    write("Fighting is Not Allowed Here.\n");
    return 0;
  }
  return (int)combat::hit_player(dmg);
}
*/


/*********************************************************************/
/* monster skill commands */

status skills(string str) {
  string verb;
  int i;

  verb = query_verb();
  /* verb must match current skill command */
  if(verb != skill_cmd) {
    skill_cmd = 0;
    return 0;
  }
  skill_cmd = 0;
    
  for(i = 0; i < sizeof(classes); i++) {
    if(FILE_SIZE("/bin/skills/classes/"+ classes[i] +"/"+ verb +".c") > 0) {
      if(call_other("bin/skills/classes/"+ classes[i] +"/"+ verb,verb,str)) return 1;
    }
  }
  return 0;
}


void delayed_message(mapping map) {
  string tmp;
  object ob;


  tmp = map["msg"];
  ob = map["ob"];

  if(present(ob, environment()))
  if(tmp) say(tmp, this_object());
}


/*Emraef, if you can...make this whole stupid function go away.
    It basically scans the room and responds at random to what people say in
    the room the mob lives in. Its sayes the stupidest crap and in general is
    just crazy annoying.

    -Critical
*/

void catch_tell(string str) {
  string tmp1, tmp2;
  string tmp3, tmp4;
  mapping map;
  string message;
  object ob;
  int n;

  if(!humanoid(this_object())) return;
  if(query_attack()) return;

  n = random(100);

  if(sscanf(str, "%s says: %s\n", tmp1, tmp2)) {
    if(!tmp2) return;
    /* don't know how someone can 'say:', as they should mumble
       but it has happened before and stops monsters hearts */

    tmp2 = lower_case(tmp2);
    ob = present(lower_case(tmp1));
    if(!ob) return;
    if(!ob->id("PLAYER")) return;




    if(sscanf(tmp2, "%sfine%s", tmp1, tmp3) ||
       sscanf(tmp2, "%swell%s", tmp1, tmp3) ||
       sscanf(tmp2, "%sgood%s", tmp1, tmp3)) {
      if(n < 5)
        message = query_name()+" says: Thanks be to the gods that you "+
                  "are well, "+ob->query_name()+".\n";
      else if(n < 10)
        message = query_name()+" says: That is good to hear, "+
                  ob->query_name()+".\n";
      else if(n < 15)
        message = query_name()+" says: Health is not everything, "+
                  ob->query_name()+".\n";
      else
        message = query_name()+" says: Praise be to the gods.\n";
      map = ([ "ob": ob, "msg": message, ]);
      call_out("delayed_message", 1, map);
    }


    if(sscanf(tmp2, "%shi%s", tmp3, tmp4) ||
       sscanf(tmp2, "%shello%s", tmp3, tmp4) ||
       sscanf(tmp2, "%swell met%s", tmp3, tmp4) ||
       sscanf(tmp2, "%sgreeting%s", tmp3, tmp4) ||
       sscanf(tmp2, "%shullo%s", tmp3, tmp4)) {
      ob = present(lower_case(tmp1), environment());
      if(!ob) return;
      if(!ob->id("PLAYER")) return;


      if(member_array(ob->query_name(), remembered_names) != -1) {
        if(n < 10)
          message = query_name()+" says: Ahh, yes. I remember you, "+
                    ob->query_name()+". How are you?\n";
        else if(n < 20)
          message = query_name()+" says: It's been some time since we "+
                    "last spoke, "+ob->query_name()+".\n";
        else 
          message = query_name()+" says: It is good to talk to you again, "+
                    ob->query_name()+".\n";
        map = ([ "ob": ob, "msg": message, ]);
        call_out("delayed_message", 1, map);
        return;
      }

      if(n < 10)
        message = query_name()+" says: Hail, and well met, "+
                  ob->query_name()+".\n";
      else if(n < 20)
        message = query_name()+" says: Welcome to "+
                  environment()->short()+", "+ob->query_name()+".\n";
      else if(n < 30)
        message = query_name()+" ignores you.\n";
      else if(n < 40)
        message = query_name()+" says: Hello, "+ob->query_name()+". "+
                  "How are you this day?\n";
      else if (n < 50)
        message = query_name()+" says: Greetings to you.\n";
      else if (n < 60)
        message = query_name()+" says: I bring you greetings from my people, "+
                  ob->query_name()+".\n";
      else
        message = query_name()+" says: I'm rather busy at the moment.\n";
      map = ([ "ob": ob, "msg": message, ]);
      remembered_names += ({ ob->query_name(), });
      call_out("delayed_message", 1, map);
      return;
    }
  }

  if(sscanf(str, "%s asks: %s\n", tmp1, tmp2)) {
    ob = present(lower_case(tmp1), environment());
    if(!ob) return;
    if(!ob->id("PLAYER")) return;


    tmp2 = lower_case(tmp2);

    if(sscanf(tmp2, "%swhat%s", tmp3, tmp4)) {
      tmp4 = lower_case(tmp4);
      if(sscanf(tmp4, "%syour name%s", tmp1, tmp2)) {
        message = query_name()+" says: My name is "+query_name()+", "+
                  ob->query_name()+".\n";
        map = ([ "ob": ob, "msg": message, ]);
        call_out("delayed_message", 1, map);
        return;
      }
      if(sscanf(tmp4, "%syou age%s", tmp1, tmp2)) {
        if(n < 50)
          message = query_name()+" asks: Why do you want to know?\n";
        else
          message = query_name()+" says: Now, that would be telling, "+
                    ob->query_name()+".\n";
        map = ([ "ob": ob, "msg": message, ]);
        call_out("delayed_message", 1, map);
        return;
      }

      if(n < 10)
        message = query_name()+" says: I'm not doing much.\n";
      else if(n < 15)
        message = query_name()+" asks: Why do you ask, "+
                  ob->query_name()+"?\n";
      else if(n < 20)
        message = query_name()+" says: I am simply biding my time here, "+
                  "in "+environment()->short()+".\n";
      else if (n < 30)
        message = query_name()+" says: Perhaps you should ask the gods?\n";
      map = ([ "ob": ob, "msg": message, ]);
      call_out("delayed_message", 1, map);
      return;
    }

    if(sscanf(tmp2, "%show are you%s", tmp3, tmp4) ||
       sscanf(tmp2, "%show do you feel%s", tmp3, tmp4) ||
       sscanf(tmp2, "%syou feel%s", tmp3, tmp4)) {
      if(n < 5)
        message = query_name()+" says: I'm well, thank you "+
                ob->query_name()+".\n";
      else if(n < 15)
        message = query_name()+" says: Fine. Thank you for asking.\n";
      else
        message = query_name()+" asks: Ah, my condition is not the "+
                  "question. How are you, "+ob->query_name()+"?\n";
      map = ([ "ob": ob, "msg": message, ]);
      call_out("delayed_message", 1, map);
      return;
      return;
    }

    if(n < 5)
      message = query_name()+" asks: Why do you say, '"+tmp2+"'?\n";
    else if(n < 10)
      message = query_name()+" says: "+ob->query_name()+", you do ask "+
                "alot of questions, don't you.\n";
    else if(n < 15)
      message = query_name()+" asks: How should I know, "+
                ob->query_name()+"?\n";
    else if(n < 20)
      message = query_name()+" thinks deeply about the question.\n";
    else if(n < 25)
      message = query_name()+" says: I don't have an opinion on that one.\n";
    else if(n < 30)
      message = query_name()+" asks: But how does that make you feel, "+
                ob->query_name()+"?\n";
    else if(n < 35)
      message = query_name()+" exclaims: That is a tough question indeed!\n";
    else if(n < 40)
      message = query_name()+" asks: "+tmp2+"?, I think that's one for the "+
                "Gods to decide!\n";
    else if(n < 45)
      message = query_name()+" says: Sorry, "+ob->query_name()+". I was "+
                "thinking about something else.\n";
    else if(n < 50)
      message = query_name()+" says: I don't think that is very "+
                "relevant, "+ob->query_name()+".\n";
    map = ([ "ob": ob, "msg": message, ]);
    call_out("delayed_message", 1, map);
    return;
  }



  if(map) call_out("delayed_message", 1, map);
  return;
}

string query_object_type() { return "Monster"; }
