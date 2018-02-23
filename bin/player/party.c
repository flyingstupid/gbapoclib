#include <mudlib.h>
#include <player.cfg>

#define TP this_player()

status party(string str) {
  object obj;
  string party;

#ifndef PARTY_DAEMON
  return 0;
#endif

  if(!str) {
    write("Usage: party <party name>\n");
    return 1;
  }

  party = TP->query_party();

  if(party) {
    write("You already belong to a party!\n");
    return 1;
  }
  if(call_other(PARTY_DAEMON, "query_party", str)) {
    write("There is already a party called '"+str+"'.\n");
    return 1;
  }
  if(party) {
    write("You already belong to the '"+party+"' party.\n");
    return 1;
  }
  if(str == "ooc") {
    write("You can't name a party after that channel.\n");
    return 1;
  }
  party = str;
  obj = clone_object(PARTY_OBJECT);
  obj -> set_party(str);
  obj -> set_founder(TP->query_name(1));
  obj -> set_birth((string)environment(TP)->query_time());
  obj -> set_leader(TP->query_name(1));
  move_object(obj, TP);
  write("You now lead the '"+str+"' party!\n");
  TP->set_party(party);
  return 1;
}
