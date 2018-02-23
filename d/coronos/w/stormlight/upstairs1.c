#include <mudlib.h>
inherit ROOM;

void reset (status arg) {
reset_doors(arg);
if (arg) return;


set_short("Upstairs in Sartan Gildentongue's house.");

set_long("You stand in a short hallway. Several pictures line the \n"+
        "walls. The hall continues further down and you think you \n"+
        "you can see a large shape down at the end.\n");

set_weather(1,0,0);

set_exits(({"/d/coronos/w/stormlight/house1.c", "down",
            "/d/coronos/w/stormlight/upstairs3.c", "hall",
         }));



set_items(({"pictures#picture", "The picture are portraits of what appears to be members of the \n"+
           "Gildentongue family.\n",
            "shape", "You can barely make it out, but it looks humanoid.\n",
           }));


load_door(({
"destination", "/d/coronos/w/stormlight/upstairs2.c",
"direction", "south door",
"description", " It's a simple wooden door.",
"unlocked",
}));

}


