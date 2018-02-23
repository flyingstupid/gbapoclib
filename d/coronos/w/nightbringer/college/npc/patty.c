/* PATTY.C
   Author:DarkBringer
   05-04-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Patty Duke");
  set_name("patty");
  set_race("gnome");
  set_long(
"Patty is a sweet gnomish girl who has been unfortunate enough to be\n"+
"roomed with a bigot like Samantha. She looks nervous and sad.\n");

  set_gender(2);
  set_level(4);
  set_ac(4);
  set_wc(8);
  add_money(50 + random(100));
  set_hp(70);
  set_max_hp(70);
  set_al(0);
  add_class("cleric");
  load_spells(20,({ "cure light wounds", "bless", "curse", "prayer", }));



  load_chat(5, ({"Patty says: I can't take much more.\n",
    "Patty says: I'm gonna do something I'll regret.\n",
    }));

  load_a_chat(5,({"Patty cries defeatedly.\n",

    }));


  }
