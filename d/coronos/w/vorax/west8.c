#include <mudlib.h>
inherit ROOM;
object thorbest, ob;

void reset(status arg)
  {


    if (arg) return;
    set_short(
      "Western Wall Street");
    set_long(
      "You are on a stretch of Wall Street. The city wall is to\n"+
      "your north. To the west it makes a sharp turn southward.\n"+
      "You see a temple to the south of here with it's beautiful\n"+
      "stained glass. There is a lamp post here with a small lamp\n"+
      "hanging from it.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "Wall Street",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "city wall#wall",
        "The city wall has many vines and cracks on it.",
      "temple",
        "This is a small temple that is to the south.",
      "stained glass#glass",
        "The stained glass has a picture of the gods on it.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west7.c", "west",
      "/d/coronos/w/vorax/west9.c", "east",
      "/d/coronos/w/vorax/temple1.c", "south",
    }));
  }
  
