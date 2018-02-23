#include <mudlib.h>
#define PATH	"d/coronos/w/angel/city/gardens/"
#define MONST   "d/coronos/w/angel/city/monst/"
inherit ROOM;
void reset(status arg) {
  object obj;
  if(!present("koala")) {
    obj = clone_object(MONST+"koala");
    move_object(obj,this_object());
  }
  if(arg) return;
  set_weather(1,3,0);
  set_short("a tree");
  set_long(
    "From the dizzy heights of the gum tree the ground below seems \n"+
    "a dangeous place, compared to the warmth and protection of the\n"+
    "leaves here. The tree trunk is a strange grey, almost white and\n"+
    "the leaves a strange sweet smell.\n");
  set_smell("The gum leaves smell of eucalyptuse.\n");
  set_exits(({
	PATH+"tree2", "up",
	PATH+"garden8", "down",
  }));
}

void init() {
  ::init();
  add_action("down", "down");
}

status down() {
  if((string)this_player()->query_name() == "koala") return 1;
  return 0;
}
