#define SICKNESS    (random(20) + 1)
#define YOUR_CON    (random((int)this_player()->query_constitution()) + 1)
#define DMG         (random(5) + 1)   /* sea sickness damage */

#include <mudlib.h>
inherit ROOM;

void sea_sickness();
void make_inventory();
void reset(status arg) {
  int i;
  object ob;

  if(!present("sailor")) {
    for(i=0; i<random(3)+1; i++) {
      move_object(clone_object("/d/affils/ships/crew/sailor"), this_object());
    }
  }


  if(!present("locker")) {
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
  }

  if(!present("ballista")) {
    move_object(clone_object("/d/affils/ships/ballista"), this_object());
  }

  make_inventory();

  ::reset(arg);
  if(arg) return;

  set_short("the bounty");
  set_long(
     "You stand at the bow, the front of the Bounty, looking forward \n"+
     "in the direction of the great open sea. A ladderway leads down \n"+
     "to the lower decks from here, while the foremast, built from the \n"+
     "trunks of several large trees towers above you.\n");

  set_items(({
     "rigging", 
          "The rigging is a spider like web of rope leading up",
     "mast#foremast",
          "It is encircled with iron bands. The shorter of \n"+
          "the three masts on the ship stands 90 feet tall",
     "sea",
          "Just looking at it makes you feel a little sea sick",
     "ladderway",
          "A dark, narrow stairway leads downward",
  }));

  set_listen("You hear the sound of the waves pouncing the ship.\n");
  set_smell("The salt air accosts your senses.\n");
  set_weather(1, 4, 6);

  set_exits(({
     "/d/affils/ships/open/types/bounty/port", "port",
     "/d/affils/ships/open/types/bounty/s_board", "starboard",
/*
     "room/ships/open/types/bounty/hallway1", "down",
*/
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

void make_inventory() {
  object ob, obj;
  int i;

  ob = present("locker");
  if(!ob)  return; 

  if(present("ballista", ob)) return;

  for(i=0; i<5; i++) {
    obj = clone_object(WEAPON);
    obj -> set_name("ballista bolt");
    obj -> set_alias("bolt");
    obj -> set_short("A ballista bolt");
    obj -> set_long(
          "This ballista bolt is akin to a spear of some sort, with \n"+
          "a hard iron tip for piercing the sides of enemy sailing "+
          "ships.\n");
    obj -> set_weight(8);
    obj -> set_wc(2);         /* not really meant to be wielded */
    obj -> set_type("pierce");
    obj -> set_value(20);
    obj -> set_sell_destruct(1);
    move_object(obj, ob);
  }
}
