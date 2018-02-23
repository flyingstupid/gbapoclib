#include <mudlib.h>
#include <player.cfg>

#define TP this_player()

status pong() {
  string who;
  int i;
  object pinger;

  pinger = TP->query_pinger();
	
  if (pinger) who = (string)pinger->query_name(1);
  if (!(pinger && who)) {
    TP->set_pinger(0);
    write("No one has pinged you.\n");
    return 1;
  }
  tell_object(pinger, (string)TP->query_name() + " pongs back.\n");
  for(i = 3; i--; ) {
    tell_object(pinger, sprintf("%c",7));
  }
  TP->set_pinger(0);
  write("You pong back to " + capitalize(who) + ".\n");
  return 1;
}
