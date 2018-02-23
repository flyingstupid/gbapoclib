#include <mudlib.h>
#define FILE		(string)this_object()->query_affiliation_file()

inherit AFFILIATION_OB;


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

  if(tmp == "evil" && FILE != "brm") return 0;
  else if(tmp == "good"    && FILE != "wrm") return 0;
  else if(tmp == "neutral" && FILE != "grm") return 0;


  if(!stringp(school)) return 1;
  switch(school) {
    case "alteration" :
      if(tmp == "neutral") dam = 3;
      else dam = -2;
      break;

    case "necromancy":
      if(tmp == "evil") dam = 3;
      else dam = -2;
      break;
 
    case "abjuration" :
      if(tmp == "good") dam = 3;
      else dam = -2;
      break;

    case "illusion" :
      if(tmp == "neutral" || tmp == "evil") dam = 2;
      else dam = -3;
      break;

    case "evocation" :
      if(tmp == "good" || tmp == "neutral") dam = 2;
      else dam = -3;
      break;

    case "charm" :
      if(tmp == "good" || tmp == "evil") dam = 2;
      else dam = -3;

    default :
      dam = 1; /* conj, divination */
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
