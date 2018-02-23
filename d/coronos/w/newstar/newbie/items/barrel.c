/* barrel.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit CONTAINER;
 
void reset(status arg) {

  if (!present("lantern")) {
     move_object(clone_object(
     "d/coronos/w/newstar/newbie/items/lantern"),this_object()); 
  }

  if(arg) return;
  set_name("barrel");
  set_short("");
  set_long(
    "The wooden barrel is used to store lanterns.  It has some\n"+
    "hay in it to help protect the lanterns. \n");
  set_max_weight(2);
  set_weight(10000); /* Can't GET jar */
}
