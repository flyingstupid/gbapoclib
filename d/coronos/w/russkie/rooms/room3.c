#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {
  load_door(({
      "file",       "/d/coronos/w/russkie/rooms/hall3",
     "direction",   "south door",
     "long",        "A door made of dark walnut",
     "closed",
     "locked",
     "lock id",     "lock",
     "lock long",   "A silver lock with the number 3 in it.",
     "key id",       "skyes tavern and inn",
     "lock difficult", 17,
  }));

  if(!present("couch")) {
    object couch;
     couch = clone_object("inherit/chair");
    couch -> set_max_sitters(4);
  couch -> set_short("a long silk couch");
    couch -> set_long("\
This is a long blue silk couch. It looks very comfortable to sit on, and\n\
large enough to invite some friends!\n");
    couch -> set_name("couch");
    move_object(couch, this_object());
  }

  if(arg) return;

  set_short("a room in skyes inn");
  set_long("\
A large window shows a view of the outdoors, while inside the room\n\
is a soft feather bed, a stone table, and a large couch. The room\n\
is fairly clean, and the walls are painted a light blue shade. There\n\
is a faint scent of smoke and old perfume in the room.\n");
  set_weather(1, 1, 0);

  set_items(({
"window#street#curtains",
"Blue curtains frame this window. From here you can see the street below.\n",
"table",
"A large stone table takes up a lot of room in the corner.\n",
"outdoors",
"The view from the window is very nice.\n",
"bed#feather bed",
"This is a large, soft feather bed. It is covered in soft silk.\n",
"silk",
"The bed is covered in soft, blue silk.\n",
"walls",
"The walls are a soft blue color, and have faint smoke stains on them.\n",
   }));
}
