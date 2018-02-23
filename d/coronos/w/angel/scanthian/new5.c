#include <mudlib.h>
#include "paths.h"
inherit ROOM;

#define ELF 4

object *elves;

void reset(status arg) {
  int i;
  object welf;
  object axe;
  
  if(!present("tree")) {
    welf = clone_object("obj/skills/tree");
    move_object(welf, this_object());
    welf -> grow();
  }

  if(!arg) {
    set_short("the elfin forest");
    set_long(
       "You are still in the forest.  Large trees  surround you on every \n"+
       "side. There is a sense of peace in this place. You look up and   \n"+
       "watch the trees disappear in the mist that drapes the top of the \n"+
       "trees.  There is a small cabin just up ahead.\n");

     set_exits(({
	PATH+"new3", "south",
	PATH+"new7", "north",
     }));

     set_items(({
       "trees",  "Large oak trees",
       "cabin",  "A small log cabin to the north",
     }));
    set_weather(2,4,0);
  }

  if(!elves) elves = allocate(ELF);
  for(i = 0; i < ELF; i++) {
    if(!elves[i]) {
      welf = clone_object(MONSTER);
      welf->set_name("elf");
      welf->set_short("a wood elf");
      welf->set_plural("wood elves");
      welf->set_long(
          "One of the wood elves that live in the forest.  He has skills \n"+
          "in carpentry and carving.  Due to his profession, he is slightly\n"+
          "larger than the other elves, and stronger.\n");
      welf->set_level(3);
      welf->set_ac(7);
      welf->set_wc(7);
      welf->set_gender(1);
      welf->set_race("elf");
      welf->set_al(50);
      move_object(welf, this_object());
      elves[i] = welf;
    }
    if(!present("axe", elves[i])) {
        axe = clone_object(WEAPON);
        axe->set_name("axe");
        axe->set_short("an axe");
        axe->set_long(
          "A small axe, used for cutting wood.  The handle is wood, and \n"+
          "the blade is made from iron.\n");
        axe->set_wc(8);
        axe->set_plural("axes");
        axe->set_weight(4);
        axe->set_value(275);
        axe->set_type("cleave");
        axe->query_type();
        axe->set_length(30);
        move_object(axe, elves[i]);
        command("wield axe", elves[i]);
    }
  }
}



