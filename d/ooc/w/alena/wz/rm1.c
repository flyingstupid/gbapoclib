#include <mudlib.h>
inherit ROOM;

void reset(status arg) {

    if(arg) return;

    set_long(
      "Front hallway of the wizard beachhouse.\n"+
      "Change this later.\n");

    set_short("the front hallway");
    set_weather(2,2,0);

    set_items(({
	"floor#hardwood floor",
	"A standard hardwood floor that shows years of use.",
      }));

    set_exits(({
	"/d/ooc/w/alena/wz/porch", "out",
      }));

    set_smell("A salty smell coming off the waters.\n");
    set_listen("A soft creaking noise is heard with each step and the \n"+
      "sound of voices seem to come from every direction.\n");

    set_ooc_room(1);
}
/* Lena, Sept 25, 1996 */
