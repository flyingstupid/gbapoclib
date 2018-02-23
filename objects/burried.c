/* This room is to store all the burried items floating around the mud.
 * When someone burry's an item, a small mound of dirt will appear.
 * Items that were on the ground are then moved here for safe keeping.
 * When someone tries to dig items up, they will uncover a random item
 * from in this room.
 */


#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("a hole in the ground");
  set_long(
	"The walls of this place lead upward. . .\n");
  set_exits(({
	CHURCH, "up",
  }));

  set_weather(1, 0, 1);
}
