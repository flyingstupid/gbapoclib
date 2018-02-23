#include <mudlib.h>
inherit ROOM;

void reset(status arg){
    if(!present("blue chair")){
	move_object(clone_object("/d/ooc/w/alena/blue_chair"),this_object());
    }

	if(!present("red chair")){
	    move_object(clone_object("/d/ooc/w/alena/red_chair"),this_object());
	}


	if(arg) return;

	set_long(
	  "The ceiling vaults high above, a single skylight allowing a good "+BS(n)+
	  "view of the sky above. Two chairs occupy the room and look so very "+BS(n)+
	  "comfortable. A blue one sits in the northeastern corner of the room, "+BS(n)+
	  "and a red one in the southeastern. Diagonal from the comfy blue "+BS(n)+
	  "chair stands a tall plant. A large rug covers the hardwood floor "+BS(n)+
	  "and quiets the sound of feet in the room. A large picture window "+BS(n)+
	  "allows one to look out westward. A staircase leads to the "+BS(n)+
"upstairs. A screened in porch extends onto the main house \n"+
"to the west.\n");

	set_short("the main entrance");
	set_weather(2,2,0);

	set_night_desc(
	  "The windows are dark and no light shines through from above."+BS(n));
	set_items(({
	    "stairs#staircase",
	    "A simple set of stairs leading to the upstairs room."+BS(n),
	    "ceiling#skylight",
	    "It rises high above, opening up the room and making it feel "+BS(n)+
	    "larger. The skylight is a single window that provides a "+BS(n)+
	    "reminder of the world outdoors.",
	    "chairs#chair",
	    "There is a blue one and a red one, which do you wish to look at?",
	    "plant#tall plant",
	    "Standing about five feet high the plant looks like a rubber plant.",
	    "rug#large rug",
	    "It's main purpose is to cover up the hardwood floor and to "+BS(n)+
	    "protect it from scuff marks from shoes and boots. It also "+BS(n)+
	    "dampens the sounds of feet upon wood, making it a bit quieter "+BS(n)+
	    "then it could be. It's a deep beige color with a dark blue trim.",
	    "floor#hardwood floor",
	    "A standard hardwood floor that shows years of use.",
	    "large picture window#window#picture window#large window",
	    "Looking out you can see a huge oak tree and a couple of bushes. "+BS(n)+
	    "Occasionally a person wanders by.",
	    "oak#oak tree#huge oak#huge oak tree",
	    "It would be better to look at it from outside, don't you think?",
	  }));

	set_exits(({
"/d/ooc/w/alena/main/porch1","porch",
	    "/d/ooc/rooms/ooc1","out",
	    "/d/ooc/rooms/ooc4","stairs",
	  }));
 add_exit("/d/ooc/w/kreston/spades.c", "south");

	set_smell("Nothing of interest to smell here."+BS(n));
	set_listen("You hear the voices of people chatting from all around."+BS(n));

  set_ooc_room(1);
}
/* Lena, Sept 25, 1996 */
