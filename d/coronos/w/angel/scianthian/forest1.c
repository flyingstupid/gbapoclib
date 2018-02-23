#include <mudlib.h>
#include "path.h"
inherit ROOM;
#include <mudlib.h>

void reset(status arg) {
  string *smells;
  object leather_jacket;

  leather_jacket = present("leather jacket");

  if(!leather_jacket) {
    leather_jacket = clone_object(ARMOUR);
    call_other(leather_jacket, "set_name", "leather jacket");
    call_other(leather_jacket, "set_armour_material", "leater");
    call_other(leather_jacket, "set_short", "A leather jacket");
    call_other(leather_jacket, "set_alias", "jacket");
    call_other(leather_jacket, "set_long", 
		"A worn but sturdy leather jacket.\n" +
	  	"On the back is a lot of rivets making the pattern of a star.\n");
    call_other(leather_jacket, "set_value", 200);
    call_other(leather_jacket, "set_weight", 2);
    call_other(leather_jacket, "set_ac", 1);
    call_other(leather_jacket, "set_type", "armour");
    move_object(leather_jacket, this_object());
  }

  if(arg) return;

  smells = ({
	"The air is fresh and cool.\n",
	"The air is cold against your skin.\n",
	"The cool air gives you goosebumps.\n",
	"The air smells of pine.\n",
	"The air smells sweet and crisp.\n",
	"The air smells fresh.\n",
  });

  set_smell(smells[random(sizeof(smells)-1)]);
  set_short("scianthian forest");
  set_weather(1, 1, 0);
  
  set_items(({
	"trees", "The trees stand over 50 feet tall",
	"undergrowth", "The undergrowth is very wild in this forest",
  }));


  set_long(
	"The canopy of the forest is oppressive, blocking all visible \n"+
	"light from the heavens above. The trees here are quite large,\n"+
	"and the undergrowth quite wild.\n");

  set_exits(({
	PATH+"wild1", 	"east",
	PATH+"clearing", 	"west",
  }));


}

void fix_jacket() {

}
