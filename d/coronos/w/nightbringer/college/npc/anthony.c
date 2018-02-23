/* ANTHONY.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Anthony Daniels");
  set_name("anthony");
  set_race("halfling");
  set_long(
"Anthony Daniels is a nimble, quick witted Halfling. He is sly and\n"+
"willful, using wit and stealth to overcome situations that most\n"+
"would use might for.\n");

  set_gender(1);
  set_level(8);
  set_ac(7);
  set_wc(12);
  add_money(300 + random(50));
  set_hp(130);
  set_max_hp(130);
  set_al(50);
  add_class("cleric");
  add_class("fighter");
  load_spells(20,({ "cure light wounds", "bless", "curse", "prayer",}));


  load_chat(5, ({"Anthony asks: Is that your face, or did a cart hit you?\n",
    "Anthony says: Halfling rule, all others drool!\n",
    }));

  load_a_chat(5,({"Anthony yells: Hey, look! A fiary!\n",
    "Anthony says: Quick, behind you, a Troll!\n",

    }));


  }
