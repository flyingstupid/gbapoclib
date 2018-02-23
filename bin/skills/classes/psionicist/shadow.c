#include "path.h"

#define  NAME       "@@query_name:$this_player()$@@"
#define  SPELLNAME  (string)caster->query_spell_name()
#define  SPELLDMG   (int)caster->query_spell_dmg()  

status shadow(string str, mixed alt_type, string class) {
  string targ, spell_name, file;
  int cost, level, i;

  if(!str) {
    notify_fail("Shadow form?\n");
    return 0;
  }

  if(!alt_type) alt_type = "psychometabolic";
  if(!class)    class    = "psionicist";

  return MAGE+"wraith" -> wraith(str, alt_type, class);
}

