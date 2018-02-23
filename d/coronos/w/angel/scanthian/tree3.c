#include <mudlib.h>
inherit ROOM;

  object by, grl, ts, doll;
void reset(status arg) {
  
     set_short("a tree");
     set_long(
"You are standing in the children's room.  There are lots of toys lying \n"+
"on the floor. There are two very tiny beds in the room.  The walls have\n"+
"been covered with pink bunnies, and the curtains are also pink. Must be\n"+
"girls.\n");
    set_exits(({
       "room/newbie/tree2",  "down",
       "room/newbie/tree4",  "stairs",
      }));
      set_items(({
          "beds",   "Two small beds with pink covers",
          "walls",  
               "Wooden walls carved out of the oak covered with pink bunnies",
      }));
      set_weather(2,4,3);

  if(!present("boy")) {
    by = clone_object(MONSTER);
    by->set_name("boy");
    by->set_alias("elf");
    by->set_short("a boy elf");
    by->set_plural("boy elves");
    by->set_long(
    "A little boy elf.  He about 5 years old, and stand only 3 ft high.\n");
    by->set_level(2);
    by->set_ac(3);
    by->set_wc(6);
    by->set_gender(1);
    by->set_race("grey elf");
    by->set_al(25);
    move_object(by, this_object());
  }

  if(!present("girl")) {
    grl = clone_object(MONSTER);
    grl->set_name("girl");
    grl->set_alias("girl");
    grl->set_short("a girl elf");
    grl->set_long(
    "A little girl elf.  She's about 3 ft tall, and as cute as a button.\n");
    grl->set_level(2);
    grl->set_ac(3);
    grl->set_wc(6);
    grl->set_gender(2);
    grl->set_al(25);
    grl->set_plural("girl elves");
    grl->set_race("grey elf");
    move_object(grl, this_object());
  }

  if(!present("doll", grl)) {
    doll = clone_object(TREASURE);
    doll->set_alias("doll");
    doll->set_short("A cute little baby doll");
    doll->set_plural("cute little baby dolls");
    doll->set_long(
    "A doll of a little baby elf, dress in a pink skirt.\n");
    doll->set_value(60);
    move_object(doll, grl);
  }
}
