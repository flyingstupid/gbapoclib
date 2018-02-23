/* Thief tunnel15 Angel Sept 1993 */
#define PATH	"d/coronos/w/angel/city/sewer/"

inherit "inherit/room2";

reset(arg) {
  if(!present("zilanthiuz")) {
    move_object(clone_object(PATH+"zil"), this_object());
  }

  if(arg) return;

  set_short("A dark damp tunnel beneath the city");
  set_long(
     "Water drips down the walls in this small round tunnel \n"+
     "that meanders it ways around underneath the city above.\n");

  set_items(({ 
     "water#walls#wall", "Water drips down the blackened walls" 
  }));

  set_exits(({ 
	PATH+"tunnel14", "south",
  }));

  set_weather(0, 2, 0);
  set_listen("You hear the dripping of water off the walls...");
  set_smell("The air about you smells damp and musty...");
}
