#include <mudlib.h>
#include "path.h"

inherit ROOM;

void reset(status arg) {
  string *smells;
  object troll, rags, club;

  /* taken from the original troll from 2.4.5 */
  if(!troll) {
    troll = clone_object(MONSTER);
    troll -> set_level(9);
    troll -> set_name("troll");
    troll -> set_race("troll");
    troll -> set_aggressive(1);
    troll -> set_short("A large troll");
    troll -> set_long(
	"This troll is tall and green and looks very hungry.\n");
    troll -> set_wc(12);
    troll -> set_ac(6);
    troll -> add_money(random(500));
    troll -> set_alignment(-60);
    troll -> set_gender(2);
    troll -> add_class("thief");
    troll -> add_class("fighter");
    move_object(troll, this_object());
  }

  if(!present("rags", troll)) {
    rags = clone_object(CLOTHING);
    rags -> set_name("rags");
    rags -> set_short("some rags");
    rags -> set_long(
	"They look smelly and dirty.\n");
    rags -> set_value(5);
    rags -> set_weight(1);
    move_object(rags, troll);
    command("wear rags", troll);
  }

  if(!present("club", troll)) {
    club = clone_object(WEAPON);
    club -> set_name("club");
    club -> set_short("A wooden club");
    club -> set_long(
	"While little more than a large tree branch, this club has \n"+
	"small pieces of rusty metal sticking out of it's sides.\n");
    club -> set_type("crush");
    club -> set_wc(9);
    club -> set_length(36);
    club -> set_weight(6);
    club -> set_value(260);
    move_object(club, troll);
    command("wield club", troll);
    troll -> set_wc(12);
  }


  if(arg) return;

  smells = ({
	"The air is fresh and cool.\n",
	"The air is cold against your skin.\n",
	"The cool air gives you goosebumps.\n",
	"The air smells of pine.\n",
	"The air smells sweet and crisp.\n",
	"The air smells fresh.\n",
  });

  set_smell(smells[random(sizeof(smells)-1)]);
  set_short("scianthian forest");

  set_long(
"A small wooden bridge spans a creek that runs through this \n"+
"part of the forest. A few large boulders at it's side mark \n"+
"something that appears to be a small shelter.\n");

  set_weather(1, 1, 0);
  
  set_items(({
	"trees", "The trees stand over 50 feet tall",
	"undergrowth", "The undergrowth is very wild in this forest",

	"shelter#rocks#rock",
	"The few rocks have been placed there to form a small shelter.\n"+
	"Perhaps someone lives inside?\n",

	"creek",
	"The creek runs under the bridge, and looks icy cold.\n",

	"bridge",
	"A small foot bridge that spans the creek",
  }));


  set_exits(({
	PATH+"clearing", "east",
	PATH+"slope",    "west",
  }));
}
