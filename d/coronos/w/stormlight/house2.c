#include <mudlib.h>
inherit ROOM;

void reset (status arg) {
if (arg) return;

set_short("Living Area");
set_long("This room is larger then the foyer and just as tidy. The room \n"+
"is furnished with a simple table, a couch and a large chair. \n"+
"There is a fireplace on the south wall. The floor boards creak \n"+
"slightly as you walk through here. There are archways leading \n"+
"to the north and west.\n");

set_smell("You catch the scent of roasted duck.\n");

set_listen("You can swear you hear someone whistling\n");

set_exits(({"d/coronos/w/stormlight/house1.c", "north",
            "d/coronos/w/stormlight/house3.c", "west",
            }));

set_weather(1,1,0);

set_items(({"couch", "It is a simple leather couch, it doesn't look as though \n"+
                     "it has seen much use.\n",
            "chair", "It is a large, overstuffed chair. It looks as though a very \n"+
                    "robust individual uses it.\n",
            "table", "The table is a simple wooden table standing 3' high. On it's \n"+
                      "surface you see a small scratch.\n",
            "scratch", "The scratch is real faint but looks to be an arrow pointing \n"+
                    "towards the fireplace.\n",
            "fireplace", "The fireplace is made from rough cut stone. It doesn't look \n"+
                     "as though it has been used recently. In fact you'd swear you \n"+
                      "can make out a foot print in the soot.\n"
             }));

}


void init() {
::init();
add_action("climb1", "climb");
}

status climb1(string str) {
if (str != "into fireplace") {
write("\nClimb into what?\n\n");
return 1;
}
if (str == "into fireplace") {
write("\nYou get on your hands and knees and climb into the fireplace.\n\n");
say(this_player()->query_name()+ " climbs into the  fireplace.\n\n", this_player());
call_out("climb2", 1);
return 1;
}
}


void climb2() {
write("\n\nOnce inside you find that there is enough room to stand.\n\n\n");
this_player()->move_player("", "d/coronos/w/stormlight/fireplace");
return;
}

