#include <mudlib.h>

#define PATH 	"d/coronos/w/angel/city/univ"
#define MONST	"d/coronos/w/angel/city/monst"

inherit ROOM;

void reset(status arg) {

  if(!present("apprentice")) 
    move_object(clone_object(MONST+"/apprentice"), this_object());
  if(arg) return;

  set_short("the University of Power");
  set_long(
"This long hallway separates the public library from the dinning \n"+
"hall to the south. Lights dance off the polished marble floor   \n"+
"cast by torches in silvery sconces, and illuminating the staircase\n"+
"that winds upstairs into the darkness.\n");

  set_weather(2, 1, 0);

  set_items(({
	"floor", 
	"When an apprentice wizard is punished for wrong doing he \n"+
	"is sent here to polish the floor with his small cantrip spells.\n",

	"torch#torches", "They seem to burn on for ever",
	"sconces", "They hold torches which are lit",
	"light", "It almost hypnotises you . . .",

  }));


  set_listen("All is quite and peaceful here.\n");
  set_smell("You can smell food from the south.\n");

  set_exits(({
        "d/coronos/w/angel/city/univ/library1", "west",
        "d/coronos/w/angel/city/univ/dinning", "south",
        "d/coronos/w/angel/city/univ/guild",   "up",
  }));
}


