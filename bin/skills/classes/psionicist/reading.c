#include "path.h"

status reading(string str, mixed alt_type, string class) {
  string targ, spellname;
  object ob;

  if(!str) {
    notify_fail("Reading what?\n");
    return 0;
  }

  
  if(!alt_type) { 
    if(!this_player()->query_psi_skills("object reading")) {
      notify_fail("You have not yet learned the 'object reading'"+
                  " psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "clairsentient";
  if(!class)    class    = "psionicist";

  ob = present(str, environment(this_player()));
  if(!ob) ob = present(str, this_player());


  if(!ob) {
    notify_fail("There is no "+ capitalize(str) +" here.\n");
    return 0;
  }

  if(living(ob)) {
    notify_fail("You can only perform a reading on an inanimate object.\n");
    return 0;
  }

  return MAGE+"detect"->detect("magic "+str, alt_type, class);
}

