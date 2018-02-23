/* KENNY.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Kenny Baker");
  set_name("kenny");
  set_race("gnome");
  set_long(
"Kenny Baker is a cheerful Gnome. He is the cousin of Harold Holis\n"+
"who lives down the hall. He plans on opening a magic shop with his\n"+
"cousin after they graduate from the University.\n");

  set_gender(1);
  set_level(10);
  set_ac(8);
  set_wc(14);
  add_money(650 + random(50));
  set_hp(175);
  set_max_hp(175);
  set_al(-50);
  add_class("mage");
  load_spells(20,({ "magic missile", "acid arrow", "fireball", "bbb",
  "chill touch", "vampiric touch", "pws", "scare", 
              }));



  load_chat(5, ({
    "Kenny says: NightBringer is the coolest dude in the realm.\n",
    "Kenny thinks about life.\n",
    }));

  load_a_chat(5,({"Kenny screams with rage.\n",
    "Kenny says: But i'm much too young and cool to die.\n",

    }));


  }
