#include "path.h"

#define  NAME       "@@query_name:$this_player()$@@"
#define  SPELLNAME  (string)caster->query_spell_name()
#define  SPELLDMG   (int)caster->query_spell_dmg()  

status create(string str, mixed alt_type, string class) {
  string targ, spell_name, file;
  int cost, level, i;

  if(!str) {
    notify_fail("Create sound?\n");
    return 0;
  }

  sscanf(str, "%s %s", spell_name, targ);

  if(!targ) {
    notify_fail("Create sound what?\n");
    return 0;
  }

  if(!alt_type) alt_type = "psychokinetic";
  if(!class)    class    = "psionicist";

  return MAGE+"ventriloquism" -> ventriloquism(targ, alt_type, class);
}


