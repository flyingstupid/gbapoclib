/* The Void.
 * This room must not inherit any file, as it is the default room if anything
 * happens to the mudlib. Atleast this way, players won't screw up the mud
 * by logging into room code that is bugged.
 * Hence, there will always be one default room we can go to
 */

#include <player.cfg>


void reset(status arg) {
  if(arg) return;
  set_light(5);
}



string short(status wiz) {
  return "The Void";
}

void long(status wiz) {
  write(
	"You are in a dark and endless void, spiraling downward \n"+
	"in a cascade of energy toward a familiar place below...\n"+
	"Obvious exits: square.\n");
}

void init() {
  add_action("square", "square");
}

status square() {
  if(catch(call_other(DEFAULT_ENTER, "????"))) {
    write("There is an error with the room file code.\n"+
	"Please find a creator to fix it!\n");
    return 1;
  }
  write("You fall endlessly down toward Tempus...\n\n");
  this_player()->move_player("X#"+ DEFAULT_ENTER);
  return 1;
}

