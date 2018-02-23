/* bobby.c -- Newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("bobby");
  set_alt_name("boy");
  set_alias("son");
  set_short("little Bobby");
  set_long(
    "Little Bobby Newman is the Newman's son.  He is a rambunctious little\n"+
    "boy, as are all boys his age.  He is no more than five years old.  He\n"+
    "has short, brown hair, blue eyes and a smile so cute it is only rivaled\n"+
    "by his sister's smile.\n");
 
   load_chat(5, ({
    "Bobby smiles at you playfully.\n",
    "Bobby runs around the room happily.\n",
    "Bobby plays with some toys.\n",
    "Bobby explores the area.\n",
    }));
 
  load_a_chat(40, ({
    "Bobby cries and calls for his mommy.\n",
    "Bobby cries and calls for his daddy.\n",
    "Bobby tries to look very brave.\n",
    "Bobby tries to run away.\n",
    }));

  set_al(250);
  set_level(2);
  set_wc(4);
  set_ac(5);
  set_max_hp(50);
  set_hp(50);
  set_gender(1);
  set_money(40+random(20));
  set_race("human");
 
 if (!present("shortsword")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/sword2"),
    this_object());
    command("wield sword");
  }
}



void catch_tell(string str) {
  return;
}
