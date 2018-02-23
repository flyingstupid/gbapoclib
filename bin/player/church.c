#include <mudlib.h>
#include <player.cfg>

#define TP this_player()

status church() {
  if(TP->query_level() > 1) return 0;
  TP->move_player("X#"+ DEFAULT_ENTER);
  return 1;
}
