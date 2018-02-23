#include <mudlib.h>
#include "paths.h"

inherit ROOM;

#define ELF 4 /* number of elves */

object *elves;

void reset(status arg) {
  int i;
  object elf, bs;

  if(!arg) {
    set_short("the forest");

    set_long(
"The forest of Scianthian is well protected by walls of trees, \n"+
"making any chance of attack on the creatures that live within it seem   \n"+
"almost impossible. ");

  set_day_desc(	    "Still, the sun shines through the gaps in the       \n"+
"canopy above, making all around you warm.\n");

  set_night_desc(   "Still, the stars shine through the gaps in the      \n"+
"canopy above, bathing all in a soft white glow.\n"); 

    set_exits(({
	ROADS+"forest10", "east",
	PATH+"new2", "north",
    }));
    set_weather(2,4,3);
    set_listen("You hear the sound of birds chirping.\n");
  }
 
  if(!elves) elves = allocate(ELF);
  for(i = 0; i < ELF; i++) {
    if(!elves[i]) {
      elf = clone_object(MONSTER);
      elf -> set_name("elf");
      elf -> set_race("elf");
      elf -> set_alias("fighter");
      elf -> set_short("An elfin fighter");
      elf -> set_long(
        "A short little elf.  He has pointy little ears and green eyes.\n"+
        "He is standing here, watching and caring for the forest. \n");
      elf -> set_level(1);
      elf -> set_ac(3);
      elf -> set_wc(5);
      elf -> set_gender(1);
      elf -> set_al(50);
      elf->set_plural("elven fighters");
      elves[i] = elf;
      move_object(elves[i], this_object());
    }
    if(!present("boots", elves[i])) {
      bs = clone_object(ARMOUR);
      bs -> set_name("boots");
      bs -> set_short("pointy elf boots");
      bs -> set_long(
        "A pair of green boots, with a long point at the toe.\n");
      bs -> set_ac(1);
      bs -> set_weight(5);
      bs -> set_value(60);
      bs -> set_armour_material("cloth");
      bs -> set_type("boots");
      move_object(bs, elves[i]);
      command("wear boots", elves[i]);
    }
  }
}
