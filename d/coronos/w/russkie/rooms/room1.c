#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {
  load_door(({
     "file",        "/d/coronos/w/russkie/rooms/hall1",
     "direction",   "north door",
     "long",        "A door made of dark walnut",
     "closed",
     "lock id",     "lock",
     "lock long",   "A silver lock with the number 1 on it.",
     "key id",       "skyes tavern and inn",
     "lock difficult", 17,
  }));

  if(!present("loveseat")) {
    object loveseat;
    loveseat = clone_object("inherit/chair");
    loveseat -> set_max_sitters(2);
    loveseat -> set_short("a cute loveseat");
    loveseat -> set_long("\
This small loveseat is just the right size for two. It looks very comfy.\n");
    loveseat -> set_name("loveseat");
    move_object(loveseat, this_object());
  }

  if(arg) return;

  set_short("a room in skyes inn");
  set_long("\
A large window shows a view of the outdoors, while inside the room\n\
is a soft feather bed, a small table, and a cute loveseat. The\n\
room is fairly clean, and the walls are painted a soft shade of\n\
ivory. The air has a faint scent of smoke and old perfume.\n");
  set_weather(1, 1, 0);

  set_items(({
"window#street#curtains",
"Red curtains frame this window. From here you can see the street below.\n",
"table",
"A small wooden table flanks one corner of the room.\n",
"outdoors",
"The view from the window is very nice.\n",
"bed#feather bed",
"This is a large, soft feather bed. It is covered in soft silk.\n",
"silk",
"The bed is covered in soft red silk.\n",
"walls",
"The walls are painted a soft shade of ivory, and have faint smoke stains.\n",
   }));
}
