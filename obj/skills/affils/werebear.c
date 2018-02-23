#include <mudlib.h>
#include <linewrap.h>
#define FILE		(string)this_object()->query_affiliation_file()
#define WEREBEAR_SHADOW "obj/shadows/werebear"


inherit AFFILIATION_OB;


status wereform;
status initialised;

#ifdef SPELL_CASTING_CLAN
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

  if(FILE == "all-god" && tmp != "good") return 0;


  if(!stringp(school)) return 1;
  switch(school) {
    case "divination_sphere" :
      dam = 2;
      break;

    case "combat_sphere":
      dam = 2;
      break;

    case "necromancy_sphere":
      dam = 2;
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
  else if (dam == 3)
    return damage;    /* total x2 damage */
  else
    return 0;         /* total 0 extra dmg */
}
#endif /* SPELL_CASTING_CLAN */

void reset(status arg) {
  if(arg) return;
}



status id(string str) {
  return ::id(str) ||
    str == "werebear" ||
    str == "guild_object";
    str == "external";
}

void init() {
  affils::init();
  ::init();
  if(!initialised) init_arg();

}

status query_wereform()         { return wereform;     }
status set_wereform(status w) {
  if(w) {
    environment()->set_alias("bear");
    environment()->set_wimpy(0);
    this_object()->drop_equipment();
    environment()->set_attack_msg(
	({ "missed",         "", 
           "brushed",        "with a claw",  
           "grazed",         "with sharp teeth",  
           "gouged",         "with sharp claws",  
           "tackled",        "with a bear hug",  
           "pummled",        "with a vicious claw",  
           "clobbered",      "with a vicious claw to the head",  
        }));
  }
  else {
    environment()->set_alias(0);
    environment()->set_attack_msg(0);
  }
  return wereform = w;
}


void initialise_wereform() {
  object obj;
  tell_object(environment(), 
	"You feel the spirit of the beast within you.\n");

  obj = clone_object(WEREBEAR_SHADOW);
  obj -> shadow_werebear();
}

void init_arg(varargs arg) {
  initialised = 1;
  call_out("initialise_wereform", 2);
  ::init_arg(arg);
}

void drop_equipment() {
  int i;
  object *inv;

  inv = all_inventory(environment());
  for(i=0; i<sizeof(inv); i++) {
    if(inv[i]->query_wielded()) inv[i]->drop();
    if(inv[i]->query_worn()) {
      tell_object(environment(),
	"You burst out of your "+inv[i]->short()+"!\n");
      inv[i]->hit_armour(10);
      environment()->adj_hp(-(random(10)));
      inv[i]->drop();
    }
  }
}

status wear_func(object ob) {
  if(environment()->query_is_were()) {
    writelw("You fumble with the "+ob->short()+", but your paws "+
    "don't seem to be as good as hands.\n");
    return 1;
  }
  return 0;
}

status wield_func(object ob) {
  if(environment()->query_is_were()) {
    writelw("You fumble with "+ob->short()+", but your paws "+
    "don't seem to be as good as hands.\n");
    return 1;
  }
  return 0;
}
