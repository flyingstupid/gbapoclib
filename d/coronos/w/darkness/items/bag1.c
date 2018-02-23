#include <mudlib.h>
inherit CONTAINER;
 
void reset(status arg) {
  if(arg) return;
  set_name("sack");
  set_plural("sacks");
  set_alias("bag");
  set_short("A small sack");
  set_long("A small sack that once held grain.\n");
  set_max_weight(11);
  set_value(10);
  set_weight(1);

  if (!present("gem")) {
    move_object(clone_object(
    "/objects/components/gem"),
    this_object());
  }
  
  if (!present("key")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/items/key1"),
    this_object());
  }
}
