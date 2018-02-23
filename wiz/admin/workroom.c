#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
    if (arg) return;

    set_short("a standard workroom");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits(({
	CHURCH, "square",
	INNER,  "inner",
	POST_OFFICE,   "post",
      }));
}
