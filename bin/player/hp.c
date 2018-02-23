#include <mudlib.h>

#define TP this_player()

status hp(string str) {
  if(str) return 0;
  TP->set_hp_displ(!TP->query_hp_displ());
  write("Hit point display " + ( TP->query_hp_displ() ? "on" : "off" ) +".\n");
  return 1;
}
