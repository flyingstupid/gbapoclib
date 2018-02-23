#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    reset_doors(arg);

   load_door(({
	"file", "d/affils/rooms/taalandrix",
	"long",
		"A fine door of sturdy red wood.\n"+
		"It bears the symbol of the kitten paw above the peep hole.\n",
	"direction", "temple door",
   }));

    if (arg) return;
    set_short(
      "West Road");
    set_long(
"You have wandered onto West Road. To the north the city wall  \n"+
"abruptly turns east. You are up on a small hill and notice    \n"+
"that you are almost at the corner of the city. There is a lamp\n"+
"post here with a small lamp hanging from it beside a small and.\n"+
"odd looking temple to the east.\n");

    set_weather(2, 4, 0);
    set_night_desc(
      "The city lights shine brightly through the blackness.\n");
    set_night_items
    (({
      "city lights#lights",
        "The city lights are very bright.",
    }));
    set_items
    (({
      "West Road",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "city wall#wall",
        "The city wall has many vines and cracks on it.",
      "city",
        "The city is very large and beautiful.",
      "hill",
        "The hill is made of dirt.",
    }));
    set_exits
    (({
      "/d/coronos/w/vorax/west6.c", "north",
      "/d/coronos/w/vorax/west4.c", "south",
    }));
  }
  
        
