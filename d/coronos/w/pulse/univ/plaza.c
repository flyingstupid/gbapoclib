/******************************************************************************
 * plaza.c
 * Mage University Plaza
 * 
 * Pulse,
 * October 1996
 * <johnw@bitsmart.com>
 */
 
#include <mudlib.h>
inherit ROOM;
 
void reset(int arg) {
  if (arg) {
    return;
  }
  
  if (!present("fountain")) {
    move_object(clone_object("/d/coronos/w/pulse/univ/objects/fountain"),
		this_object());
  }
  
  set_long(
    "The road under the archway broadens out into a plaza with an imposing\n"+
    "and beatiful fountain at the center.  This seems to be where mages\n"+
    "relax when chance smiles upon them and they find a free moment.\n"
  );
  
  set_items((  {
    "stone#stones#tile",
    "It appears to be slate and is laid in neat squares, each perfect in\n"+
    "shape and form; mages would expect no less.\n",
    
    "arch#archway",
    "Magnificently crafted, the archway connects the top of the left\n"+
    "side of the college to the right side.  The face is constructed of\n"+
    "white marble with an inscription engraved on it.\n",
    
    "school#college#institute",
    "One of the first and foremost establishments of Ille Coronos, the\n"+
    "institute has been proudly training aspirants in the ways of knowledge\n"+
    "and prides itself on its numerous and prosperous students.\n"
  } ));
  
  set_listen(
    "Laughter and voices rise above the soothing gurgle of the fountain.\n"
  );
  
  set_smell("A mild breeze carries the scent of fresh air to your senses.\n");
  set_weather(2,3,0);
  
  set_exits(( {
    "/d/coronos/w/pulse/univ/archway", "south",
    "/d/coronos/w/pulse/univ/cafe", "north"
  } ));
}
	    
