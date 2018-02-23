#include <mudlib.h>
inherit ROOM;
void reset(status arg) {
if(!present("rat")) {
  move_object(clone_object("/d/coronos/w/vorax/mon/rat"),this_object());
  {
    if (arg) return;
    set_short(
      "A dirty alley");
    set_long(
      "You are walking along in a long and dark alley. The alley\n"+
      "is very dusty. To the north, you see the alley makes an\n"+
      "abrupt turn to the east. There is lamp post here with a\n"+
      "small lamp hanging from it.\n");
    set_weather(1, 4, 0);
    set_day_desc(
      "Hardly any sunlight filters through to the alley floor.\n");
    set_night_desc(
      "Even the lamps have a hard time keeping the alley lit.\n");
    set_items
    (({
      "alley",
        "This is a very dark and dirty alley.",
      "lamp post",
        "This is a lamp post with a lamp hanging on it.",
      "lamp",
        "This lamp is burning to keep the street bright.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/alley4.c", "east",
      "/d/coronos/w/vorax/alley2.c", "south",
    }));
  }
}
}
