#include <mudlib.h>
inherit ROOM;

  void reset(status arg) {
  if(arg) return;

  set_short("a small beach house");
  set_long("\
Soft music can be heard from somewhere in this small living room,\n\
and the air is sweet with the scent of roses and soft magnolia. A\n\
large, antique curio cabinet stands in one side of the room, filled\n\
with small treasures. Dark blue silk drapes cover the windows, tied\n\
back with small, silver dolphin pins. A blue leather couch sits in\n\
front of a glowing fire. The fireplace is made of an icy white stone,\n\
that glimmers like opal in the light.\n");
  set_weather(2, 2, 0);
  set_items(({
"cabinet#curio#curio cabinet",
"The maple cabinet has a glass front, and is filled with little\n\
knick knacks.\n",
"treasures#knick knacks#figurines",
"Small, shimmering glass, crystal, and ceramic figurines fill the cabinet.\n",
"drapes#dolphins#pins#dolphin pins",
"Long, soft, silk drapes cover the windows. They are held back by small\n\
sterling silver dolphin tie-backs.\n",
"window#windows",
"The windows of the small house look out on the ocean.\n",
"couch",
"It is made of the finest blue leather.\n",
"fire#fireplace#stone",
"The beautiful fireplace looks as though it were made out of pure,\n\
flaming opal.\n",
}));
  set_exits(({
 "d/coronos/w/russkie/rooms/h2", "west",
"d/coronos/w/russkie/rooms/17", "east",
}));
}
