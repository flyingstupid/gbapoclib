/* teleport, teleport other */


status warp(string str, mixed alt_type, string class) {
  int level, i;
  string file, *destinations, dom1, dom2, tmp, who;
  string spell_name;
  int spell_level;
  status party;
  object tel;


  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("warp")) {
      notify_fail("You have not yet learned the 'warp' "+
        "psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "psychoportive";
  if(!class) class = "psionicist";
  return "/bin/skills/classes/mage/warp"->warp(str,alt_type,class);
}
