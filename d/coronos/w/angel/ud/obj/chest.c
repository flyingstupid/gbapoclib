#include <mudlib.h>
inherit CONTAINER;

void reset(status arg) {
  set_locked(1);
  set_closed(1);
  set_trapped(1);

  if(arg) return;
  set_name("chest");
  set_container_weight(20);
  set_max_weight(20);
  set_short("An iron chest");
set_long(  "The chest is made froma very solid wood and is \n"+   "bound with iron bands around either end. In the centre\n"+     "is a large lock, made some kind of silver alloy.\n");

set_trap_id("needle");
set_trap_desc("A poison needle jutting out of the lock.\n");
set_trap_difficulty(10);
set_trap_damage(20 + random(50));
set_trap_message("A needle flies out and stabs you in the finger.\n");
set_trapped(1);

  set_lock_id("silver lock");
  set_lock_desc("An iron lock, plated in silver.\n");

  set_key_id("silver key");
  set_lock_difficulty(10000);
  /* go ahead and find the key instead! */

}
