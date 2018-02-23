#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {
  load_door(({
     "file",        "/d/coronos/w/russkie/rooms/hall2",
     "direction",   "north door",
     "long",        "A door made of dark walnut",
     "closed",
     "locked",
     "lock id",     "lock",
     "lock long",   "A silver lock with the number 2 on it.",
     "key id",       "skyes tavern and inn",
     "lock difficult", 17,
  }));

  if(!present("chair")) {
    object chair;
    chair = clone_object("inherit/chair");
    chair -> set_max_sitters(1);
  chair -> set_short("a small brown chair");
    chair -> set_long("\
Although small, this chair looks perfectly comfortable for one person.\n");
    chair -> set_name("chair");
    move_object(chair, this_object());
  }

  if(arg) return;

  set_short("a room in skyes inn");
  set_long("\
A large window shows a view of the outdoors, while inside the room\n\
is a soft feather bed, a round table, and a wooden chair. The room\n\
is fairly clean, and the walls are painted a light mauve shade. There\n\
is a faint scent of smoke and old perfume in the room.\n");
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
"The bed is covered in soft mauve silk.\n",
"walls",
"The walls are a soft mauve color, and have faint smoke stains on them.\n",
   }));
}
