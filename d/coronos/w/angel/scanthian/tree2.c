#include <mudlib.h>
#include "paths.h"

inherit ROOM;


object moth, am;
void reset(status arg) {

  if(!arg) {
    set_short("a tree");
    set_long(
"You are in what appears to be the sleeping quarters. The beds are neatly \n"+
"made and tucked tightly.  \n");
     set_exits(({
	PATH+"tree1", "down",
	PATH+"tree3", "up",
     }));

     set_items(({
       "bed",   "A small comfortable looking bed",
     }));
     set_weather(2,4,3);
   }
  if(!present("mother")) {
    moth = clone_object(MONSTER);
    moth->set_name("mother");
    moth->set_alias("elf");
    moth->set_short("a mother elf");
    moth->set_plural("mother elves");
    moth->set_long(
"A cute little mother elf.  She has a nice little body, and her ears \n"+
"are pointed just the right amount to drive a male elf wild.\n");
    moth->set_level(3);
    moth->set_ac(4);
    moth->set_wc(7);
    moth->set_gender(2);
    moth->set_al(100);
    moth->set_race("grey elf");
    move_object(moth,this_object());
  }

  if(!present("amulet", moth)) {
    am = clone_object(ARMOUR);
    am->set_name("amulet");
    am->set_short("A bark amulet");
    am->set_plural("back amulets");
    am->set_long(
"A small amulet made out of tree bark. It has the picture of \n"+
"two little children in the center of it.\n");
    am->set_ac(1);
    am->set_weight(4);
    am->set_value(90);
    am->set_type("amulet");
    am->set_armour_material("leather");
    move_object(am, moth);
    command("wear amulet", moth);
  }
}

