#define PATH	"/d/affils/ships/island"

#include <mudlib.h>
#define YOUR_CLIMB       random((int)this_player()->query_climb())
#define CLIMB_CHANCE     (random(6)+1) /* 1 to 6 */
#define NAME		(string)this_player()->query_name()

inherit ROOM;
void reset(status arg) {
  if(arg) return;

  set_short("Skol island");
  set_long(
     "A wreck of a ship lies here against the shore, while the waves \n"+
     "crash against it, eroding and decaying it further. The beach   \n"+
     "makes its way back down the coast of skol island to the east.  \n");

  set_weather(1, 4, 6);
  set_exits(({ 
	PATH+"/beach5", "east",
  }));
  set_listen("You hear the soothing sounds of the waves against the wreck.\n");
  set_smell("Sea salt is strong in the air here.\n");
  set_items(({
     "sand",  
          "Soft, yellow sand. It feels wonderful beneath your feet",
     "beach", 
          "A small beach which extends down the coast of the island",
     "waves#wave",
          "Strong waves crash against the hull of the wreck",
     "wreck",
          "A tall sailing ship which must have come to rest here after \n"+
          "some stormy sea years and years ago. Now, it is a simple wreck",
     "hull",
          "As the waves crash against the hull of the wreck you notice \n"+
          "a hole in its side. Perhaps you could enter inside?",
  }));

  set_search_array(({
     "sand#beach",
          "All you find is sand. Did you expect to find anything else?\n",
     "wreck#hull",
          "You won't find anything from here!\n",
  }));
}

void init() {
  ::init();
  add_action("enter", "enter");
}

status enter(string str) {
  if(!str) {
    write("Enter what?\n");
    return 1;
  }
  if(str != "hole" && str != "wreck" && str != "hull") return 0;
  if(CLIMB_CHANCE >YOUR_CLIMB) {
    write(
     "You don't seem to be skilled enough in climbing to \n"+
     "climb up into the hole, and slide back down.\n");
    say(NAME+" tries to climb into the wrecks hull, but slides back down.\n",
     this_player());
    return 1;
  }
  if(!this_player()->add_weight(5)) {
    write("You can't fit through the breach in the hull.\n"+
          "Perhaps you're carrying too much?\n");
    return 1;
  }
  write("You wriggle through the breach in the hull.\n");
  this_player()->move_player("into the breach in the hull#"+PATH+"/wreck1");
  return 1;
}


      
