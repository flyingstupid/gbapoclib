/* NIL.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Nil Spaar");
  set_name("nil");
  set_race("minotaur");
  set_long(
"Nil Spaar is a small bull Minotaur with a deep hatred to all humanoids.\n"+
"He is massive in size by human comparison, but small to Minotaurs. He\n"+
"wears a large golden ring through his nose.\n");

  set_gender(1);
  set_level(6);
  set_ac(5);
  set_wc(10);
  add_money(200 + random(50));
  set_hp(95);
  set_max_hp(95);
  set_al(0);
  add_class("mage");
  add_class("fighter");
  load_spells(20,({ "magic missile", "shield", "bbb", "acid arrow",
  "chill touch", "lt", "stoneskin", }));



  load_chat(5, ({"Nil snorts at Norda.\n",
    "Nil says: I will eat this smelly elf for breakfast one day.\n",
    "Nil mimics Norda.\n",
    }));

  load_a_chat(5,({"Nil says: You are ugly.\n",
      "When I am done with this one...I will slay you Norda.\n",

    }));


  }
