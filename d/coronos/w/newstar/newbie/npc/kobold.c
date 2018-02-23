/* kobold.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("kobold");
  set_short("a kobold");
  set_long(
   "This is  a small kobold, standing no more than three feet high.\n"+
   "He has rusty brown skin and a long tail.  He is most likely a \n"+
   "slave of the Drow that has been taken on an above ground expedition.\n");
 
   load_chat(5, ({
    "The kobold scans the area.\n",
    "The kobold mumbles something to himself.\n",
    }));
 
  load_a_chat(40, ({
    "The kobold screams with rage.\n",
    "The kobold tries to run away.\n",
    "The kobold yells some sort of kobold battle cry.\n",
    }));
 
  set_al(-200);
  set_ac(3);
  set_wc(6);
  set_level(2);
  set_gender(1);
  set_money(40 +random(20));
  set_race("kobold");
  add_class("fighter");
 
 if (!present("heavy shirt")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/shirt"),
    this_object());
    command("wear shirt");
  }
}
