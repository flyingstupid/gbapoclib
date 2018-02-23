/** suggestion **/

#include <humanoid.h>

#define  NAME       "@@query_name:$this_player()$@@"
#define  TARGET_WIS (int)target->query_wisdom()
#define  CASTER_CHR (int)caster->query_charisma()

status suggest(string targ, mixed alt_type, string class) {
  int level, i;
  string cmd, file;

  if(!targ || sscanf(targ,"%s %s",targ,cmd) != 2) {
    notify_fail("suggest who what?\n");
    return 0;
  }

  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("suggest")) {
      notify_fail("You have not yet learned the 'strength' psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "telepathic";
  if(!class) class = "psionicist";
  return "/bin/skills/classes/mage/suggest"->suggest(targ, alt_type, class);
}
