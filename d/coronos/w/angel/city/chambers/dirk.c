#include <mudlib.h>
#define NAME	(string)this_player()->query_name()


inherit ROOM;

void reset(status arg) {
  object ob;

  if(!present("board")) {
    ob = clone_object(BULLETIN_BOARD);
    ob -> set_name("board");
    ob -> set_long(
	"This board is for posting of criminal activities.\n");
    ob -> set_save_file("ob_saves/boards/dirk_board");
    move_object(ob, this_object());
  }
  reset_doors(arg);
  load_door(({
	"direction", "south door",
	"file", "d/coronos/w/angel/city/chambers/pkoffice",
	"description",
	"A fine door with a poster of the Dirk's captain pinned to it.\n",
  }));

  if(arg) return;
  set_weather(2, 0, 0);
  set_short("the office of the Dirk");
  set_long(
"You are standing in the inner office of the Dirk, a lance \n"+
"of the Black Guard. A few desks are arranged through out  \n"+
"the room. A massive map of the lands of the kingdom covers\n"+
"the back wall. On the side wall is a large map of Ille Coronos\n"+
"with pins marking several sites. The door is covered in a mural\n"+
"of a large and pitch black dirk. On the back of the door is a \n"+
"dart board with the Captain's picture on it. \n");

  set_items(({
	"desk#desks",
	"The desks are made from a black oak, and look very stable.\n",

	"wall#back wall",
	"There's a large map there.\n",

	"map",
	"Perhaps you can read it?\n",

	"pin#pins", "They highlight black spots around the city.\n",
	"mural", "It covers the door",
	"door", "It's made of oak, like the desks in the room.",
	"mural",
	"A special mural designed by one of the local artists. It \n"+
	"is a simple dirk of human design, made from a black metal,\n"+
	"most probably adamantite.\n",
	"dart board",	
	"It has the picture of the Captain of the dirk on it.\n"+
	"One dart is stuck in his forehead",
  }));

  set_listen("The room is odly quiet. Perhaps the Dirk have gone to "+
	"catch a criminal?\n");


  set_smell("It smells like ink and paper in here.\n");
}

void init() {
  ::init();
  add_action("read_it", "read");
  add_action("get_it", "get");
  add_action("get_it", "take");
}

status get_it(string str) {
  string tmp1, tmp2;
  if(sscanf(str, "%sdart%s", tmp1, tmp2)) {
    write("It appears to be really wedged good and tight into the board.\n");
    return 1;
  }
  return 0;
}


status read_it(string str) {
  object ob;
  if(!str || str != "map") return 0;

  write("You read the map...\n\n");
  say(NAME+" reads the map on the wall.\n");

  ob = clone_object(MORE_OB);
  move_object(ob, this_player());
  ob -> more("/d/coronos/w/angel/map.txt");
  return 1;
}
