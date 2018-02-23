/* stoneskin */

#define NAME  "@@query_name:$this_player()$@@"

status stoneskin(string targ, mixed alt_type, string class) {
  int level, i;
  string file;

  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("stoneskin")) {
      notify_fail("You have not yet learned the 'stoneskin' psionic power.\n");
      return 0;
    }
  }



  if(!alt_type) alt_type = "psychometabolic";
  if(!class) class = "psionicist";
  return "/bin/skills/classes/mage/stoneskin"->stoneskin(targ, alt_type, class);
}
