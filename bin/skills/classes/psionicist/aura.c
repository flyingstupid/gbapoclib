#include "path.h"

status aura(string str, mixed alt_type, string class) {
  string targ, spell_name;
  object ob;

  if(!str) {
    notify_fail("Aura sight?\n");
    return 0;
  }

  sscanf(str, "%s %s", spell_name, targ);

  if(!targ) {
    notify_fail("Aura sight who?\n");
    return 0;
  }    

  
  if(!alt_type) { 
    if(!this_player()->query_psi_skills(spell_name)) {
      notify_fail("You have not yet learned the 'aura sight'"+
                  " psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "clairsentient";
  if(!class)    class    = "psionicist";

  ob = present(targ, environment(this_player()));

  if(!ob) {
    notify_fail("There is no "+ capitalize(targ) +" here.\n");
    return 0;
  }

  if(!living(ob)) {
    notify_fail(capitalize(targ) +" isn't living and so has no aura.\n");
    return 0;
  }


  return MAGE+"identify"->identify(targ, alt_type, class);
}

