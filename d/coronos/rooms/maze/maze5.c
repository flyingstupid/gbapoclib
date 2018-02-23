#include "path.h"
#include <mudlib.h>

inherit ROOM;

int exit_num;
object leather;

void reset(status arg) {
  if (!leather || !present(leather)) {
	leather = clone_object(ARMOUR);
	leather -> set_ac(1);
      leather -> set_weight(3);
      leather -> set_type("armour");
      leather -> set_name("leather armour");
      leather -> set_short("A suit of leather armour");
      leather -> set_long(
		"A simple suit of leather armour. While it \n"+
		"looks a little old in its style, it seems \n"+
		"in reasonable condition.\n");
      leather -> set_armour_material("leather");
      leather -> set_value(400);
	move_object(leather, this_object());
  }

  move_object(clone_object(PATH+"toy"), this_object());


  if(arg) return;
  set_short("a dark tunnel");

  set_long(
	"The series of dark tunnels comes to a dead end here.\n");

  set_smell("The air is quite chill here.\n");

  set_exits(({
	PATH+"maze4", "south",
  }));

  set_weather(0, 1, 0);
}
