/* teleport */

status teleport(string str, mixed alt_type, string class) { 

  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("teleport")) {
      notify_fail("You have not yet learned that psionic power.\n");
      return 0;
    }
  }

  if(!alt_type) alt_type = "telepathic"; 
  if(!class)    class    = "psionicist";       

  return "/bin/skills/classes/mage/teleport" -> teleport(
	 str, alt_type, class);
}


