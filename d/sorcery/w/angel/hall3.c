#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object ob;

  if(!present("apprentice")) {
    ob = clone_object("d/sorcery/w/angel/monst/app");
    move_object(ob, this_object());
  }
  reset_doors(arg);
  if(arg) return;
  load_door(({
	"file", "d/affils/rooms/grm",
	"direction", "west door",
	"long", "A door of sturdy oak.\n",
  }));

  set_short("the tower of sorcery");
  set_long(
"The grand stair case ascends upward into the darkness from the main  \n"+
"foyer here in the Tower of High Sorcery. A narrow hallway, lit by    \n"+
"torches placed sporadically along its length, extends to the east.   \n");
  set_day_desc(
"Sunlight spills into the room from large stained glassed windows. \n");

  set_night_desc(
"The lack of light coming into the room gives the foyer a very sinister look.\n");

  set_weather(2, 1, 0);

  set_items(({
	"window#windows",
	"They are made from rich royal reds and blues, and depict scenes \n"+
	"of the battle between the One Whose Name is Spoken in Whispers, \n"+
	"and the guardians of Magic; Acipter, Majaan, and Zentrani.\n",

	"darkness", "Its very black",
	"shadow#shadows", "They look very sinister",
	"foyer#main foyer",
	"The foyer is where mages from all over the realms of Magia \n"+
	"come to meet and discuss the ways of magic.\n",

	"torch#torches",
	"The torches flicker and dance, spilling shadows onto the  \n"+
	"dark polished marble floor of the foyer.\n",

	"floor#marble",
	"The floor is made from a dark marble, and has veins of silver\n"+
	"and gold running across it. It is very likely that it was made "+
	"with powerful magics",
  }));
  
  set_exits(({
	"d/sorcery/w/angel/hall2", "up",
	"d/sorcery/w/angel/ehall1", "east",
	"d/sorcery/w/angel/hall4", "north",
  }));
}

