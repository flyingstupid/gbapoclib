#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
  object ob;
  int i;

  if(!present("guard")) {
    for(i=0; i<2; i++) {
      ob = clone_object("d/coronos/w/angel/city/monst/bguard");
      move_object(ob, this_object());
    }
  }

 
  reset_doors(arg);
  load_door(({
    "destination", "d/coronos/w/darkness/b/hall/hall1",
    "direction", "oak door",
    "long", 
      "This solid, oaken door leads into the Beauracracy.\n",
    "door id", "east door",

    "key id", "city key",
    "closed",
  }));

  if(arg) return;

  set_short("a cobblestone street");
  set_long("\
A peaceful walk is what awaits travelers on this wide stone road.\n");
  set_day_desc("\
The sun beams down on this quiet cobblestone street. Birds peck\n\
the ground for food, and a slight salty breeze blows through the\n\
air. A railing to the west shows a view to a beach below, as well\n\
as the sea. The road continues to the southeast at this point.\n");
  set_night_desc("\
A cool night breeze blows softly through the street. Iron lamps\n\
offer a soft glow to the area, glinting off of the stones in the\n\
road. A bird screeches by now and then, but other than that all\n\
is very quiet here. The road continues to the southeast here.\n");
  set_day_items(({
    "birds",
    "Many seagulls fly overhead, hovering above you...better run for cover!\n",
    "railing#beach#sea",
    "From the edge of the railing you can see a beach and the rough ocean.\n",
    "street#stones",
    "This street is made up of large yellowish stones.\n",
    "sun#road",
    "The sun beats down on the road, creating warmth.\n",
    }));
  set_night_items(({
    "stars#sky",
    "The sky is a dark shade of midnight blue. Stars shine brightly there.\n",
    "street#stones#road",
"The street seems to be made of dark stones, though harder to see in the\n\
night.\n",
    "lamp post#lamp#light#post",
    "The lamp illuminates the area in a soft glow.\n",
    "lamps",
    "Tall, black iron lamps shine brightly in the night.\n",
    }));
  set_exits(({
  "/d/coronos/w/russkie/rooms/19", "northwest",
  "/d/coronos/w/russkie/rooms/23", "southeast",
  }));
}
