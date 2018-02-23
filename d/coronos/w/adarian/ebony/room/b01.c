#include <mudlib.h>
#include <ansi.h>
#include "path.h"

inherit "inherit/room2";

void reset(status arg) {
  if(arg) return;

  set_short("South Bridge");
  set_long(MAGENTA_F+"\t--<South Bridge>--\n"+OFF+
"South entrance\n");
  set_weather(5, 4, 6);
  set_exits(({
    ROOMS "c01.c", "north",
    "players/adarian/workroom.c", "south",
  }));
}
