#include <mudlib.h>

#define TP this_player()

status oc() {

  if(query_verb() != "-ooc") return 0;

  if(TP->query_ghost()) {
    write("You can't do that just yet...\n");
    return 1;
  }

  if(TP->query_attack()) {
    write("You can't remove your VR goggles while in combat!\n");
    return 1;
  }

  if(environment(TP)->query_ooc_room()) {
    write("You are already out of character.\n");
    return 1;
  }
  write("You remove your VR goggles, and your virtual world disolves...\n");
  say(TP->query_name()+" removes "+TP->query_possessive()+" VR goggles and "+
  "vanishes from sight...\n");
  TP->set_ooc_enter_room(file_name(environment(TP)));
  TP->move_player("X#"+OOC_ENTER);
  say(TP->query_name()+" removes "+TP->query_possessive()+" VR goggles.\n");
  return 1;
}
