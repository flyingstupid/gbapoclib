/* JACK.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Jack Daniels");
  set_name("jack");
  set_race("dwarf");
  set_long(
"Jack Daniels is a stout Dwarven adolescent. He is short and stocky\n"+
"with long black hair and an even longer black beard. He has a big,\n"+
"bolbous nose that is a bright red, indictive of his alcohol abuse.\n");

  set_gender(1);
  set_level(12);
  set_ac(9);
  set_wc(16);
  add_money(900 + random(100));
  set_hp(230);
  set_max_hp(230);
  set_al(-200);
  add_class("cleric");
  load_spells(20,({ "cure medium wounds", "cause medium wounds", "bless",
  "curse", "prayer", "barkskin",}));



  load_chat(5, ({"Jack says: Hab a sdrink wid...hicup...me\n",
    "Jack says: Fink alepjanbtss arez in the cornder\n",

    }));

  load_a_chat(5,({"jack looks like he might throw up on you.\n",
    "Jack says: I willd slayd cho.\n",

    }));


  }
