#include <mudlib.h>

#define TP this_player()

status news() {
  write("\tLogin News for "+MUD_NAME+"\n");
  TP->more("/data/news/NEWS");
  return 1;
}

