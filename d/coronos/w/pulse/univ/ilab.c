/******************************************************************************
 * entrance.c
 * Illusion Lab
 * Mage University
 * 
 * Pulse,
 * October 1996
 * <john@bitsmart.com>
 */
 
#include <mudlib.h>
inherit "/d/coronos/w/solstice/univ/class/mage_gld";
 
void reset(int arg) {
  if (arg) {
    return;
  }
 
  ::reset(arg);
  if (!present("rhiannon")) {
    guild_master=clone_object("/d/coronos/w/solstice/univ/monst/rhiannon");
    move_object(guild_master, this_object());
    set_guild_master_name(guild_master->query_name());
  }
  set_long(
    "A endless row of mirrors stretches along either side of this hallway,\n"+
    "playing havoc with the images of whoever enters in the room.  Aspiring\n"+
    "illusionists must have a blast in this room.\n"
  );
  
  set_items((  {
    "mirror#mirrors",
    "The number of times each mirror is reflected off each other is enough\n"+
    "to make the hardiest person a little queasy.\n"
  } ));
  
  set_weather(2,3,0);
  
  set_classes(( {
    "mage", ({ "illusion", }),
  } ));
  
  set_exits(( {
    "/d/coronos/w/solstice/univ/hall_lft", "east",
    "/d/coronos/w/solstice/univ/nlab", "north"
  } ));
 }
 
 
