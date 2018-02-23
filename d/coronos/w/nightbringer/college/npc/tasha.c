/* TASHA.C
   Author:DarkBringer
   05-03-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

 set_short("Tasha Marlow");
  set_name("tasha");
  set_race("gnome");
  set_long(
"Tasha is a short, squat Gnomish female. She stands about three feet\n"+
"tall and is nearly as wide as she is high. She has a beautiful smile\n"+
"and a sensational personality.\n");

  set_gender(2);
  set_level(4);
  set_ac(4);
  set_wc(8);
  add_money(100 + random(50));
  set_hp(70);
  set_max_hp(70);
  set_al(1000);
  add_class("cleric");
  load_spells(20,({ "cure wounds", "bless", "curse", "prayer", }));



  load_chat(5, ({"Tasha says: It figures.....\n",
    "Tasha says: My dad is a famous inventor!\n",
    "Tasha says: He invented the ice box.\n",
    }));

  load_a_chat(5,({"Tasha cries.\n",
    "Tasha says: May the All-God have mercy on your soul.\n",
    "Tasha says: You evil person, you!\n",

    }));


  }
