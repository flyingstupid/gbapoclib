#include <mudlib.h>
#include "paths.h"

inherit ROOM;

#define ELF 4 /* Number of elves */

object *elves;

void reset(status arg) {
  int i;
  object ring, sly;
  
  if(!arg) {
      set_short("the elfin forest");
      set_long(
"You are moving closer toward the elven thieves hideout.  It is said\n"+
"that only a special race of people can get inside the hideout.  If\n"+
"you aren't of that special race, perhaps you could sneak in.  If you\n"+
"were to try it, and failed, the punishment would be severe.\n");
      set_exits(({
	PATH+"new13", "south",
	PATH+"new15", "north",
       }));
      set_weather(1,3,4);
  }

  if(!elves) elves = allocate(ELF);
  for(i = 0; i < ELF; i++) {
    if(!elves[i]) {
      sly = clone_object(MONSTER);
      sly->set_name("elf");
      sly->set_short("a sly wood elf");
      sly->set_long(
"A small little thieving elf.  He is capable of moving in and out of\n"+
"places quickly without being caught.\n");
      sly->set_level(2);
      sly->set_plural("sly wood elves");
      sly->set_ac(3);
      sly->set_wc(6);
      sly->set_gender(1);
      sly->set_race("wood elf");
      sly->set_al(-50);
      move_object(sly, this_object());
      elves[i] = sly;
    }
  }
}

