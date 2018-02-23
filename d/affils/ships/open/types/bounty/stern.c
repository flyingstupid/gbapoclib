#define PATH	"d/affils/ships/open/types/bounty"
#define SICKNESS    (random(20) + 1)
#define YOUR_CON    (random((int)this_player()->query_constitution()) + 1)
#define DMG         (random(5) + 1)   /* sea sickness damage */

#include <mudlib.h>
inherit SHIPS;

void sea_sickness();
void reset(status arg) {
  if(!present("bligh")) {
    move_object(clone_object("d/affils/ships/crew/bligh"),this_object());
  }

  ::reset(arg);
  if(arg) return;

  set_ship_name("bounty");
  set_captain("Bligh");
  set_ship_speed(1);

  set_short("the Bounty");
  set_long(
     "You stand at the sterncastle of the bounty where a flag bearing \n"+
     "the symbol of Tempus hangs over the sea, fluttering in the breeze.\n"+
     "Several ropes stand coiled by the rails, and rigging fan out toward\n"+
     "the masts above.\n");

  set_items(({
     "flag", "It flutters in the breeze",
     "symbol", "The coat of arms of Tempus city",
     "rope#ropes", "Several coils of rope sit by the railing",
     "rigging", 
          "The rigging is a spider like web of rope extending toward \n"+
          "the masts and crows nest above. Perhaps you could climb it?",
     "rail#rails#railing",
          "Its main purpose it to stop you from falling overboard. It \n"+
          "is crafted from a fine red wood.\n",
  }));

  set_listen("You hear the sound of the waves pouncing the ship.\n");
  set_smell("The salt air accosts your senses.\n");
  set_weather(1, 4, 6);
  set_climb(8);
  set_fall_dam(10);

  set_ports(({
	"ille coronos", "minos", "skol island", "isle of sorcery",
	"griffin",
  }));

  set_exits(({
	PATH+"/c_nest", "up",
	PATH+"/port", "port",
	PATH+"/s_board", "starboard",
	"d/coronos/w/angel/city/docks/dock1", "gang plank",
  }));
}

void init() {
  ::init();
  call_out("sea_sickness", 1);
}

void sea_sickness() {
  if(SICKNESS > YOUR_CON) {
    write("You feel a little sea sick.\n");
    this_player()->adj_hp(DMG);
  }
}
