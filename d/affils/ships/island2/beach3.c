#include <mudlib.h>
#define PATH	"d/affils/ships/island2/"

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the beach of I'tool'Zar Isle");
  set_long(
"The east-end of the beach ends in a cliff, rising high toward the \n"+
"sky. ");

  set_items(({
"cliff",
	"The cliff is very steep, but you may be able to climb it.\n",
 "sea#seas",
	"The water looks good enough to go for a swim.\n"+
	"If you had swimming skills perhaps you could jump in",
  }));

  set_night_desc(
"Acipter, the white moon can be seen on the horizon, caressing \n"+
"the distant waters with soft white light.\n");

  set_night_items(({
"acipter#moon", 
"Acipter is the white moon, and guardian of the good wizards of Magia",

"horizon", "You can see the moon just above the horizon",
  }));


  set_exits(({
	PATH+"beach2", "west",
	PATH+"cliff1", "up",
  }));
  
  set_climb(10);
  set_fall_dam(10);

  set_listen(
"You can hear the waves rolling up on the beach, and the squawk of gulls.\n");

  set_weather(1, 1, 6);
}


