#include <mudlib.h>
#include "paths.h"
inherit ROOM;


object fath, wp;
void reset(status arg) {
  
  if(!arg) {
    set_short("a tree");
    set_long(
"You are standing in the base of a large tree.  You were correct,\n"+
"someone does live in here. This part of the tree is very large and\n"+
"open. There is a small table in the middle of the floor.  There are\n"+
"several chairs in the room for someone to rest in.  There is a\n"+
"small window near you that is even with ground level, allowing you\n"+
"to see the nice green blades of grass. There is a stairway in the\n"+
"corner of the room.\n");

    set_exits(({
	PATH+"tree2", "up",
	PATH+"new6", "out",
    }));
    set_items(({
        "table",  "A small round wooden table",
        "chairs",  "Wooden chairs with soft cushions",
        "window",  "A small glass window used for viewing outside",
        "grass",   "Green blades of grass growin from the ground",
        "stairway", "A spiriling stairway that leads up into the tree",
    }));
    set_weather(2,3,4);
  }
  if(!present("father")) {
    fath = clone_object(MONSTER);
    fath->set_name("father");
    fath->set_alias("elf");
    fath->set_short("A father elf");
    fath->set_long(
          "A stout little elf.  He has a large robust \n"+
          "stomach, and large glaring eyes.\n");
    fath->set_level(4);
    fath->set_race("elf");
    fath->set_ac(4);
    fath->set_gender(1);
    fath->set_plural("father elves");
    fath->set_al(75);
    move_object(fath,this_object());
  }

  if(!present("whip", fath)) {
    wp = clone_object(WEAPON);
    wp->set_name("whip");
    wp->set_short("A small whip");
    wp->set_plural("small whips");
    wp->set_long(
           "A small black leather whip. What did the father want with it??\n");
    wp->set_wc(7);
    wp->set_weight(3);
    wp->set_value(160);
    wp->set_length(100);
    wp->set_type("slash");
    move_object(wp, fath);
    command("wield whip", fath);
    fath->set_wc(8);
  }
}
