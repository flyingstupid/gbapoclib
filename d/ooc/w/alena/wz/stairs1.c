#include <mudlib.h>
inherit ROOM;

void reset(status arg) {

    if(arg) return;

    set_long(
      "Bottom of the stairs.\n"+
      "Change this later.\n");

    set_short("base of some stairs");
    set_weather(2,2,0);

    set_night_desc(
      "A little light shines down from the windows above.\n");
    set_items(({
	"floor#hardwood floor",
	"A standard hardwood floor that shows years of use.",
      }));

    set_exits(({
	"/d/ooc/w/alena/wz/porch","stairs",
      }));

    set_smell("A salty smell rising from the waters.\n");
    set_listen("The rushing of waves hitting the beach as well as \n"+
      "laughter coming from within the beachhouse.\n");

    set_ooc_room(1);
}
/* Lena, Sept 25, 1996 */
