/* JOHN.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("John Earhardt");
  set_name("john");
  set_race("dwarf");
  set_long(
"John Earhardt is Jack Daniels cousin and drinking mate. He has \n"+
"accompanied Jack on many a long drunken fling.\n");

  set_gender(1);
  set_level(12);
  set_ac(9);
  set_wc(16);
  add_money(900 + random(100));
  set_hp(230);
  set_max_hp(230);
  set_al(-200);
  add_class("cleric");
  add_class("fighter");
  load_spells(20,({ "cure medium wounds", "cause medium wounds", "bless",
  "curse", "prayer", "barkskin",}));

  load_chat(5, ({"John says: Hez suchadrunk.....burp.\n",
    "John sings: Roll out the barrels.\n",

    }));

  load_a_chat(5,({"John burps in your face.\n",
    "John drools on you.\n",

    }));


  }
