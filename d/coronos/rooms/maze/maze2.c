#include "path.h"
#include <mudlib.h>

inherit ROOM;

int exit_num;

void reset(status arg) {
  exit_num = random(4);	/* "grin" */

  if(arg) return;

  set_short("a dark tunnel");
  set_long(
	"The tunnels beneath the city are like a maze; you're \n"+
	"certain you've seen these icy cold walls before.\n"+
	"There are four obvious exits: north, south, west and east.\n");

  set_weather(0, 1, 0);
  custom_exits = "";
  set_smell("The air is icy cold here.\n");
}


string short(status wiz) {
  string sh, ex;

  sh = ::short(wiz);
  if(this_player()->query_brief())
  ex = "There are four obvious exits: n, s, e, w.\n";

  if(ex) {
    write(ex);
    sh += ex;
  }

  return sh;
}

void init() {
    ::init();
    add_action("e0"); add_verb("north");
    add_action("e1"); add_verb("south");
    add_action("e2"); add_verb("east");
    add_action("e3"); add_verb("west");
}

status e0() {
    if (exit_num == 0)
        call_other(this_player(), "move_player", "north#"+PATH+"maze3");
    else
        call_other(this_player(), "move_player", "north#"+PATH+"maze1");
    return 1;
}

status e1() {
    if (exit_num == 1)
	call_other(this_player(), "move_player", "south#"+PATH+"maze3");
    else
	call_other(this_player(), "move_player", "south#"+PATH+"maze1");
    return 1;
}

status e2() {
    if (exit_num == 2)
	call_other(this_player(), "move_player", "east#"+PATH+"maze3");
    else
	call_other(this_player(), "move_player", "east#"+PATH+"well");
    return 1;
}

status e3() {
    if (exit_num == 3)
	call_other(this_player(), "move_player", "west#"+PATH+"maze3");
    else
	call_other(this_player(), "move_player", "west#"+PATH+"well");
    return 1;
}

