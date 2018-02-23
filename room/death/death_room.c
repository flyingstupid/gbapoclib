#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
  set_short("death room");
  set_long(
    "A dark room lit with a dark light that seems to defy the darkness \n"+
    "not so much by actually illuminating the room as by being a dark  \n"+
    "point in less dark surroundings. In the strange light (dark?) you \n"+
    "can see a centrally placed desk covered with books and diagrams.  \n"+
    "The walls are covered with bookshelves filled with dark tomes bound\n"+
    "in leather that gleam with strange runes.\n");
  set_weather(5, 1, 0);
}
