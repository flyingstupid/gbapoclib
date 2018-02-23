/* THORDKIN.C */
/* Author:DarkBringer */
/* 04-25-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("thordkin, the gardener");
  set_name("thordkin");
  set_alias("gardener");
  set_race("dwarf");
  set_long(
"Thordkin is an ancient, crumpled over Hill Dwarf that has spent what he.\n"+
"fells to be 20 wasted years in servitude to the Penors. He has long,\n"+
"hair, and a grey, shaggy beard. He has a bolbous nose and his complexion\n"+
"is red and flushed, showing the signs of drinking to much Dwarven Spirits\n"+
"in his life./n");

  add_class("fighter");

  set_gender(1);
  set_level(8);
  set_ac(7);
  set_wc(12);
  add_money(250 + random(100));

  load_chat(5, ({"Thordkin groans with exhaustion.\n",
    "Thordkin says: Tweenty years, and for what?\n",
    "Thordkin says: I hope the evil spirits get 'em.\n",
    }));

  load_a_chat(5,({"Thordkin says: Do me a favor and kill me quick.\n",
    "Thordkin asks: What do I have to live for anyway...more work?\n",
    }));


  }
