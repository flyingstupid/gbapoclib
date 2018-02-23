/* OTIK.C 
   Author:DarkBringer 
   05-04-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Otik Karlov");
  set_name("otik");
  set_race("human");
  set_long(
"Otik is a big, brawny guy who stands six feet tall. He has wavy brown\n"+
"hair and deep, penetrating blue eyes.\n");

  set_gender(1);
  set_level(12);
  set_ac(9);
 set_wc(11);
  add_money(250 + random(50));
  set_hp(230);
  set_max_hp(230);
  set_al(1000);
  add_class("mage");
  add_class("fighter");
  load_spells(20,({ "magic missile", "acid arrow", "coc", "scare", }));



  load_chat(5, ({"Otik says: I'm wasting my time here.\n",
    "Otik says: A mage could never be as powerful as a fighter.\n",
    }));

  load_a_chat(5,({"Otik screams with rage.\n",
    "Otik says: Die scum, die!\n",
    "Otik laughs in your face.\n",

    }));


  }
