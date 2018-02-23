/* PHILLIPE.C 
   Author:NightBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Phillipe French");
  set_name("phillipe");
  set_race("human");
  set_long(
"Phillipe is a small, dainty human male. He is five and a half feet\n"+
"tall and has black hair and brown eyes.\n");

  set_gender(1);
  set_level(6);
  set_ac(5);
  set_wc(10);
  add_money(200 + random(50));
  set_hp(95);
  set_max_hp(95);
  set_al(0);
  add_class("mage");
  add_class("fighter");
  load_spells(20,({ "magic missile", "shield", "bbb", "acid arrow",
  "chill touch", "lt", "stoneskin", }));



  load_chat(5, ({"Phillipe clicks his toungue.\n",
    "Phillipe says: Tsk, tsk....this will never do.\n",
    "Phillipe asks: Do you attend the University?\n",
    }));

  load_a_chat(5,({"Phillipe says: I'm a lover not a fighter.\n",
      "Phillipe says: Geez, your muscles are so big.\n",

    }));


  }
