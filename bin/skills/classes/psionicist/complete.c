#include "path.h"

#define  NAME       "@@query_name:$this_player()$@@"
#define  SPELLNAME  (string)caster->query_spell_name()
#define  SPELLDMG   (int)caster->query_spell_dmg()  

status complete(string str, mixed alt_type, string class) {
  string targ, spell_name, file;
  int cost, level, i;

  if(!str) {
    notify_fail("Complete healing?\n");
    return 0;
  }


  targ = TP->query_name();

  if(!alt_type) alt_type = "psychometabolic";
  if(!class)    class    = "psionicist";

  return CLERIC+"heal" -> heal(targ, alt_type, class);
}
