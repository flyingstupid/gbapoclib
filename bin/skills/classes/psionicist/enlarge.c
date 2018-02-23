/* enlarge */

inherit "inherit/timer";

int carry_bonus, wc_bonus;

status enlarge(mixed targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("enlarge")) {
      notify_fail("You have not yet learned the 'enlarge' psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "psychometabolic";
  if(!class) class = "psionicist";
  return "/bin/skills/class/mage/enlarge"->enlarge(targ, alt_type, class);
}
