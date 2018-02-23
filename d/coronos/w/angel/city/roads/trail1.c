#include <mudlib.h>
#include "paths.h"


string *drinkers;

inherit ROOM;


void reset(status arg) {

  drinkers = ({ });

  load_door(({
        "file", NEWBIE+"new6",
	"open",
        "direction", "trail",
        "long",
        "An animal trail that leads into the scanthian forest\n",
	"trail", 10,
        "secret door finders", ({}),
  }));





  if(arg) return;


  set_short("a game trail neaby a stream");

  set_long(
"A game trail makes its way through the underbrush, nearby a tall, \n"+
"humpbacked bridge to the north. Several animal tracks can be  \n"+
"clearly seen beside the banks of the stream. Light and smoke from \n"+
"a camp fire spill out toward you from the north.\n");


  set_weather(3,0,0);
  set_exits(({
	PATH+"stream", "north",
  }));

  set_items(({
	"tracks",
	"They seem to be on the run from something and move quickly south",

	"trail#game trail",
	"The game trail leads into the heavy underbrush",

	"underbrush",
	"It looks too thick to pass through",
	
	"bridge",
	"The bridge is made from sandstone, built from stones \n"+
	"crafted at a nearby quarry",

	"stream",
	"The stream looks like fresh water, probably running from the \n"+
	"icy peaks of Darken Mountain. Perhaps you could drink from it?",

	"fire",
	"The fire to the north looks recently lit",

	"cloud#clouds", "They are fluffy clouds. One looks like a donkey\n",
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

  if(random(ob->query_intelligence()) > 5)
    write("You feel as though someone is watching you.\n");

  say(this_player()->query_name(1)+" drinks from the stream\n");

  if(!random(10)) {
    this_player()->drink_soft(5);
    drinkers += ({ ob->query_name(1), });
  }

  return 1;
}

