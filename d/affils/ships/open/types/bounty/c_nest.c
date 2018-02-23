#define SICKNESS    (random(20) + 1)
#define YOUR_CON    (random((int)this_player()->query_constitution()) + 1)
#define DMG         (random(5) + 1)   /* sea sickness damage */

#include <mudlib.h>
inherit ROOM;

void sea_sickness();
void reset(status arg) {
  object ob;
  if(!present("sailor")) {
    ob = clone_object("/d/affils/ships/crew/sailor");
    move_object(ob, this_object());
  }
  if(arg) return;

  set_short("the bounty");
  set_long(
     "You stand in the crows nest, high above the bounty, amid the    \n"+
     "few birds that sit here, atop the main mast. You can see almost \n"+
     "everything from this fine vantage point. The rigging leads down \n"+
     "from here to the stern.\n");

  set_items(({
     "rigging", 
          "The rigging is a spider like web of rope leading down",
     "birds#bird",
          "An albatross sits here",
     "main mast#mast",
          "The mast supports the crows nest",
  }));

  set_listen("You hear the sound of the waves pouncing the ship.\n");
  set_smell("The salt air accosts your senses.\n");
  set_weather(1, 4, 6);
  set_climb(8);
  set_fall_dam(10);

  set_exits(({
     "/d/affils/ships/open/types/bounty/stern", "down",
  }));
}

void init() {
  ::init();
  call_out("sea_sickness", 1);
}

void sea_sickness() {
  if(SICKNESS > YOUR_CON) {
    write("You feel a little sea sick.\n");
    this_player()->adj_hp(DMG);
  }
}
