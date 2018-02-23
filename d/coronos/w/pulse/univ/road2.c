/******************************************************************************
 * entrance.c
 * Entance road to Mage University
 * 
 * Pulse,
 * October 1996
 * <john@bitsmart.com>
 */
 
#include <mudlib.h>
inherit ROOM;
 
void reset(int arg) {
  if (arg) {
    return;
  }
  
  set_long(
    "Tall oak trees shade a nondescript cobblestone road that leads away\n"+
    "from the hustle and bustle of the city.  This path appears well\n"+
    "trodden and every now and then a young mage apprentice rushes by,\n"+
    "probably late for training or a lecture.  Further north lies the\n"+
    "goal of these apprentices: a magnificent archway leading to the two\n"+
    "sections of the School of Magic, the university where all aspiring\n"+
    "mages eventually find themselves.\n"
  );
  
  set_items(( {
    "stone#stones",
    "What did you expect to find on a cobblestone road?\n",
	    
    "oak#oaks#tree#trees",
    "Magnificent and venerable oaks that provide shade and peace to the\n"+
    "travelers of this path.\n",
    
    "arch",
    "It is difficult to make out details of the arch, but it appears to be\n"+
    "magnificently crafted.  Mages spare no expense for their own comfort\n"+
    "and furnishings.\n",
    
    "school",
    "The famed School of Magic in Ille Coronos lies under the arch to the\n"+
    "north of here.\n",
	    
    "apprentice#apprentices",
    "They appear to be students at the university, and seem to have little\n"+
    "time to think, less to talk.\n"
  }));
  
  set_listen(
    "Underneath the grumbling of the apprentices that pass by, you can hear\n"+
    "the chirping of birds, the rustling of woodland animals, and the soft\n"+
    "whisper of a mild breeze.\n"
  );
  
  set_smell("The smells of the forest aromate the road.\n");
  set_weather(2,3,0);
  
  set_exits(( {
    "/d/coronos/w/solstice/univ/entrance", "north"
  }));
	  
}
	    
