/* STEEL.C 
   Author:DarkBringer 
   05-29-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Steel Trueblade");
  set_name("steel");
  set_race("human");
  set_long(
"Steel Trueblade is a descendent of the Solamnic Knights of old.\n"+
"He is tall and slender with long, straight brown hair, and a \n"+
"thick handlebar mustache.\n");

  set_gender(1);
  set_level(6);
  set_ac(5);
  set_wc(10);
  add_money(200 + random(50));
  set_hp(95);
  set_max_hp(95);
  set_al(0);
  add_class("cleric");
  add_class("fighter");
  load_spells(20,({ "cure light wounds", "bless", "curse", "prayer", }));



  load_chat(5, ({"Steel ponders the situation.\n",
    "Steel says: You know, school is hard work.\n",
    "Steel asks: Do you attend the University?\n",
    }));

  load_a_chat(5,({"Steel exclaims: Hey, that's not allowed here!\n",
    "Steel says: Pick on someone your own size, you big meanie!\n",

    }));


  }
