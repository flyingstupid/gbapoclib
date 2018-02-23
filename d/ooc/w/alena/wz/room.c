#include <mudlib.h>
inherit ROOM;

	}


	if(arg) return;

	set_long(
	  "The ceiling vaults high above, a single skylight allowing a good "+BS(n)+
	  "upstairs."+BS(n));

	set_short("the main entrance");
	set_weather(2,2,0);

	set_night_desc(
	  "The windows are dark and no light shines through from above."+BS(n));
	set_items(({
	    "stairs#staircase",
	    "A simple set of stairs leading to the upstairs room."+BS(n),
	    "rug#large rug",
	    "It's main purpose is to cover up the hardwood floor and to "+BS(n)+
	    "protect it from scuff marks from shoes and boots. It also "+BS(n)+
	    "dampens the sounds of feet upon wood, making it a bit quieter "+BS(n)+
	    "then it could be. It's a deep beige color with a dark blue trim.",
	    "floor#hardwood floor",
	    "A standard hardwood floor that shows years of use.",
	  }));

	set_exits(({
	    "/d/ooc/rooms/ooc1","out",
	    "/d/ooc/rooms/ooc4","stairs",
	  }));

	set_smell("Nothing of interest to smell here."+BS(n));
	set_listen("You hear the voices of people chatting from all around."+BS(n));

  set_ooc_room(1);
}
/* Lena, Sept 25, 1996 */
