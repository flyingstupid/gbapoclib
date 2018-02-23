/******************************************************************************
 * nlab.c
 * Necromancy Lab
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
  if (!present("roc")) {
    guild_master=clone_object("/d/coronos/w/solstice/univ/monst/roc");
    move_object(guild_master, this_object());
    set_guild_master_name(guild_master->query_name());
  }
  set_long(
    "This room seems to have been originally similar to the rest of the\n"+
    "university, but black paint has been thrown on the walls, and black\n"+
    "stained canvas covers the floor.  A few corpses are littered about the\n"+
    "room.  A poster bill lies on the far wall.\n"
  );
  
  set_items((  {
    "wall",
    "All of Roc's walls have turned to black.\n",
    
    "ground#canvas",
    "All of Roc's walls have turned to black.\n",
    
    "corpse#corpses",
    "Some twitch with powerful magics.  They're probably used by\n"+
    "Roc's students for practicing their death magics.\n",
    
    "bill#poster bill",
    "It reads 'To Kill A Dead Man, from an original idea by Portisehead'.\n"
  } ));
  
  set_weather(2,3,0);
  
  set_listen("It is deathly quiet in this room.\n");
  
  set_smell("The stench of rotting corpses fills the room.\n");
  
  set_classes(( {
    "mage", ({ "necromancy", }),
  } ));
  
  set_exits(( {
    "/d/coronos/w/solstice/univ/ilab", "south"
  } ));
 }
 
 
