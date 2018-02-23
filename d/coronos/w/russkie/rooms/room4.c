#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {
  load_door(({
       "file",       "/d/coronos/w/russkie/rooms/hall4",
     "direction",   "north door",
     "long",        "A door made of dark walnut",
     "closed",
     "locked",
     "lock id",     "lock",
     "lock long",    "A silver lock with the number 4 on it.",
     "key id",       "skyes tavern and inn",
     "lock difficult", 17,
  }));

  if(!present("sofa")) {
    object sofa;
     sofa = clone_object("inherit/chair");
    sofa -> set_max_sitters(3);
    sofa -> set_short("a dark green sofa");
    sofa -> set_long("\
This is a soft green sofa. It looks perfectly comfortable.\n");
    sofa -> set_name("sofa");
    move_object(sofa, this_object());
  }

  if(arg) return;

  set_short("a room in skyes inn");
  set_long("\
A large window shows a view of the outdoors, while inside the room\n\
is a soft feather bed, an antique desk, and a small sofa. The room\n\
is fairly clean, and the walls are painted a soft green color. There\n\
is a faint scent of smoke and old perfume in the room.\n");
  set_weather(1, 1, 0);

  set_items(({
"window#street#curtains",
"Green curtains frame this window. From here you can see the street below.\n",
"desk",
"This is a large, oak antique desk. It is really quite pretty.\n",
"outdoors",
"The view from the window is very nice.\n",
"bed#feather bed",
"This is a large, soft feather bed. It is covered in soft silk.\n",
"silk",
"The bed is covered in soft, green silk.\n",
"walls",
"The walls are a soft green shade, and have faint smoke stains on them.\n",
   }));
}
