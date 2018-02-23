#include <mudlib.h>
inherit ROOM;

void reset (status arg) {
if (arg) return;

set_short("Foyer of the Home of Sartan Gildentongue");
set_long("The foyer to this house is small and tidy. A braided rug \n"+
"covers the floor here and a small table with a lanturn \n"+
"sits in the corner. Several windows look out onto the busy\n"+
"street. A set of stairs leads up to the upstairs and there\n"+
"is an archway to the south leading into another room.\n");

set_weather(2,1,0);

set_exits(({"d/coronos/w/stormlight/house2.c", "south",
            "d/coronos/w/stormlight/upstairs1.c", "upstairs",
            }));

set_items(({"rug", "The rug is oval in shape and made from the braids of \n"+
          "thick, cord like fabric.\n",
            "table", "It is a small, round wooden table, just big enough for the lanturn.\n"}));

set_day_items(({"lanturn", "The lanturn is sitting on the table with it's shutters closed.\n"}));

set_night_items(({"lanturn", "The lanturn's shutters are open, basking the room in a soft light.\n"}));


}

