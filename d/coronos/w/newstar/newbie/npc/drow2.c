/* drow2.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("drow scout");
  set_alias("drow");
  set_short("a drow scout");
  set_long(
    "This is a Drow scout.  He is just under five feet tall, and his\n"+
    "cold grey eyes look out from behind his bangs.  Long white hair\n"+
    "contrasts his dark grey, almost black, skin.\n");
 
   load_chat(5, ({
    "The Drow scans the area.\n",
    "The Drow checks his gear.\n",
    "The Drow inspects something close by.\n",
    }));
 
  load_a_chat(40, ({
    "The Drow screams with rage.\n",
    "The Drow fights well.\n",
    "The Drow curses violently.\n",
    }));
 
  set_al(-250);
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_hp(60+random(40));
  set_gender(1);
  set_money(150 +random(100));
  set_race("drow elf");
  set_plural("drow scouts");
  add_class("fighter");
 
 if (!present("dagger")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/dagger"),
    this_object());
    command("wield dagger");
  }
}
