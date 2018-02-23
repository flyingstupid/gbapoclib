#include <mudlib.h>
inherit ROOM;

void reset(status arg)  {

  load_door(({
    "destination",      "d/coronos/w/darkness/barrack1",
    "direction",        "west door",
    "long",             "This is a wooden door made of oak.\n",
    "door id",          "barrack door",
    "closed", 
  }));

    if (arg) return;
    set_short(
      "Western Wall Street");
    set_long(
      "You have found your way to the corner of Wall Street and\n"+
      "West Road. To the west are the large barracks of the City\n"+
      "Guard.  The sounds of barking hounds echoes throughout the \n"+
      "city streets from the southwest, the alley leading in that \n"+
      "direction lit by lamp post and a small hanging lamp.\n");
    set_weather(2, 4, 0);
    set_night_desc(
      "  The lamp burns brightly, lighting the road.\n");         
    set_items
    (({
     "alley",
      "In the alley are several paw prints, most likely from large \n"+
      "war dogs that are trained by the guards that live in the barracks.",
      "West Road#west road",
        "West Road is directly to the south.",
      "corner",
        "This is the corner of the city.",
      "Wall Street",
        "Just look around you, you're standing on it.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "street sign",
        "The street sign says:\n"
	" Ille Coronos Guards Barracks\n"
	" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
        "East: Wall Street\n"
        "South: West Road\n",
      "sign",
        "The street sign says:\n"
        "East: Wall Street\n"
        "South: West Road\n",
      "city wall#wall",
        "Here two portions of the wall meet.",
      "sun",
        "You can't see it.",
    }));
    set_sign_message(
      "The street sign says:\n"
      " Ille Coronos Guards Barracks \n"+
      " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"+
      "East: Wall Street\n"
      "South: West Road\n");
    set_exits
    (({
      "/d/coronos/w/vorax/west8.c", "east",
      "d/coronos/w/angel/city/rooms/animal_trainer", "southwest",
      "/d/coronos/w/vorax/west6.c", "south",
    }));
  }

