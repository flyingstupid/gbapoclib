#include <mudlib.h>
inherit ROOM;

  void reset(status arg) {
  if(!present("woman")) {
  move_object(clone_object("/d/coronos/w/russkie/npc/woman"),this_object());
}

 
  reset_doors(arg);
  load_door(({
    "destination", "d/coronos/w/darkness/b/hall/hall7",
    "direction", "oak door",
    "long", 
      "This solid, oaken door leads into the Beauracracy.\n",
    "door id", "north door",
    "key id", "city key",
    "closed",
  }));

  if(arg) return;
  set_short("a beautiful cliff");
  set_long("\
The street has come to a beautiful apex here. Railings spring up\n\
around the sides of the area, as a cliff drop to the sea surrounds\n\
the area. Many people just stand here, looking in awe at the sea.\n");
  set_day_desc("\
The sun beats down onto the cobblestone street, and creates some\n\
needed warmth to fight off the cool ocean breezes.\n");
  set_night_desc("\
The moon lights the area beautifully, with help from softly lit\n\
iron lamps that sprout up here and there. Cool sprays of salty\n\
air make the area very chilly.\n");
  set_day_items(({
"street#apex",
"The street is widely open here, showing much of the sea.\n",
"railings",
"Large metal railings keep silly people from falling to the jagged\n\
rocky waters below.\n",
"cliff#sea",
"This street is right on the edge of the cliff. You can see the wild\n\
sea below from here.\n",
"sun#sky",
"The sun looks bright and warm in the sky.\n",
}));
  set_night_items(({
"street#apex",
"The street is widely open here, showing much of the dark sea.\n",
"air",
"You can actually see wisps of sea mist in the air.\n",
"railings",
"Large metal railings have been placed at the edge of the street\n\
for safety.\n",
"cliff#sea",
"You can see past the rocky cliff, to the dark, wild sea.\n",
"moon#lamps",
"The moon, along with softly lit lamps, light the area perfectly.\n",
}));
  set_weather(2, 6, 0);
  set_exits(({
"/d/coronos/w/russkie/rooms/26", "northeast",
"/d/coronos/w/russkie/rooms/25", "northwest",
}));
}
