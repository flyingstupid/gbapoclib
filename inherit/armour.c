#pragma strict_types
#pragma save_types
#pragma combine_strings

#include <mudlib.h>
#include <combat.cfg>
inherit BASE;


/* armour materials, resilience. eventually armour is destroyed */

#define ARM_MOD 1
#define STR_MOD  6           /*  When the current str is this, -1 ac & wt */ 
 
#define MAX_REPAIR 3          /* max times armour can be repaired */  
#define ARM_COMPLEXITY 14 
  
#define CLASS_ALLOWED_ARMOUR(WHO) \
  call_other("/function/am_allow", "allowed_armour", \
  WHO,query_name(),query_type(),query_armour_material())

string armour_mat;           /* the material of the armour  */  
int max_strength;            /* Max dam armour can take */  
int current_strength;        /* current value of strength */  
int repair;                  /* amount of times the armour been repaired */  
int absorb_dam;              /* amount of dam armour can absorb */  


/* armour basics */

string type;                 /* armour type, also an identifier */  
status worn;                 /* flag true if worn */  
int armour_class;            /* armour class value of the armour */  
object worn_by;              /* who wears this */  



/*** function prototypes ***/

/* actions */

status wear(string str);
status remove(string str);
void hit_armour(int damage);
void calc_strength();
int repair_armour(int i);
string set_type(string s);
int set_ac(int ac);
int set_current_strength(int i);
int set_max_strength(int i);
int set_repair(int i);
string set_armour_material(string arg);
status set_worn(status i);
object set_worn_by(object ob);
void set_arm_light(int i);

/* query */  
  
int armour_class();
int query_ac();
status query_worn();
object query_worn_by();
string query_type();
string query_armour_material();
int query_current_strength();
int query_armour_strength();
int query_max_strength();
int query_compexity();
int query_complex();
int query_repair();
int query_max_value();
void load_armour(mixed *arg);


/**************************************************************************/
/**************************************************************************/  
/***           Standard operation functions for armour objects.         ***/  
  
void reset(status arg) {
  if(arg) return;

  set_short("Chainmail");
  set_name("chainmail");
  set_long("The chainmail looks old and rusty, "+
           "and smells like an ironworks.\n");
  set_type("armour");
  set_armour_material("iron");
  set_value(100);
  set_weight(4);
  set_ac(2);
}

status get() { return 1; }

status id(string str) { return ::id(str) || str == type; }


/* support parse_command */
string *parse_command_id_list() {
	return ::parse_command_id_list() + ({ type });
}

string query_object_type() { return "Armour"; }

status drop(status silently) {  
  if(worn) {  
    if(!silently && worn_by) 
      tell_object(worn_by, "You drop your worn armour.\n");  
    worn = 0;  
    if(worn_by) worn_by->recalc_ac();  
    worn_by = 0;
  }
  return 0;  
}  

  
string short(status wiz) {  
  string str;

  if(worn && environment() != worn_by) {  /* failsafe */
    worn = 0;
    if(worn_by) worn_by->recalc_ac();
    worn_by = 0;
  }
  if(!(str = ::short(wiz))) return 0;
  if(wiz) str += "\("+current_strength+"/"+max_strength+"\)";
  if(worn) str += " (worn)";
  return str;  
}  


void long(status wiz) {
  string str;

  ::long(wiz);
  ::extra_long(wiz);
  if(!type) type = "armour";
  str = "";  
  if(wiz) str += "Armour stats: "+current_strength+"/"+max_strength+".\n";  
  str += "The "+type;  
  str += (extract(type,strlen(type)-1)=="s")  
      ? " are "  
      : " is ";
  str += (current_strength > max_strength/2)  
      ? "in superb condition.\n"  
      : (current_strength > max_strength/3)  
      ? "in fine condition.\n"  
      : (current_strength > max_strength/4)  
      ? "in average condition.\n"  
      : (current_strength > max_strength/5)  
      ? "showing wear and tear.\n"
      : (current_strength > max_strength/6)  
      ? "quite beaten and dented.\n"  
      : "falling apart!\n";  
  write(str);
}  

  
void init () {  
   ::init();
   if(!max_strength) calc_strength();
   if(!query_plural()) set_plural(query_name()+"s");
   if(environment(this_object()) != this_player()) return;
   add_action ("wear", "wear");  
   add_action ("remove", "remove");  
}  

/**************************************************************************/
/**************************************************************************/
/* actions */

status wear(string str) {  
  object ob, env;  
  object alt;
  int i;

  env = environment();
  if(!str) {
    notify_fail("wear what?\n");
    return 0;
  }
  if(!(ob = present(str, this_player()))) {
    notify_fail("You don't have a "+ str +".\n");
    return 0;
  }
  if(ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0; 
  }
  if(worn) {  
    tell_object(env,"You already wear it!\n");  
    return 1;  
  }  
  if(GUILD_OB) {
    for(i = 1; (alt = present(GUILD_OB+" "+i, this_player())); i++) {
      if(alt->wear_func(ob)) return 1;
    }
  }
  if(ALT) {
    for(i = 1; (alt = present(ALT+" "+i, this_player())); i++) {
      if(alt->remove_func(ob)) return 1;
    }
  }
  if(!env->query_npc() && !CLASS_ALLOWED_ARMOUR(env)) return 1; 
  if(env->query_armour_type(type)) {
    tell_object(env,"You already wear ");
    if(type == "armour") 
      tell_object(env,"Armour.\n");
    else if(type == "amulet")
      tell_object(env,"an Amulet\n");
    else
      tell_object(env,"a "+capitalize(type)+".\n");
    return 1;
  }
  if((env->two_weapons_wielded() && type == "shield") ||
      (env->query_right_weapon() &&
      (string)(env->query_right_weapon())->query_type() == "missile" &&
       type == "shield")) {
    tell_object(env,"You cannot wear a shield while wielding such weapons.\n");
    return 1;
  }
  worn = 1;
  worn_by = env;
  worn_by->recalc_ac();
  write("You wear "+ query_name() +".\n");
  say(env->query_name() +" wears "+ query_name() +".\n");
  return 1;  
}  
  

status remove(string str) {  
  object ob, env;  
  object alt;
  int i;

  env = environment();
  if(!str) {
    notify_fail("remove what?\n");
    return 0;
  }
  if(!(ob = present(str, this_player()))) {
    notify_fail("You don't have a "+ str +".\n");
    return 0;
  }
  if(ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0; 
  }
  if(!worn) {  
    tell_object(env,"You are not wearing it!\n");  
    return 1;  
  }  
  if(ALT) {
    for(i = 1; (alt = present(ALT+" "+i, this_player())); i++) {
      if(alt->remove_func(ob)) return 1;
    }
  }
  if(GUILD_OB) {
    for(i = 1; (alt = present(GUILD_OB+" "+i, this_player())); i++) {
      if(alt->remove_func(ob)) return 1;
    }
  }
  worn = 0;
  worn_by = 0;
  env->recalc_ac();  
  tell_object(env,"You remove "+ (string)this_object()->short()+"\n");
  say(env->query_name() +" removes "+(string)this_object()->short()+"\n");
  return 1;  
}   


/***************************************************************************/
/***************************************************************************/
/* hit armour */


/* hit armor */
 
void hit_armour(int damage){  
  object env;

  damage = damage - absorb_dam;  
  if(damage < 0) return;  
  current_strength -= damage;  
  if(!(env = environment())) return;
  
  if(current_strength < (max_strength/STR_MOD)){  
    if(armour_class > 1) { 
      armour_class--;
      env->recalc_ac();
    }
    if(weight > 1){  
      weight--;  
      env->recalc_carry();  
    }  
  }  

  if(current_strength <= 0){  
    tell_object(environment(), "Your "+ type +" falls to pieces!\n");  
    if(environment(env)) {
      tell_room(environment(env), 
        env->query_name()+"'s "+ type +" falls to pieces!\n");  
    this_object()->drop(1);   /* silently...shhhhhh!  */  
    destruct(this_object());  
    }
  }  
}

/* end hit armour */
/***************************************************************************/
/***************************************************************************/
/* armour strength */

  
void calc_strength() {
  mixed *armour_strength;  
  mixed *absorb_rate;
  mixed *absorb_material;
  int i, tmp_ac, tmp_wt;  

  armour_strength = ({
      ({  500,  550,  600,  650,  700,  750,  800,  850, }),
      ({  600,  650,  700,  750,  800,  850,  900,  950, }),
      ({  700,  775,  850,  925, 1000, 1025, 1150, 1225, }),
      ({  850,  950, 1050, 1150, 1250, 1350, 1450, 1550, }),
      ({ 1000, 1250, 1500, 1750, 2000, 2250, 2500, 2750, }),
      ({ 1100, 1350, 1600, 1850, 2100, 2350, 2600, 2850, }),
                    });  
 
  tmp_ac = (!armour_class) 
         ? 1  
         : (armour_class < 0)
         ? armour_class * -1  
         : (armour_class > 6) 
         ? 6  
         : armour_class;  
  
  tmp_wt = (!weight)
         ? 2  
         : (weight < 0)
         ? weight * -1
         : (weight > 8)
         ? 8
         : weight;  
  
  max_strength = armour_strength[tmp_ac-1][tmp_wt-1];  
  max_strength = max_strength * 2 / 3;
  
  absorb_rate = ({ 
    ({"armour","shield","helm","ring","cloak","boots","gloves","amulet",}),
    ({      10,       6,     5,     4,      4,      2,       2,       2,}),
                });

  if((i = member_array(type, absorb_rate[0])) > -1) {
    absorb_dam = absorb_rate[1][i];
  }
  else {
    absorb_dam = 10;
  }
  
  absorb_material = ({  
      "bone",          -50,  
      "ivory",         -50,  
      "ceramic",       -75,  
      "cloth",         -45,  
      "crystal",       -75,  
      "glass",        -100,  
      "leather",       -20,  
      "metal",           0,  
      "mithral",       100,  
      "meteorite iron", 75,  
      "iron",           20,  
      "adamantite",    150,  
      "bronze",        -10,  
      "silver",        -20,  
      "gold",          -30,  
      "platinum",      -40,  
      "steel",          30,  
    });  

  if(!armour_mat) armour_mat = "metal";
  if((i = member_array(armour_mat,absorb_material)) > -1) {
    max_strength = max_strength + absorb_material[i+1];
  }
  if(!current_strength) {   
    current_strength = max_strength;  
  }
}  


int repair_armour(int i){  
  if(i <= 0 || repair > MAX_REPAIR) return 0; /* failure */  
  current_strength += i;  
  repair += 1;  
  if(current_strength > max_strength) current_strength = max_strength;  
  return current_strength;  
}  


/****************************************************************************/  
/* sets */

string set_type(string s)    { return type = s; }  

int set_ac(int ac) {  
  if(type == "armour") {  
    if(ac > 4) enchanted = 1;  
  }  
  else if(ac > 1) {  
    enchanted = 1;
  }  
  return armour_class = ac;  
}  
  
int set_current_strength(int i){  
  return current_strength = (i > max_strength) ? max_strength : i;
}  

int set_max_strength(int i) { return max_strength = i; }

int set_repair(int i) { return repair = i; } 
 
string set_armour_material(string a) {
  armour_mat = (a) ? a : "metal";  
  calc_strength();
  return armour_mat;  
}  

status set_worn(status i) { 
  worn = (i) ? 1 : 0;
  if(worn_by) worn_by->recalc_ac();
  if(!worn) worn_by = 0;
  return worn;
}

object set_worn_by(object ob) {
  if(ob && living(ob)) {
    worn_by = ob;
    worn = 1;
    worn_by->recalc_ac();
  }
  else {
    worn = 0;
  }
  if(worn_by) worn_by->recalc_ac();
  if(!worn) worn_by = 0;
  return worn_by;
}    

void set_arm_light(int i) {  adj_light(i); }

/*************************************************************************/
/*************************************************************************/    
/***   Query_*** functions for external objects to access   ***/  
/***   information on the armour.                           ***/  
  
int armour_class()          { return armour_class; }
int query_ac ()             { return armour_class; }  
status query_worn ()        { return worn; }  
object query_worn_by()      { return worn_by; }

string query_type ()           { return type; }  
string query_armour_material() { return armour_mat; }  

int query_current_strength(){ return current_strength; }  
int query_armour_strength() { return max_strength; }  
int query_max_strength()    { return max_strength; }  
  

int query_compexity() { return ARM_COMPLEXITY; } 
int query_complex()   { return ARM_COMPLEXITY; } 
int query_repair()    { return repair; }  
  
int query_max_value() { return value; }  

int query_value () {   
  return (max_strength < current_strength * 2)
       ? (value * current_strength)/max_strength
       : value/2;
}  
  
status query_sell_destruct () {  
  if(type == "armour" && armour_class > 4) return 1;  
  if (type != "armour" && armour_class > 1) return 1;  
  return ::query_sell_destruct();  
}  
  
mapping query_specs() {
  return ([
	"type" 			: type,
	"ac" 			: armour_class,
	"current_strength" 	: current_strength,
	"max_strength" 	: max_strength,
	"repair" 		: repair,
	"armour_material" 	: armour_mat,
  ]);
}
  

void load_armour(mixed *arg) {
    int i, size;
    mixed t;

    for(i=0; i < sizeof(arg); i += 2) {
      t = arg[i+1];
      switch(arg[i]) {
        case "id":              set_id(t);              break;
        case "name":            set_name(t);            break;
        case "short":           set_short(t);           break;
        case "value":           set_value(t);           break;
        case "weight":          set_weight(t);          break;
        case "ac":              set_ac(t);              break;
        case "alias":           set_alias(t);           break;
        case "long":            set_long(t);            break;
        case "type":            set_type(t);            break;
        case "info":            set_info(t);            break;
        case "quest_item":      set_quest_item(t);      break;
        case "enchanted":       set_enchanted(t);       break;
        case "armour_material": set_armour_material(t); break;
        case "sell_destruct":   set_sell_destruct(t);   break;
        case "arm_light":       set_arm_light(t);       break;
      }
    }
}


string query_objective() { return "it"; }
