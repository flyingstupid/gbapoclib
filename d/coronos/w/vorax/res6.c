#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    if (arg) return;
    set_short(
      "Residential Road");
    set_long(
      "You are standing on a stretch of Residential Road. To the\n"+
      "north you can hear a lot of noise. You can smell dust\n"+
      "coming from somewhere to the south. There is a lamp post\n"+
      "here with a small lamp hanging from it.\n");
    set_weather(2, 4, 0);
	set_land_value(200000);
    set_day_desc(
      "The sun is very bright in this area of the city.\n");
    set_day_items
    (({
      "sun",
        "You can't look at the sun.",
    }));
    set_night_desc(
      "The moon shines down on the street.\n");
    set_night_items
    (({
      "moon",
        "The moon is full and round in the sky.",
    }));
    set_items
    (({
      "Residential Road",
        "Just look around you, you're standing on it.",
      "small dirt path",
        "The small dirt path is to the south.",
      "lamp post",
        "This is a lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/res5.c", "south",
      "/d/coronos/w/vorax/west12.c", "north",
    }));
  }
  
