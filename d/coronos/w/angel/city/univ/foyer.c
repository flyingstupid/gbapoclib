#include <mudlib.h>

#define PATH 	"d/coronos/w/angel/city/univ"
#define MONST	"d/coronos/w/angel/city/monst"

inherit ROOM;

void reset(status arg) {
  int i;
  object ob;

  reset_doors(arg);
  load_door(({
	"file", PATH+"/path2",
	"direction", "west door",
	"long",
	        "A grand set of double doors, bound in iron and gold, and bearing \n"+
        "several circles of stained glass windows. Each is a different    \n"+
        "colour; white, grey and black to represent the Three Robes .\n",
  }));

  load_door(({
	"file", PATH+"/common",
	"direction", "south door",
	"long", "A strong sturdy door made from hard wood and bound in iron\n"+
		"A golden plaque onthe door reads:\n"+
		"\tMaster's Common Room.\n",
  }));

  if(!present("clerk")) {
    ob = clone_object(MONST+"/clerk");
    move_object(ob, this_object());
  }

  if(!present("apprentice")) {
    for(i=0; i<3; i++) {
      ob = clone_object(MONST+"/apprentice");
      move_object(ob, this_object());
    }
  }

  if(arg) return;

  set_short("the University of Power");
  set_long(
"The large grant entrance known only as the Grand Hall is impressive in \n"+
"the most extravagant of the word. A huge crystal chandelier is its     \n"+
"centre piece, glowing softly at thousands of points with small blue    \n"+
"magical lights that splay into a myriad of colours into the room below.\n"+
"In the very centre of the room is a marble pedestal with a bust of a   \n"+
"noble looking man.\n");

  set_weather(2, 1, 0);

  set_items(({
"chandelier", 
"A thousand crystals went into its construction. It is the most \n"+
"impressive sight in the whole Grand Hall of the university.\n",

"light#lights#blue lights",
"The blue lights were created by the apprentices who live within the \n"+
"dormitory on the upper floors. They used a cantrip known as blue light\n"+
"to achieve the effect",

"colour#colours",
"The colours of the rainbow spread out into the Grand Hall below the chandelier",

"bust#clerk#statue",
"The bust looks like a clerk, with horn rimmed glasses perched on \n"+
"the tip of his nose, and a small neatly trimmed moustache",

"pedestal",
"There is a small plaque of gold on the pedestal which reads:\n"+
"\tUniversity Guide. Speak and you will know the way",

  }));

  set_exits(({
	PATH+"/admin", "north",
	PATH+"/common", "south",
  }));
}

