#include <mudlib.h>
inherit CONTAINER;
 
void reset(status arg) {

  if (!present("old bronze key")) {
     move_object(clone_object(
     "d/coronos/w/newstar/newbie/items/bkey"),this_object()); 
  }

  if(arg) return;

  set_name("cookie jar");
  set_alias("jar");
  set_short("");
  set_long(
    "The ceramic cookie jar is white with blue stripes running around it.\n"+
    "It has a flat base and a rounded top.  The small lid has a little \n"+
    "handle used to open the jar.\n");
  set_max_weight(1);
  set_weight(10000); /* Can't GET jar */
  set_closed(1);
}
