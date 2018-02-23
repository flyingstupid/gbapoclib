#include <mudlib.h>
inherit ROOM;

object chest;
object money;
void reset(status arg) {
  if(!present("chest")) {
    chest = clone_object(CONTAINER);
    chest -> set_name("chest");
    chest -> set_closed(1);
    chest -> set_can_lock(1);
    chest -> set_locked(1);
    chest -> set_short("A huge chest");
    chest -> set_long("A huge chest with iron bands about its middle\n");
    chest -> set_lock_desc("A big rusty iron lock");
    chest -> set_key_id("skeleton key");
    chest -> set_weight(1000000000);   /* big hey! */
    chest -> set_trapped(1);
    chest -> set_trap_msg("A poison dart comes flying out at you!");
    chest -> set_trap_dam(20 + random(30));
    chest -> set_trap_complexity(17);
    move_object(chest, this_object());
  }

  if(!present("money", chest)) {
    money = clone_object(MONEY);
    money -> set_money(1000 + random(1000));
    move_object(money, chest);
  }

  if(arg) return;

  set_short("the inn at skandles downfall");
  set_long(
     "Cobwebs and dust hang from the corners of this old room.\n"+
     "It looks like no one has been here for many years. There\n"+
     "is a hole in the wall large enough to crawl through.\n");
  set_weather(0, 1, 0);
  set_items(({
    "hole#wall", "There is a hole in the wall big enough to crawl through"
  }));
}

void init() {
  ::init();
  add_action("enter", "crawl");
  add_action("enter", "squeeze");
  add_action("enter", "enter");
}

status enter(string str) {
  string tmp1, tmp2;

  if(sscanf(str, "%shole%s", tmp1, tmp2) ||
     sscanf(str, "%swall%s", tmp1, tmp2)) {
    write("You crawl through the hole in the wall.\n");
    if(!this_player()->query_stealth_on())
      say(this_player()->query_name() +" crawls through a hole in the "+
          "wall.\n");
    move_object(this_player(), "room/city/pub/inn1");
    command("look", this_player());
    return 1;
  }
}
