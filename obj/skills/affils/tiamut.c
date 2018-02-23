#include <mudlib.h>
#define FILE		(string)this_object()->query_affiliation_file()

inherit AFFILIATION_OB;
inherit CLOTHING;


static int wc_bonus;
int right_weapon_class_bonus() {
  return (environment()->query_class("cleric")) ? 0 : wc_bonus; 
}

int query_extra_spell_dmg(int damage, string school) {
  string al_title, tmp;
  string tmp1, tmp2;
  int dam;

  if(!school) {
    return 1;
  }

  al_title = (string)this_player()->query_al_title();
  if(!al_title) return 1;
  if(!sscanf(al_title, "(%s)", tmp1)) {
    return 1;
  }


  if(!damage) return 1;
  al_title = tmp1;

  switch(al_title) {
    case "Lawful Good" : case "Lawful Neutral" : case "Neutral Good":
    tmp = "good";
    break;
    
    case "True Neutral" : case "Chaotic Neutral" :
    tmp = "neutral";
    break;

    default :
    tmp = "evil";
    break;
  }

  if(FILE == "tiamut" && tmp != "evil") return 0;


  if(!stringp(school)) return 1;
  switch(school) {

    case "combat_sphere":
      dam = 3;
      break;

 
  }

  
  if(dam == 1) 
    return 0;
  else if(dam == -2)
    return -damage/2; /* ie spell does half damage */
  else if(damage == -3)
    return -damage*2/3;
  else if(dam == 2)
    return damage/2;  /* +half damage */
  else if(dam == 3) 
    return damage;    /* total x2 damage */
  else return 0;
}

void reset(status arg) {

  set_name("symbol");
  set_long(
	"The unholy symbol is forged from black steel and bears the \n"+
	"the likeness of the five headed dragon; Tiamut, the Queen of "+
	"Darkness.\n");

  set_short("A unholy symbol");
}

status id(string str) {
  return ::id(str) ||
    str == "external" ||
    str == "symbol" || 
    str == "holy symbol" ||
    str == "unholy symbol";
}

void init() {
  clothing::init();
  affils::init();
  ::init();
}


status wield_func(object weapon, status tmp_left) {
  object env, r_weapon;
  string type;
  string *w_names;

  env = environment();

  wc_bonus = 0;
  type     = (string)weapon->query_type();

  w_names = ({
        "longsword", "broadsword", "shortsword", "lance", 
  });


  if(env->query_class("cleric")) {
    if(member_array((string)weapon->query_name(), w_names) == -1 &&
      type != "crush") {
      write("Tiamut would not approve of such a weapon.\n");
      return 1;
    }
    wc_bonus += 2;
  }

  if(!weapon->query_wc() > 15 && (int)env->query_strength() < 10) { 
    tell_object(env,"You lack the strength to use that weapon effectively.\n");  
    return 1; 
  }

  if(env->query_armour_type("shield") && tmp_left) {
    tell_object(env,"You cannot wield a left weapon when using a shield.\n");
    return 1;
  }



  if(r_weapon = (object)env->query_right_weapon())
      r_weapon->dewield();

  weapon->set_right_wielded(env);
  env->set_right_weapon(weapon);
  write("You wield the "+weapon->query_name()+" in your right hand.\n");
  return 1;
}
