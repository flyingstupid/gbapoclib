/* Thief tunnel9 Angel Sept 1993 */
#define PATH	"d/coronos/w/angel/city/sewer/"

inherit "inherit/room2";

reset(arg) {
  if(arg) return;

  set_short("A dark damp tunnel beneath the city");
  set_long(
     "Water drips down the walls in this small round tunnel \n"+
     "that meanders it ways around underneath the city above.\n"+
     "Up ahead you see a light that shines into this tunnel. \n");

  set_items(({ "light#lights",     "A light shines into the tunnel "+
                                   "from up ahead.."
  }));

  set_exits(({ 
	PATH+"guild", "south",
	PATH+"tunnel8", "west",
  }));

  set_weather(0, 2, 0);
  set_listen("You hear the dripping of water off the walls...");
  set_smell("The air about you smells damp and musty...");
}
