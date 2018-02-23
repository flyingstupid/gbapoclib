#include <mudlib.h>
inherit ROOM;

status dagger_gotten;

void reset (status arg) {
dagger_gotten = 0;

set_short("Kitchen of Sartan Gildentongue");
set_long("This is obviously the kitchen. A large brick oven stands \n"+
"against the west wall, while tables covered in all manner of \n"+
"utensils, lay scattered about. There is a light coating of flour \n"+
"on the floor, and the heat is immense. Shelves and cabinets \n"+
"bulge with foodstuffs.\n");

set_smell("The scent of roast duck is strong here.");

set_listen("You'd swear you could hear someone whistling.\n");

set_items(({"oven", "The oven is a large brick monstrosity. Several logs burn in it \n"+
                   "constantly for cooking and to provide heat to the house. A large \n"+
                  "duck slowly roasts on a spit over the flames.\n",
            "flour", "The flour has obviously been spilled onto the floor.\n",
            "table#tables", "The tables are large and made from oak. Several knicks and \n"+
                  "scratches cover they're surfaces along with different types of \n"+
                    "cooking instruments.\n",
             "duck", "Yum, it's almost done!\n",
            }));

set_weather(1,1,0);

set_exits(({"d/coronos/w/stormlight/house2.c", "east",
            }));
}

void init() {
:: init();
add_action("dag_cup", "get");
}

status dag_cup(string str) {
if (str == "dagger from cabinet") {
if (dagger_gotten != 0) {
write("The dagger is not here.\n");
return 1;
}
write("You peek in and slip the dagger out of the cabinet.\n");
say(this_player()->query_name()+" takes a dagger from the cabinet.\n",
this_player());
move_object( clone_object( "/players/stormlight/lsword.c"), this_player());
dagger_gotten = 1;
return 1;
}
else {
write ("Get What?\n");
return 1;
}
}



