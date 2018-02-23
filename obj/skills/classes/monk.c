/***************************************************************************/

/* Monk Class Object. v1.01 
 * Angel, August 1996 for Heaven7 development
 */


/***************************************************************************/
/* defines */

#include <tell.h>
#define MONK_ALIGNMENT1	 300
#define MONK_ALIGNMENT2	-300

#define THIS_PLAYER_WIZ    ((this_player()->query_security_level()) ? 1 : 0)
#define ALIGNMENT          (int)this_player()->query_alignment()



/*********************************************************************/
/* queries */
string query_name()        { return "ranger_guild_object"; }
string query_object_type() { return "guild_object";         }
status query_auto_load()   { return 1; }



status check_alignment() {
  if(ALIGNMENT < MONK_ALIGNMENT1 && 
     ALIGNMENT > MONK_ALIGNMENT2) return 1;
  return 0;
}



string extra_look(status wiz) {
  if(this_player() != environment()) 
    return (string)environment()->query_name()+" is a Monk";
  else {
    if(environment()->query_class("psi"))
      return "You are a Monk, of the brotherhood of the Mind";
    else if(environment()->query_class("monk"))
      return "You are a Monk, of the brotherhood of the Hand";
    else if(environment()->query_class("kensai"))
      return "You are a Monk, of the brotherhood of the Sword";
  }
}

void init_arg() {
  call_out("monk_bonuses", 2);
}

void monk_bonuses() {
  if(environment()) {
/*
    clone_object("obj/shadows/monk")->monk_aura(environment());
*/
  }
  environment()->add_spell_immunity("mind blank");
}

void guild_death() {
}

status id(string str) {
  return str == "monk"      ||
         str == "psi"       ||
         str == "psionicist" ||
         str == "guild_object";
}

status drop(string quit) { return 1; }
status get(string quit)  { return 1; }

void init() {
  if(present("guild_object 2", environment()))
    destruct(this_object());
}
