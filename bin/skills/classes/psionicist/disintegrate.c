#include "path.h"


status disintegrate(string str, mixed alt_type, string class) {
  string targ, spellname;

  if(!str) {
    notify_fail("Disintegrate what?\n");
    return 0;
  }


  
  if(!alt_type) { 
    if(!this_player()->query_psi_skills("disintegrate")) {
      notify_fail("You have not yet learned the 'Disintegrate'"+
                  " psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "psychokinetic";
  if(!class)    class    = "psionicist";

  return MAGE+"disintegrate"->disintegrate(str, alt_type, class);
}



