#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Main Street");
    set_long(
      "You have found your way to Main Street. There is a lot of\n"+
      "dust in the air to the west. You can see many houses lining\n"+
      "a street to the east. There is a lamp post here with a\n"+
      "small lamp hanging from it.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "Main Street",
        "Just look around you, you're standing on it.",
      "West Road",
        "You can see West Road in the distance.",
      "Residential Road",
        "Residential Road is to the north east of here.",
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
      "dust",
        "This is just plain old dust",
      "houses",
        "The houses line Residential Road.",
    }));
    set_exits
      (({
        "/d/coronos/w/vorax/res1.c", "east",
        "/d/coronos/w/vorax/main2.c", "west",
      }));
    }
    
