#include <mudlib.h>

#define PATH 	"d/coronos/w/angel/city/univ"
#define MONST	"d/coronos/w/angel/city/monst"

inherit ROOM;

object ob;
void reset(status arg) {
  if(!ob) {
    ob = clone_object(MONST+"/damon");
    move_object(ob, this_object());
  }

  reset_doors(arg);
  load_door(({
	"file", PATH+"/admin",
	"direction", "southeast door",
	"long", "A fine and sturdy door",
  }));


  if(arg) return;

  set_short("the University of Power");
  set_long(
"This fine, plush office is very cosy and warm, with a large desk in \n"+
"the center of the spacious room. While designed for the chancellors \n"+
"own private study, it is also designed with interviews and entertaining\n"+
"guests.\n");

  set_weather(2, 1, 0);

  set_items(({
"desk",
"An enormous desk that appears to have been carved from a single piece \n"+
"of ancient white pine. It has been polished to such a sheen that you  \n"+
"can see your face reflected in its surface. In contrast to the office \n"+
"outside, this desk is spotlessly clean. Behind it stands a high backed chair",

"chair",
"The chair that stands behind the large desk of the chancellor is made \n"+
"from the same wood, and bears a gold and purple pillows and cushioned \n"+
"arm rests. Indeed it is a comfortable and expensive piece of office furniture",

  }));


  set_listen("All is quite and peaceful here.\n");
  set_smell("The air is rich with the smell of old leathery books.\n");

  set_exits(({
  }));
}


