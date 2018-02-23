#include <mudlib.h>
#define PATH	"d/affils/ships/island2/"

inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("the beach of I'tool'Zar Isle");
  set_long(
"The west-end of the beach ends as a crop of rocks spears out from the\n"+
"seas. ");

  set_items(({
"rocks", 
"Several grey rocks jut out from the sandy beach",
"sea#seas",
	"The water looks good enough to go for a swim.\n"+
	"If you had swimming skills perhaps you could jump in",
  }));

  set_night_desc(
"Acipter, the white moon can be seen on the horizon, caressing \n"+
"the distant waters with soft white light\n");

  set_night_items(({
"acipter#moon", 
"Acipter is the white moon, and guardian of the good wizards of Magia",

"horizon", "You can see the moon just above the horizon",
  }));


  set_exits(({
	PATH+"beach2", "east",
  }));
  
  set_weather(1, 1, 6);
}


