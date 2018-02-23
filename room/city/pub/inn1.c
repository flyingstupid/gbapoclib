#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  load_door(({
     "file",        "room/city/pub/hall1",
     "direction",   "east door",
     "long",        "A door of solid oak.\n",
     "closed",
     "locked",
     "lock id",     "lock",
     "lock long",   "An iron lock bearing the number 1",
     "key id",      "skandles downfall",
     "lock difficult", 15,
  }));

  if(!present("couch")) {
    object couch;
    couch = clone_object("inherit/chair");
    couch -> set_max_sitters(2);
    couch -> set_short("A small comfy leather couch");
    couch -> set_long(
     "The soft leather couch looks ideal to sit and rest comfortably in.\n");
    couch -> set_name("couch");
    move_object(couch, this_object());
  }

  if(arg) return;

  set_short("the inn above skandles downfall");
  set_long(
     "A small white window peers out over the street below, into \n"+
     "the city streets of Tempus. A small dark curtain is gathered\n"+
     "by its sides. The walls are sparsely decorated, as is the room. \n"+
     "the only items in the room to give any traveller any welcome  \n"+
     "is the soft bed, and the couch over against the far wall.\n");
  set_weather(1, 1, 0);

  set_items(({
     "window#white window",
     "A white window which looks over the city streets below",

     "street#streets#city#tempus",
     "From here you can easily see Merchant Street below",

     "wall#walls", "They are sparsely decorated",

     "bed", "A nice soft bed. This one has red cotton sheets"
   }));
}
