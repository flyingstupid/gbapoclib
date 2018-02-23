#include <mudlib.h>
#define PATH	"d/affils/ships/island2/"

inherit ROOM;

void reset(status arg) {
  object ob;
  int i;

  if(!present("dragonfly")) {
    for(i=0; i<4; i++) {
      ob = clone_object(PATH+"dragon_f");
      move_object(ob, this_object());
    }
  }

  if(arg) return;

  set_short("the beach of I'tool'Zar Isle");
  set_long(
"The soft sand of the beach stretches out toward the east and west of \n"+
"this tiny island. Tall trees sway in the breeze as the waves roll up,\n"+
"anointing the sand with its gentle touch. ");

  set_night_desc(
"Acipter, the white moon can be \n"+
"seen on the horizon, caressing the distant waters with soft white light\n");

  set_listen("The waves roll up on the beach, greeting\n"+
             "your ears with their soft lolling tones.\n");

  set_exits(({
	PATH+"beach3", "east",
	PATH+"beach1", "west",
  }));
  
  set_weather(1, 1, 6);
}


