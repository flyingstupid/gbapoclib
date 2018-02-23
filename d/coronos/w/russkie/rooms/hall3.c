#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

  void reset(status arg) {
  load_door(({
    "file",     "/d/coronos/w/russkie/rooms/room3",
    "direction",  "south door",
    "long", "A strong maple door.\n",
    "closed",
    "locked",
    "lock id", "lock",
    "lock description", "A small silver lock with the number 3 on it.\n",
    "key id", "skyes tavern and inn",
    "lock difficult", 17,
}));

  if(arg) return;

  set_short("a hall in the inn");
  set_long("This is a narrow hall in the inn above Skyes tavern. There is a soft\n\
glow emitted from the small torched ensconced on the walls creating\n\
shadows across the room doors. The floor is covered in a soft blue\n\
rug, and the window at the end of the hall is boarded up.\n");
  set_exits(({
"/d/coronos/w/russkie/rooms/hall4", "west",
"/d/coronos/w/russkie/rooms/hall2", "east",
}));
  set_items(({
"floor#rug",
"The floor here is covered in a pale blue rug.\n",
"hall",
"This is a narrow hall in the inn.\n",
"torches#shadows#glow#walls#doors",
"The torches in the walls send shadows cascading across the room doors.\n",
"window#boards",
"The window at the end of the wall has been covered with flimsy boards.\n",
}));
set_weather(2, 1, 0);
}
