#include <mudlib.h>
#include <player.cfg>

#define TP this_player()

status ping(string who) {
  object ob;

#ifndef PING_PONG
  return 0;
#endif /* PING_PING */

  if (!who) {
    write("Ping whom?\n");
    return 1;
  }
  ob = find_living(who);
  if (!ob) {
    write("No player with that name.\n");
    return 1;
  }
  if(ob->query_invis() && (int)TP->query_security_level()
    < (int)ob->query_security_level()) {
      write("Can't ping "+ capitalize(who) +".\n");
      return 1;
  }
  if (!(ob->catch_ping())) {
    write("Can't ping "+ capitalize(who) +".\n");
    return 1;
  }
  write("You ping "+ capitalize(who) +".\n");
  return 1;
}
