/* ALICIA.C
   Author:DarkBringer
   05-04-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Alicia Crownguard");
  set_name("alicia");
  set_race("human");
  set_long(
"Alicia is a distant descendant of the ancient Solamnic Knight,\n"+
"Derreck Crownguard.She is very proud of her heritage, and wants\n"+
"to see the Knights resurface.\n");

  set_gender(2);
  set_level(7);
  set_ac(6);
  set_wc(11);
  add_money(250 + random(50));
  set_hp(110);
  set_max_hp(110);
  set_al(1000);
  add_class("cleric");
  load_spells(20,({ "cure light wounds", "bless", "curse", "prayer", }));



  load_chat(5, ({"Alicia says: We will see that they shall rise again.\n",
    "Alicia says: Hmmm, you are not worthy of the Knights.\n",
    "Alicia says: We are looking for a few special men to start with.\n",
    }));

  load_a_chat(5,({"Alicia sighs sadly.\n",
    "Alicia says: I guess that it was not meant to be.\n",

    }));


  }
