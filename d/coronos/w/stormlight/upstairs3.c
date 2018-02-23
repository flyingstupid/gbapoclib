#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
reset_doors(arg);
if (arg) return;

set_weather(1,1,0);

set_short("Upstairs Hallway");
set_long("The hallway here is much the same as the area by the top of the \n"+
       "stairs. Pictures line the walls, and there is a suit of ornamental \n"+
        "platemail armor standing here.\n");

set_items(({"pictures", "The pictures seem to be of the Gildentongue family.\n",
        "platemail#plate#mail", "The platmail is polished to a shine and looks to be a replica of \n"+
                         "something a Knight would wear, though not this glamourous.\n",
             }));

load_door(({
"destination", "/d/coronos/w/stormlight/upstairs4",
"direction", "south door",
"closed",
"description", "It is a sturdy oak door.\n",
"unlocked",
}));

}
