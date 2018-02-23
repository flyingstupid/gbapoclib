#include <mudlib.h>
#include "paths.h"
inherit ROOM;


void reset(status arg) {
  
  if(!arg) {
     set_short("the elfin forest");
     set_long(
"You are travelling along the western end of the forest. Screeches and\n"+
"sceams echo around the forest. You look up, and all you see is \n"+
"a cliff face to the north. There is a slight trail of blood on the \n"+
"ground which smears off to the north.\n");
     set_exits(({
	CAVES+"cave1", "north",
	PATH+"new10", "south",
	PATH+"new12", "east",
     }));
     set_listen("The screeches of forest birds echo throughout the forest\n");
     set_smell("You can smell the sweet fragrance of the forest\n");
     set_items(({
	"cliff#cliff face",
	"A tall cliff face looms to the north",

	"forest#tree#trees",
	"You can't see the forest through the trees",

	"ground",
	"It is smeared with blood",

	"trail#blood",
	"A long trail of blood. It looks as though someone,\n"+
	"or something has dragged a body to the north.\n",
     }));
     set_weather(1,4,3);
   }


}
