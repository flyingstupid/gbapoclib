/* SAMANTHA.C
   Author:DarkBringer
   05-04-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

   set_short("Samantha Strong");
  set_name("samantha");
  set_race("minotaur");
  set_long(
"Samantha is a young minotaur cow. She is very proud of her race,\n"+
"and considers all others as inferiors.\n");

  set_gender(2);
  set_level(7);
  set_ac(6);
  set_wc(11);
  add_money(250 + random(50));
  set_hp(110);
  set_max_hp(110);
  set_al(-1000);
  add_class("cleric");
  load_spells(20,({ "cure light wounds", "bless", "curse", "prayer", }));



  load_chat(5, ({"Samantha says: You are inferior.\n",
    "Samantha asks: Are all of the lesser races so puny?\n",
    }));

  load_a_chat(5,({"Samantha kicks you.\n",
    "Samantha says one such as you could not possibly defeat me.\n",

    }));


  }
