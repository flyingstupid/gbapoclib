/* JENNIFER.C
   Author:DarkBringer
   05-04-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Jennifer Sagelight");
  set_name("jennifer");
  set_race("halfling");
  set_long(
"Jennifer is a small halfling woman who is trying to turn from,\n"+
"being a disrespctful street rat into a respectful mage. She wears\n"+
"her hair in a top knot.\n");

  set_gender(2);
  set_level(4);
  set_ac(4);
  set_wc(8);
  add_money(100 + random(50));
  set_hp(70);
  set_max_hp(70);
  set_al(-400);
  add_class("mage");
  load_spells(20,({ "magic missile", "bbb", }));



  load_chat(5, ({"Jennifer says: I will not steal, I will not steal.\n",
    "Jennifer says: I will become a powerful mage.\n",
    "The Kender will sing songs about me.\n",
    }));

  load_a_chat(5,({"Jennifer sighs sadly.\n",
    "Jennifer says: Now how did that spell go....\n",

    }));


  }
