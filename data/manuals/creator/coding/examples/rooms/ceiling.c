#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object obj;
  int i;
  if(!present("possum")) {
    for(i=0; i<random(6)+1; i++) {
      obj = clone_object("room/city/garden/monst/possum");
      move_object(obj,this_object());
    }
  }

  if(arg) return;
  set_short("the rotunda rafters");
  set_weather(0,1,0);
  set_long(
     "The shadowy ceiling, far above the rotunda, is cosy and warm; the \n"+
     "perfect place for small animals to snuggle down and sleep. The    \n"+
     "clear sign of twigs and leaves indicates the animals who live here\n"+
     "are probably not far away.\n");
  set_items(({
     "twigs", "Many twigs lie scattered about the rafters supporting \n"+
              "a make shift bed for some small animals who live here",
     "leaves", "Red, brown, and green leaves sit in small piles, acting \n"+
               "as perfect insulation against any harsh weather that    \n"+
               "may assault the tall rotunda",
     "shadows", "They look very scary!",

     "ceiling", "It is covered in shadows",

     "rotunda", "The floor of the rotunda is far below you. If you fall \n"+
                "you might hurt yourself!",
  }));
  set_exits(({
	"d/coronos/w/angel/city/gardens/rotunda", "down",
  }));
  set_climb(6);
  set_fall_dam(5);
  set_search_array(({
     "leaves", "You find some nuts!\n",
     "twigs",   "You find some nuts!\n",
  }));
  add_extra_object("nuts", "room/city/garden/nuts");
}

