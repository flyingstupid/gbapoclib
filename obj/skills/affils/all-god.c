#include <mudlib.h>
#define FILE		(string)this_object()->query_affiliation_file()

inherit AFFILIATION_OB;
inherit CLOTHING;


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

void reset(status arg) {

  set_name("symbol");
  set_long(
	"The holy symbol is made from platinum and steel, as is the \n"+
	"custom. The medalion is circular, with a crucifix in the \n"+
	"centre, encircled by two dragons in a figure eight.\n");

  set_short("A holy symbol");
}

status id(string str) {
  return ::id(str) ||
    str == "external" ||
    str == "symbol" || 
    str == "holy symbol";
}

void init() {
  clothing::init();
  affils::init();
  ::init();
}
