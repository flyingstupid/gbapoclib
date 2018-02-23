#include <mudlib.h>

#define YOUR_CLIMB       random((int)this_player()->query_climb())
#define CLIMB_CHANCE     (random(6)+1) /* 1 to 6 */

inherit ROOM;
void reset(status arg) {
  object barrel, money, lamp, food, cloth, chest;
  int i, j;

  if(!present("barrel")) {
    for(i=0; i<3; i++) {
      barrel = clone_object(CONTAINER);
      barrel -> set_name("barrel");    
      barrel -> set_short("A barrel");
      barrel -> set_long("An old sea barrel.\n");
      barrel -> set_smell("It smells musty and smelly.\n");
      barrel -> set_listen("Barrels don't usually make any noise.\n");
      barrel -> set_max_weight(10);
      barrel -> set_container_weight(8);
      barrel -> set_closed(1);
      barrel -> set_sell_destruct(1);
      barrel -> set_value(200);
      move_object(barrel, this_object());

      for(j=0; j<3; j++) {
        food = clone_object(FOOD);
        food -> set_name("sea biscut");
        food -> set_alias("biscut");
        food -> set_smell("It even smells like the sea!\n");
        food -> set_sell_destruct(1);
        food -> set_weight(1);
        food -> set_strength(10);
        food -> set_room_msg( 
          "@@query_name:$this_player()$@@ munches on a biscut.\n");
        food -> set_consumer_msg(
          "The biscut tastes rather salty and dry, but it quite filling.\n");
        food -> set_short("A sea biscut");
        food -> set_long("An old, stale, sea biscut, only fit for rats.\n");
        move_object(food, barrel);
      }
      move_object(clone_object("objects/head"), barrel);
    }
  }

  if(!present("chest")) {
    chest = clone_object(CONTAINER);
    chest -> set_name("chest");
    chest -> set_container_weight(1000);  /* don't want this one taken      */
    chest -> set_max_weight(18);          /* about 2 swords and some armour */
    chest -> set_short("A sea chest");
    chest -> set_long(
          "The sea chest is bound in strong metal and has a sturdy lock.\n");
    chest -> set_closed(1);
    chest -> set_locked(1);
    chest -> set_lock_id("lock");
    chest -> set_lock_desc("A sturdy iron lock");
    chest -> set_key_id("iron key");
    chest -> set_lock_difficulty(20);
    move_object(chest, this_object());
  }
  if(!present("money", present("chest", this_object()))) {
    money = clone_object(MONEY);
    money -> add_money(100 + random(500));
    move_object(money, present("chest", this_object()));
  }   

  if(!present("lamp", present("chest", this_object()))) {
    lamp = clone_object("objects/torch");
    lamp -> set_name("lamp");
    lamp -> set_weight(2);
    lamp -> set_short("An oil lamp");
    lamp -> set_long("A fine brass oil lamp.\n");
    lamp -> set_value(20);  
    lamp -> set_fuel(8000);             /* x2 that of a torch */
    lamp -> set_light_intensity(3);     /* x2 that of a torch */
    move_object(lamp, present("chest", this_object()));
  }

  if(!present("cloth", present("chest", this_object()))) {
    cloth = clone_object(TREASURE);
    cloth -> set_name("cloth");
    cloth -> set_alias("bolt");
    cloth -> set_alt_name("silk");
    cloth -> set_short("A bolt of silk cloth");
    cloth -> set_long(
               "A fine bolt of turquoise silk. It would fetch "+
               "a fair price at any store.\n");
    cloth -> set_value(1000);
    cloth -> set_weight(7);
    cloth -> set_sell_destruct(1);
    move_object(cloth, present("chest", this_object()));
  }

  if(arg) return;
  set_short("a wreck on skol island");
  set_long(
     "It is dark, damp, and musty inside this ship wreck. Old timbers \n"+
     "lie strewn across your path, making it impossible to access most \n"+
     "parts of the ship. Here in the hull, several barrels, and chests \n"+
     "have survived the wreck.\n");

  set_weather(0, 2, 6); /* dark all of the time, needs a torch */
  set_exits(({ 
     "room/island/beach6", "out",
  }));
  set_listen("You hear the soothing sounds of the waves against the wreck.\n");
  set_smell("Sea salt is strong in the air here.\n");
  set_items(({
     "timber#timbers",
          "Old beams that used to support the ceiling of this ship",
     "hull",
          "There is a hole in the hull you may be able to climb out of",
  }));
}
