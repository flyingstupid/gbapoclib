#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  load_door(({
     "file",        "room/city/pub/inn1",
     "direction",   "west door",
     "long",        "A door of solid oak.\n",
     "closed",
     "locked",
     "lock id",     "lock",
     "lock description",
                    "An iron lock bearing the number 1 above it.\n",
     "key id",      "skandles downfall",
     "lock difficult", 15,
  }));

  if(arg) return;

  set_short("the inn above skandles downfall");
  set_day_desc(
     "A dusty corridor lit by the window at the end of the hallway \n"+
     "leads to the north. At intervals a few doors line the west wall.\n");
  set_night_desc(
     "A dusty corridor lit by a few small lamps leads to the north.\n"+
     "At intervals a few doors line the west wall.\n");
     
  set_exits(({
     "room/city/pub/hall2", "north",
     "room/city/pub/foyer", "down",
  }));

  set_day_items(({
     "window", "A small window with a white frame. The paint is slowly \n"+
     "flaking from exposure to the sun. From the window you can see the \n"+
     "whole city of Tempus below"
  }));
  set_night_items(({
     "lamp",
     "A few small lamps attached to the walls, light the corridor as \n"+
     "night has fallen, and the window at the end of the corridor is "+
     "quite shut",

     "window",
     "A small white window. It is locked closed"
  }));
  set_weather(1, 1, 0);
}
