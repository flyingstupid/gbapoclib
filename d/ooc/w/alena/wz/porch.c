#include <mudlib.h>
inherit ROOM;

void reset(status arg) {

    if(arg) return;

    set_long(
"Porch leading into the wizard beachhouse.\n"+
      "Change this later.\n");

set_short("the front porch");
    set_weather(2,2,0);

    set_night_desc(
      "A little light shines out from the windows.\n");
    set_items(({
	"floor#hardwood floor",
	"A standard hardwood floor that shows years of use.",
      }));

    set_exits(({
"/d/ooc/w/alena/wz/rm1","enter",
"/d/ooc/w/alena/wz/stairs1", "stairs",
      }));

    set_smell("A salty smell rising from the waters.\n");
    set_listen("The rushing of waves hitting the beach as well as \n"+
      "laughter coming from within the beachhouse.\n");

    set_ooc_room(1);
}
/* Lena, Sept 25, 1996 */
