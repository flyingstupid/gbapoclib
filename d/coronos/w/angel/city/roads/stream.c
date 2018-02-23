#include <mudlib.h>
#include "paths.h"

inherit ROOM;

string *drinkers;
object troll;
object gem;


void reset(status arg) {
  if(!troll) {
    troll = clone_object(MONSTER);
    troll -> set_name("troll");
    troll -> set_race("troll");
    troll -> set_short("an ugly mean troll");
    troll -> set_long(
	"The troll is nearly 9 feet tall with green bumby skin.\n"+
	"He smells very bad.\n");
    troll -> set_gender(2);
    troll -> set_aggressive(1);
    troll -> set_level(10);
    troll -> set_hp(175);
    troll -> set_wc(14);
    troll -> set_ac(8);
    troll -> add_money(700);
    move_object(troll, this_object());
  }
  if(present("troll") && !present("gem", troll)) {
    gem = clone_object("objects/components/gem");
    move_object(gem, troll);
  }


  drinkers = ({ }); /* reset the people who've had a drink */

  if(arg) return;

  set_short("a stream under the old humpbacked bridge");

  set_long(
"A large humpbacked bridge, made from sandstone, stands nearly 50 feet\n"+
"above you, spanning the deep channel of this small stream. A dirty \n"+
"blanket and a few other possessions lay beside a camp fire. It is  \n"+
"obvious that someone lives here. A small game trail leads south.   \n");


  set_weather(3,0,0);
  set_exits(({
	PATH+"trail1", "south",
	PATH+"hump",  "up",
  }));

  set_climb(10);
  set_fall_dam(10); /* it's a fairly long way */

  set_items(({
	"blanket",
	"The blanket is old and grey and is torn in some places",

	"sandstone",
	"A strong yellowish block of stone. It's a little mossy",

	"bridge",
	"The bridge is made from sandstone, built from stones \n"+
	"crafted at a nearby quarry",

	"stream",
	"The stream looks like fresh water, probably running from the \n"+
	"icy peaks of Darken Mountain. Perhaps you could drink from it?",

	"fire",
	"The fire looks recently lit",

	"cloud#clouds", "They are fluffy clouds. One looks like a cat\n",
 }));


  set_smell("It smells like a troll has been here.\n");
  set_listen("You hear a the sound of fresh running water.\n");
} 

void init() {
  ::init();
  add_action("drink", "drink");
}


/* this routine mimicks the drink.c code */
status drink(string str) {
  object ob;

  ob = this_player();

  if(ob->query_attack()) {
    notify_fail("You can't possible drink and fight at the same time!\n");
    return 0;
  }

  if(member_array(ob->query_name(1), drinkers) != -1) {
    notify_fail("You've already quenched your thirst\n");
    return 0;
  }

  write("You quench your thurst with water from the stream\n");
  say(this_player()->query_name(1)+" drinks from the stream\n");

  if(!random(10))
    this_player()->drink_soft(5);

  return 1;
}

