/* DRAKE.C */
/* Author:DarkBringer */
/* 04-27-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {
   ::reset(arg);
  if(arg) return;

  set_short("Drake");
  set_name("drake");
  set_race("human");
  set_long(
"Drake is a young boy of about ten years. He is tall and has wavy,\n"+
"black hair.\n");

  set_gender(1);
  set_level(6);
  set_ac(5);
  set_wc(10);
  add_class("fighter");


  load_chat(5, ({"Drake says: I'm gonna be a powerful fighter.\n",
    "Drake says: When I grow up, I'll be a Dragon Slayer.\n",
    }));

  load_a_chat(5,({
    "Drake says: I can whip ya.\n",
    "Drake cries.\n",
    }));


  }
