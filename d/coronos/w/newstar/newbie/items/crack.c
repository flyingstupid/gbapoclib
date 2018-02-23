/* crack.c -- Newbie */
/* Darkness and Newstar */

#include <mudlib.h>
#define NUM           (int)1+random(2)
#define CHANCE        (int)1+random(12)
inherit CONTAINER;
 
void reset(status arg) {
  
  if(arg) return;

  set_name("a crack");
  set_alias("crack");
  set_short("");
  set_long(
    "This huge rock boasts a large crack in its side, possibly\n"+
    "created by a lightning strike long ago.\n");
  set_max_weight(1);
  set_weight(10000); /* Can't GET crack */

  if (!present("small brooch")) {
    if (NUM > CHANCE) {
      move_object(clone_object(
      "d/coronos/w/newstar/newbie/items/brooch"),this_object()); }
  }
}
