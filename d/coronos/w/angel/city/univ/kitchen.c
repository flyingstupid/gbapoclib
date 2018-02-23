#include <mudlib.h>

#define PATH 	"d/coronos/w/angel/city/univ"
#define MONST	"d/coronos/w/angel/city/monst"

inherit ROOM;

void reset(status arg) {
  int i;

  if(!present("apprentice")) {
    for(i=0; i<6; i++) {
      move_object(clone_object(MONST+"/appr"), this_object());
    }
  }

  if(!present("gadrian")) {
    move_object(clone_object(MONST+"/cook"),this_object());
  }

  if(arg) return;

  set_short("the University of Power");
  set_long(
"The kitchen serves the meals for those students and masters who live and \n"+
"work within the walls of the great University of Power. Almost 24 hours a\n"+
"day the staff in here can be found preparing meals; cooking all kinds of \n"+
"delicacies catering for humans and demihuman kind. A great pantry stands \n"+
"to the south, while large pots of stew burn continuously on the old fire \n"+
"pit in the centre of the room.\n");

  set_weather(2, 1, 0);

  set_items(({
	"food#foods",
	"The food looks very yummy",
	"great pantry#pantry", "It looks well stocked with all manner of foods\n",
	"pots#pot",
	"Several large pots sit on the fire bubbling away.\n",
	"fire", "A steady fire of hot coals keeps the stew hot",
	"stew", "It looks like a chicken and vegetable stew",
  }));

  set_listen("The bubbling from the cooking pots makes your mouth water.\n");
  set_smell("The delights of the kitchen invite you to taste something.\n");

  set_exits(({
	PATH+"/dinning", "north",
	PATH+"/staff",   "west",
  }));
}


