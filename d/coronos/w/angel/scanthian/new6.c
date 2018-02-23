#include <mudlib.h>
#include "paths.h"
inherit ROOM;

#define ELF 3

object *elves;


void reset(status arg) {
  int i;
  object glv, telf;
  
  load_door(({
	"file", ROADS+"trail1",
	"open",
        "direction", "trail",
        "long",
        "An animal trail that leads into the scanthian forest\n",
	"trail", 10,
        "secret door finders", ({}),
  }));



  if(!arg) {
    set_short("the elfin forest");
    set_long(
"You are standing before a large oak tree.  Its far larger than     \n"+
"any of the other trees in the forest. Its branches seem to reach   \n"+
"up into the sky for miles. This tree is so big someone or something \n"+
"could live in it.\n");
 
   set_exits(({
	PATH+"new3", "west",
    }));
    set_items(({
        "tree",   "A large oak tree. One of the branches seems strange",
        "branch", "An oak branch. The base seems to have a pivot for twisting",
    }));
    set_weather(2,4,3);
  }
  if(!elves) elves = allocate(ELF);
  for(i = 0; i < ELF; i++) {
    if(!elves[i]) {
      telf = clone_object(MONSTER);
      telf->set_name("elf");
      telf->set_short("a wood elf");
      telf->set_long(
          "A small little wood elf. She has pointy ears, and small feet.\n");
      telf->set_level(2);
      telf->set_ac(3);
      telf->set_wc(6);
      telf->set_al(50);
      telf->set_gender(2);
      telf->set_race("wood elf");
      telf->set_plural("wood elves");
      move_object(telf, this_object());
      elves[i] = telf;
    }
    if(!present("gloves", elves[i])) {
        glv = clone_object(ARMOUR);
        glv->set_name("gloves");
        glv->set_short("A pair of bark gloves");
        glv->set_plural("pairs of bark gloves");
        glv->set_long(
               "A pair of gloves made from the soft bark of a pine tree.\n");
        glv->set_ac(1);
        glv->set_weight(5);
        glv->set_value(60);
        glv->set_type("gloves");
        glv->set_armour_material("leather");
        move_object(glv, elves[i]);
        command("wear gloves", elves[i]);
    } 
  }
}

void init() {
  ::init();
  add_action("twist", "twist");
}

status twist(string arg) {
   if(arg != "branch") return 0;
   write("You twist the branch, and a trapdoor opens under you.\n");
   say(this_player()->query_name()+" twists the branch.\n",this_player());
   this_player()->move_player("through a trapdoor#/room/newbie/tree1");
   return 1;
}

