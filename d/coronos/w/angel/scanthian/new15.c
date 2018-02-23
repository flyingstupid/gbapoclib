#include <mudlib.h>
#include "paths.h"
inherit ROOM;

#define ELF 3

object *elves;


void reset(status arg) {
   int i;
   object mas;

   if(!arg) {
      set_short("Hideout");
      set_long(
"You stand before the elven thieves hideout.  It is just a hole in the\n"+
"ground.  There is a wierd glow over the hole, that acts as the security\n"+
"system.  It is accurate 90 percent of the time, but sometimes it may make\n"+
"a mistake, and allow people to sneak by.\n");
      set_exits(({
	PATH+"new14", "south",
      }));
      set_weather(1,4,3);
      set_items(({
          "hole",  "A hole in the ground used as a hideout",
          "glow",  "A glowing circle of light",
      }));
   }

  if(!elves) elves = allocate(ELF);
  for(i = 0; i < ELF; i++) {
    if(!elves[i]) {
      mas = clone_object(MONSTER);
      mas->set_name("elf");
      mas->set_alias("master");
      mas->set_short("a master elf");
      mas->set_long(
"This is one of the master thief elves.  He is shorter than normal,\n"+
"skinnier than normal, and a lot quicker than normal guard your\n"+
"equipment well.\n");
      mas->add_class("thief");
      mas->set_level(4);
      mas->set_ac(4);
      mas->set_plural("master elves");
      mas->set_wc(8);
      mas->set_gender(1);
      mas->set_race("wood elf");
      mas->set_al(-50);
      move_object(mas, this_object());
      elves[i] = mas;
    }
  }
}


void init() {
  ::init();
   add_action("enter", "enter");
   add_action("sneak", "sneak");
}

status enter(string arg) {
  string tmp1, tmp2;
  string race;
   
  race = (string)this_player()->query_race();
  if(arg != "hideout") {
     notify_fail("Enter what??\n");
     return 0;
  }
  if((arg == "hideout") && 
     (!sscanf(race, "%self%s", tmp1,tmp2))) {
      write("You try to enter the hole, but you are trapped by light.\n");
      say(this_player()->query_name()+" fails to enter the hideout.\n",
          this_player());
      return 1;
  }
  write("You enter into the hideout.\n");
  this_player()->move_player("into the hideout#/room/newbie/hide1");
  return 1;
}

status sneak() {
  string tmp1, tmp2;
  string race;

  race = this_player()->query_race();
  if(sscanf(race, "%self%s", tmp1, tmp2)) {
    write("Theres no need to sneak, just enter the hideout.\n");
    return 1;
  }
  else if (random(25) < 5) {
    write("You successfully sneak into the hideout.\n");
    this_player()->move_player("into the hideout#/room/newbie/hide1");
    return 1;
  }
  else {
     write("You fail to sneak into the hideout.\n");
     say(this_player()->query_name()+" fails to sneak into the hideout.\n",
          this_player());
     return 1;
  }
}
