/* energy dran .. drakken */
 
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"
 
status energy(string target, mixed alt_type, string class) {
  int dam, i;
  string file;
 
  if(!target || !(target == "drain" || sscanf(target,"drain %s",target))) {
    notify_fail("energy drain?\n");
    return 0;
  }
  if(target == "drain") target = 0;

  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("energy drain")) {
      notify_fail("You have not yet learned that psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "psychometabolic";
  if(!class) class = "psionicist";

  return "/bin/skills/classes/mage/energy"->energy(target, alt_type, class);
}
