#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  object obj;
  if(!present("wand")) {
    obj = clone_object(WAND);
    obj -> set_name("stick");
    obj -> set_short("A pointy stick");
    obj -> set_long(
		"This stick is long and twisty and has a silver point.\n"+
		"It feels tingly to the touch; an obvious sign its more\n"+
		"than meets the eyes.\n");
    obj -> set_weight(2);
    obj -> set_alias("wand");
    obj -> set_sell_destruct(1);
   move_object(obj,this_object());
  }
  ::reset(arg);
  if(arg) return;
  set_name("gizarl");
