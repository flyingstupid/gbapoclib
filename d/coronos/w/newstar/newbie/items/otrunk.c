#include <mudlib.h>
inherit CONTAINER;

object ob1, ob2; 

void reset(status arg) {

  if(arg) return;

  set_name("old trunk");
  set_alias("trunk");
  set_short("an old trunk");
  set_long(
    "This is an old, oak trunk with cast-iron bindings.  It has a large,\n"+
    "bronze lock with a Soldier's Crest engraved upon it.\n");
  set_max_weight(14);
  set_weight(10000); /* Heavy.  Can't move */
  set_closed(1);
  set_locked(1);
  set_lock_id("old bronze lock");
  set_lock_desc("A sturdy bronze lock");
  set_key_id("old bronze key");
  set_lock_difficulty(20);  /* So a Newbie HAS to get the key. */
  
  if(!find_object("soldier's armour")) {
    ob1 = clone_object("d/coronos/w/newstar/newbie/items/sarmour");
    move_object(ob1, this_object());
  }

  if(!find_object("old letter")) {
    ob2 = clone_object("d/coronos/w/newstar/newbie/items/sletter");
    move_object(ob2, this_object());
  }
}
