/******************************************************************************
 * archway.c
 * Under the Archway - Mage College
 * 
 * Pulse
 * October, 1996
 */
 
#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
  if (arg) {
    return;
  }
  
  ::reset(arg);
  
  load_door(( {
    "destination", "/d/coronos/w/solstice/univ/hall_rt",
    "direction",   "east door",
    "long",        "A solid oak door with an ornately carven steel handle\n"+
		   "with the insignia of the school prominently carved in\n"+
		   "middle.\n",
  } ));
  
  load_door((  {
    "destination", "/d/coronos/w/solstice/univ/hall_lft",
    "direction",   "west door",
    "long",        "A solid oak door with an ornately carven steel handle\n"+
		   "with the insignia of the school prominently carved in\n"+
		   "middle.\n",
  } ));
  
  set_long(
    "The archway provides cover for the road that cuts the college in two.\n"+
    "To the north is the plaza where apprentices relax when not laboring\n"+
    "over mastery of strange magics.  To the south lies the road back to\n"+
    "the city.  To the east and west lie the respective halves of the\n"+
    "college.\n"
  );
  
  set_items(( {
    "plaza",
    "A wide open area with a fountain in the middle and several tables with\n"+
    "chairs for apprentices and mages to rest when not caught in the\n"+
    "hectic pace of school.\n",
    
    "road",
    "The road is made of perfectly cut squares of a smooth stone, possibly\n"+
    "slate.\n",
    
    "college",
    "To the east and west is the prestigious College for Extraphysical\n"+
    "Sciences.  The College is as old as the city itself; rooms have been\n"+
    "added as needed since that time.  Perhaps that explains the reason\n"+
    "for the college being split in half.\n"
  } ));
  
  set_weather(2,3,0);
  set_listen(
    "The scuffling of feet and the murmur of voices fill your ears.\n"
  );
  
  set_smell(
    "It smells like some mages spend too much time studying and not enough\n"+
    "time attending to bathing.\n"
  );
  
  set_exits(( {
    "/d/coronos/w/solstice/univ/entrance", "south",
    "/d/coronos/w/solstice/univ/plaza", "north"
  } ));
}
    
