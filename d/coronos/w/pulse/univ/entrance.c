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
  
  if (!present("oshido")) {
    move_object(clone_object("/d/coronos/w/solstice/univ/monst/oshido"),
		this_object());
  }
  
  set_long(
    "The cobblestone gives way to a smooth stone tile as you stand before\n"+
    "the school.  Directly north is the magnificent archway that greets\n"+
    "visitors to this impressive college.\n"
  );
  
  set_items((  {
    "stone#stones#tile",
    "It appears to be slate and is laid in neat squares, each perfect in\n"+
    "shape and form; mages would expect no less.\n",
    
    "arch#archway",
    "Magnificently crafted, the archway connects the top of the left\n"+
    "side of the college to the right side.  The face is constructed of\n"+
    "white marble with an inscription engraved on it.\n",
    
    "inscription",
    "The inscription reads, \"Institute for Extraphysical Studies,\n"+
    "Established in Search of Truth and Knowledge\".\n",
    
    "school#college#institute",
    "One of the first and foremost establishments of Ille Coronos, the\n"+
    "institute has been proudly training aspirants in the ways of knowledge\n"+
    "and prides itself on its numerous and prosperous students.\n"
  } ));
  
  set_listen(
    "The scuffle of sandles and the murmur of voices comes beyond the\n"+
    "archway.\n"
  );
  
  set_smell("A mild breeze carries the scent of fresh air to your senses.\n");
  set_weather(2,3,0);
  
  set_exits(( {
    "/d/coronos/w/solstice/univ/road", "south",
    "/d/coronos/w/solstice/univ/archway", "north"
  } ));
}
	    
