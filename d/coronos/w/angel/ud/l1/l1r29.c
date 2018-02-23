#include <mudlib.h>
#define PATH    "d/coronos/w/angel/ud/l1"
#define MONST   "d/coronos/w/angel/ud/monst"

inherit ROOM;

static int i;
static object mage, spider, guards;
void reset(status arg) {

  if(!mage) {
    mage = clone_object(MONST+"/mage1");
    move_object(mage, this_object());
  }

  if(!present("spider")) {
    for(i=0; i<4; i++) {
      spider = clone_object(MONST+"/spider");
      move_object(spider, this_object());
    }
  }


  if(arg) return;

  set_short("a cave");
  set_long(
"A small table made from dead and splintered wood sits in the corner\n"+
"littered with cards and coins and smelling of stale wine. A single \n"+
"torch is bound to the wall, giving some light to the table.\n");


  set_items(({
	"table", 
	"A simple square table, it seems to have been hastily put together",
	"wood",
	"It looks old and not very sturdy",

	"coins", 
	"A few copper coins sit on the table, they appear stuck there with \n"+
	"the amount of old wine spilt on the table.\n",

	"torch", "It is bound to the wall with some rope",
	"rope",  "It binds the torch to the wall",
	"wall",  "The cave wall",

	"card#cards", "A set of playing cards, probably of drow origin",
	
  }));

	

  set_listen("You can hear from chanting coming from the west.\n");
  set_smell("There is the scent of strong insence in the air.\n");

  set_exits(({
	PATH+"/l1r30", "west",
	PATH+"/l1r28", "east",
  }));

  set_weather(2, 1, 0);
}

void init() {
  ::init();
  add_action("no_exit", "west");
}

status no_exit() {
  if(present("mage")) {
    write("Mage blocks your path.\n");
    return 1;
  }
}
