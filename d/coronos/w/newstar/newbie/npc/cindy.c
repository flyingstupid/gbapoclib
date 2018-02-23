/* cindy.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("cindy");
  set_alt_name("girl");
  set_alias("daughter");
  set_short("little Cindy");
  set_long(
    "Little Cindy Newman is a cute little girl.  She couldn't be more\n"+
    "than three years old.  She has long, straight blonde hair, and big\n"+
    "blue eyes that make her look so adorable.  She wears a cute blue\n"+
    "dress and a pretty necklace.\n");
 
   load_chat(5, ({
    "Cindy looks at you with adorable blue eyes.\n",
    "Cindy rubs her eyes sleepily.\n",
    "Cindy plays with some toys.\n",
    "Cindy runs around hapily.\n",
    "Cindy whimpers some and then starts crying.\n",
    }));
 
  load_a_chat(50, ({
    "Cindy cries and calls for her mommy.\n",
    "Cindy cries and calls for her daddy.\n",
    "Cindy looks shocked that she is being hurt!.\n",
    "Cindy is so helpless. She doesn't know what to do.\n",
    "Cindy tries to run away.\n",
    }));
 
  set_al(300);
  set_level(2);
  set_wc(4);
  set_ac(5);
  set_max_hp(50);
  set_hp(50);
  set_gender(2);
  set_money(40+random(20));
  set_race("human");
 
 if (!present("necklace")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/necklace"),
    this_object());
    command("wear necklace");
  }
}
 

void catch_tell(string str) {
  return;
}
