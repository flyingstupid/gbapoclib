/* strength */

inherit "inherit/timer";

int carry_bonus;

status strength(mixed targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("strength")) {
      notify_fail("You have not yet learned the 'strength' psionic power.\n");
      return 0;
    }
  }



  if(!alt_type) alt_type = "psychometabolic";
  if(!class) class = "psionicist";
  
  return "/bin/skills/classes/mage/strength"->strength(targ,alt_type,class);
}
