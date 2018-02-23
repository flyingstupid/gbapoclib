/* Contagion 
 * H7 Mudlib, '96
 */

status contagion(mixed targ, mixed alt_type, string class) {
  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("contagion")) {
      notify_fail("You have not yet learned the 'contagion' psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "psychometabolic";
  if(!class) class = "psionicist";
  return (status)"/bin/skills/classes/cleric/cause"->cause("disease "+targ,
		alt_type, class);
}

