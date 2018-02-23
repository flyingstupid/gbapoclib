#include <mudlib.h>

#define TP this_player()

status ansi(string arg){  
  int ansi_on;

  if(!arg) {
    notify_fail("Usage: ansi <on|off>\n");
    return 0;
  }

  if(arg == "on") {
    write("Ansi graphics will not be filtered.\n");
    TP->set_ansi(1);
    return 1;
  }
  if(arg == "off") {
    write("Ansi graphics will be filtered.\n");
    TP->set_ansi(0);
    return 1;
  }
  notify_fail("Usage: ansi <on|off>\n");
  return 0;
}  
