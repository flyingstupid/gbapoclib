#include <mudlib.h>
#define MONST	"d/coronos/w/angel/city/monst/"
#define NAME (string)this_player()->query_name()
inherit ROOM;

void reset(status arg) {
    reset_doors(0);
    load_door(({
      "destination",     "d/coronos/w/darkness/wallst0",
      "direction",       "north gate",
      "closed",
      "description",
        "The gate is a beautifully crafted wrought iron gate.\n",
    }));

  if(!present("worm")) {
    move_object(clone_object(MONST+"worm"),this_object());
  }
  if(arg) return;

  set_short("the city garden");
  set_long(
     "A group of bottle trees stand in the corner of Ille Coronos\n"+
     "gardens, against the walls that protect the flaura and fauna.  \n"+
     "The cobblestone pathway winds close to them, southward, \n"+
     "along the sides of the garden walls.\n");
  set_day_desc(
     "The sunlight beams down on you from on high, peeking through the \n"+
     "white fluffy clouds.\n");
  set_night_desc(
     "The moon stares down at you as dark sinister clouds pass by.\n");

  set_listen("The air is silent; the sound of peace.\n");

  set_items(({
     "wall#walls",
          "Tall walls surround the gardens, protecting the flaura and "+
          "fauna inside",
     "bottle tree#bottle trees#tree#trees",
          "So named after its strange shape, the trunk of bottle trees \n"+
          "are almost seven feet in diameter. Their spread of leaves   \n"+
          "make this place ideal for picnics, and for resting in peace",
     "path#cobblestone path#cobblestones#cobblestone",
          "A well travelled cobblestone path",
  }));
  set_day_items(({
     "sunlight#sun#light",
          "Do you want to go blind?",
     "cloud#clouds",
          "They are white and fluffy. One reminds you of an echidna",
  }));

  set_night_items(({
     "moon",
          "You can see the man in the moon. He \n"+
          "appears to be grinning an evil grin at you",
     "cloud#clouds",
          "They look dark and sinister...and very spooky",
  }));

  set_exits(({
	"d/coronos/w/angel/city/gardens/garden2", "southwest",
	"d/coronos/w/angel/city/gardens/garden4", "southeast",
	"d/coronos/w/angel/city/gardens/garden3", "south",
  }));
  set_weather(1,4,0);
}

