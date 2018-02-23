inherit "players/relgar/temple/main";
#include "/players/relgar/private/mydefs.h"

void init() {
    ::init();
} /* End of init */

reset (arg) {
    if(!present("priest")){
	move_object( PRIEST ,this_object()); }

    load_door(({
	"destination","d/tempus/w/relgar/steps",
	"direction","south door",
	"open","unlocked",
	"lock difficulty",1000,
	"long",
	"The large pair of double doors to the south appear to lead out of the\n"+
	"cathedral to open air.\n",
	"door number",1,
	"trap off",
	"lock id","lock",
	"key id","key",
      }));
    if(arg) return;
    set_exits(({
	"/d/tempus/w/relgar/altar","north",
	"/d/tempus/w/relgar/tside4","east",
	"/d/tempus/w/relgar/tside3","west",
      }));
    set_short("Entrance of the cathedral");
    set_long(
      "\tYou have walked into this large cathedral at the edge of town.\n"+
      "Here is where many of the cities darker folk come to worship their own\n"+
      "gods and religions. The floor is a polished, black marble tile which\n"+
      "matches the tile on the tall cloumns that reach to the ceiling on either\n"+
      "side of the walk up to the altar to the north. On each of the columns\n"+
      "is a wall sconce with a smokey torch that fills the room with not only\n"+
      "light but a foul smelling haze.\n"
    );
    set_weather(2,2,0);
    set_items(({ 
	"floor","The floor here is of polished marble tile.\n",
	"tile#marble","The marble tiles of the floor seem to almost swirl as you "+
	"look at them.\n",
	"columns#column","The columns of this cathedral are mad of the same tile "+
	"as the floor.\nThere are sconces on each column that hold torches that "+
	"fill the room\nwith a smokey light.\n",
	"sconce#wall sconce","These bronze holders house the torches that create "+
	"the smokey light that\nfills the room.\n",
	"torch#torches","The torches made of oil soaked rags burn to provide light "+
	"for the temple.\n They are very smokey.\n",
	"smoke#haze","The smokey haze fills the room with a foul odor.\n",
	"altar","The altar is to the north. You could get a better look if you "+
	"went north.\n",
	"walk#aisle","The aisle between the columns leads to the altar to the "+
	"north.\n"
      }));  /* end of items */
    set_smell("The odor of attar and sulfur fills the air to the point "+
      "of being\nunbearable.\n");
    set_listen("You can hear the crackle of burning torches and the "+
      "chants of priests.\n");
} /* end of reset */

