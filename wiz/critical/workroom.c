#include <mudlib.h>
inherit ROOM;


void reset(status arg) {
  if (arg) return;

  set_short("Critical's Workroom");
  set_long ("[Critical's Workroom]\n"+
            "This room is covered floor to ceiling in computers and servers\n" +
            "along with other pieces of esortic origins. A huge treasure chest\n"+
            "sits to one side of the room and an ornate rack of weapons lines \n"+
            "the opposing wall. There is also a repairing bench installed here\n");
  set_weather(5, 5, 5);
  set_exits(({
        "/d/wastelands/w/critical/secondtry/city2", "town",
        INNER,  "inner",
        POST_OFFICE,   "post",
  }));
}
