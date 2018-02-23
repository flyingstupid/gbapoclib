/* THOR.C 
   Author:NightBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Thor Barlow");
  set_name("thor");
  set_race("human");
  set_long(
"Thor Barlow's ancesters were  Barbarians of the high plains. His\n"+
"parents are determined that there son will be educated in the ways\n"+
"of civilization, so that he can re-unite the Barbarian tribes once\n"+
"again and lead them to their prior power. He is a massive human\n"+
"teen-aged boy, standing nearly seven feet tall and weighing over\n"+
"two hundred pounds.\n");

  set_gender(1);
  set_level(4);
  set_ac(4);
  set_wc(8);
  add_money(100 + random(50));
  set_hp(70);
  set_max_hp(70);
  set_al(100);
  add_class("mage");
  load_spells(20,({ "magic missile", "bbb", }));



  load_chat(5, ({"Thor says: I will lead the barbarian tribes to power.\n",
    "Thor says: My people are depending on me.\n",
    }));

  load_a_chat(5,({"Thor cries with frustration.\n",
    "Thor says: Now, my people will wither and die.\n",

    }));


  }
