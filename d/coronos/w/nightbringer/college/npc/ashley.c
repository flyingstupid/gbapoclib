/* ASHLEY.C
   Author:DarkBringer
   05-04-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Ashley Nicole");
  set_name("ashley");
  set_race("dwarf");
  set_long(
"Ashley is a small, red-headed dwarf with an evil temper. She is\n"+
"known in her land as the small volcano. Her parents sent her here\n"+
"to learn to utilize her anger in a more desructive way.\n");

  set_gender(2);
  set_level(8);
  set_ac(7);
  set_wc(12);
  add_money(250 + random(100));
  set_hp(130);
  set_max_hp(130);
  set_al(-500);
  add_class("mage");
  load_spells(20,({ "acid arrow", "magic missile", "chill touch" }));



  load_chat(5, ({"Ashley says: I am learning the black arts.\n",
    "Ashley says: The world will be mine to twist and distort.\n",
    }));

  load_a_chat(5,({"Ashley says: I will devour your soul.\n",
    "Ashley says: I will eat your heart.\n",

    }));


  }
