#define SICKNESS    (random(20) + 1)
#define YOUR_CON    (random((int)this_player()->query_constitution()) + 1)
#define DMG         (random(5) + 1)   /* sea sickness damage */

#include <mudlib.h>
inherit ROOM;

void sea_sickness();
void reset(status arg) {
  object ob;
  int i;

  if(!present("sailor")) {
    for(i=0; i<random(3)+1; i++) {
      move_object(clone_object("/d/affils/ships/crew/sailor"),this_object());
    }
  }



  if(!present("locker")) {
    for(i=0; i<3; i++) {
      ob = clone_object(CONTAINER);
      ob -> set_name("locker");
      ob -> set_short("A foot locker");
      ob -> set_long(
          "A sturdy wooden foot locker with hinges of iron and locks   \n"+
          "of steel. It is designed to handle the rough weather of the \n"+
          "open seas. \n");
      ob -> set_weight(1000);
      ob -> set_value(100);
      ob -> set_closed(1);
      ob -> set_locked(1);
      ob -> set_lock_id("lock");
      ob -> set_key_id("iron key");
      move_object(ob, this_object());

      ob = clone_object("objects/torch");
      move_object(ob, present("locker"));      
      ob = clone_object("objects/rope");
      move_object(ob, present("locker"));      
    }
  }

  if(arg) return;

  set_short("the bounty");
  set_long(
     "A sturdy rail seperates you from the sea here on the port side of \n"+
     "the bounty. The rigging extends upward toward the main mast and a \n"+
     "few foot lockers that hold lanterns and wet weather gear sit beside "+
     "it.\n");

  set_items(({
     "rigging", 
          "The rigging is a spider like web of rope leading up",
     "main mast#mast",
          "The mast supports strong canvas sails above",
  }));

  set_listen("You hear the sound of the waves pouncing the ship.\n");
  set_smell("The salt air accosts your senses.\n");
  set_weather(1, 4, 6);

  set_exits(({
     "/d/affils/ships/open/types/bounty/bow", "bow",
     "/d/affils/ships/open/types/bounty/stern", "stern",
     "/d/affils/ships/open/types/bounty/s_board", "starboard",
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
