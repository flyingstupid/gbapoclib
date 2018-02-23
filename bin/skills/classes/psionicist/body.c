#include "path.h"

status body(string str, mixed alt_type, string class) {
  string targ, spell_name;
  int cl, cost, level;

  if(!str) {
    notify_fail("Body control?\n");
    return 0;
  }

  sscanf(str, "%s %s", spell_name, targ);

  if(!targ) {
    notify_fail("Body control who?\n");
    return 0;
  }

  if(!alt_type) { 
    if(!this_player()->query_psi_skills("body control")) {
      notify_fail("You have not yet learned the 'Body Control'"+
		" psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "psychokinetic";
  if(!class)    class    = "psionicist";

  return MAGE+"demand" -> demand(targ, alt_type, class);
}


