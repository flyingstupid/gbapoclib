#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    int i;
    object ob;

    if(!present("rat")) {
      ob = clone_object("d/coronos/w/angel/city/monst/rat");
      move_object(ob, this_object());
    }

    if(!present("apprentice")) {
      ob = clone_object("d/coronos/w/angel/city/monst/apprentice");
      ob -> load_chat(12, ({ "Apprentice says: Here, mousey-mousey-mousey.\n",
	"Apprentice motions to a nearby rat.\n",
	"Apprentice exclaims: Damned find familar spell.\n",
	"Apprentice asks: Do you know how this spell goes?\n",
	"Apprentice ponders as to whether some cheese would work better.\n",
	"Apprentice fidgets.\n",
      }));
      move_object(ob, this_object());
    }

    if (arg) return;
    set_short(
      "The intersection of Wall Street and Slate Road");
    set_long(
      "You are at the intersection of Wall Street and Slate Road.\n"+
      "You can see the city wall to the north. The church on\n"+
      "Slate Road is visible from here. There is a lamp post\n"+
      "here with a small lamp hanging from it.\n");
    set_weather(2, 4, 0);
    set_items
    (({
      "intersection",
        "Just look around you, you're standing at it.",
      "Wall Street",
        "West Road continues to the east and west.",
      "Slate Road",
        "Slate Road veers off to the southwest.",
      "lamp post",
        "This is a normal lamp post with a lamp hanging from it.",
      "lamp",
        "This lamp is here to light the streets.",
      "street sign",
        "The street sign says:\n"
        "Southwest: Slate Road\n"
        "West: Wall Street\n"
        "East: Intersection of Wall Street and Residential Road\n",
      "sign",
        "The street sign says:\n"
        "Southwest: Slate Road\n"
        "West: Wall Street\n"
        "East: Intersection of Wall Street and Residential Road\n",
      "church",
        "The church's steepal is visible above the horizon.",
      "city wall#wall",
        "The city wall is lined with vines and cracks.",
    }));
    set_sign_message(
      "The street sign says:\n"
      "Southwest: Slate Road\n"
      "West: Wall Street\n"
      "East: Intersection of Wall Street and Residential Road\n");
    set_exits
    (({
      "/d/coronos/w/vorax/west12.c", "east",
      "/d/coronos/w/vorax/west10.c", "west",
      "/d/coronos/w/vorax/slate3.c", "southwest",
    }));
  }
  
