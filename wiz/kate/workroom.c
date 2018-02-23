//
// wiz/kate/workroom.c
//

#include <mudlib.h>
inherit ROOM;


void reset(status arg) {
  if (arg) return;

  set_short("Kate's Workroom");
    set_long ("The little room is painted sage green and has soft, indirect\n"
              "lighting.  A big cushy armchair sits in one corner with a small\n"
              "table just next to it.  There is a gleaming 17 inch silver\n"
              "laptop on the table beside a plate of freshly baked scones. \n"
              "A coffee pot putters away in the corner.\n");
  set_weather(3, 1, 0);
  set_exits(({
	"d/wastelands/w/critical/secondtry/city6", "workshoppe",
	"wiz/kate/open/kate_hall.c",  "hall",
      "wiz/kate/open/forest/forest_3.c", "forest"
  }));
}
