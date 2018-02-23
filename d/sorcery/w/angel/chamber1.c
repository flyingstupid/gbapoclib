#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  if(arg) return;
  load_door(({
	"file", "d/sorcery/w/angel/hall1",
	"direction", "north door",
	"long",
	"A large set of double doors with a single circle of \n"+
	"protection in its centre in three colours; white, grey, "+
	"and black",
  }));


  set_short("the chambers of the nine");
  set_long(
"You stand in the central chamber of the Council of the Nine, \n"+
        "the wizards who rule over the teaching of magic in the realms\n"+
        "of Magia. A long circular desk of black wood stands in the   \n"+
        "centre, with a break at the front so that someone may pass  \n"+
        "into its centre. Along the edges stand nine high backed chairs,\n"+
        "three with white satin in the backs, three with black silk, and\n"+
        "three with grey suede.\n");

  set_items(({
	"desk",
	"A long desk of fine black wood. It appears to be made from \n"+
	"a single piece of wood as you can see no joins or workings \n"+
	"on the surface at all.\n",

	"chair#chairs",
	"Each of the three representatives of each alignment sits \n"+
	"behind their chair during meetings of the council of magic.\n",
  }));
  set_weather(2, 1, 0);

  set_exits(({
	"d/sorcery/w/angel/hall1", 
	"north",
  }));
}  
