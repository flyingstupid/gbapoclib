/* Scry */

status scry(string str, mixed alt_type, string class) {
  int level;

  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("scry")) {
      notify_fail("You have not yet learned the 'scry' psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "clairsentience";;
  if(!class) class = "psionicist";
  return "/bin/skills/classes/mage/scry"->scry(str, alt_type, class);
}
