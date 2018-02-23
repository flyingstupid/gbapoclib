/* GEORGE.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("George Braveheart");
  set_name("george");
  set_race("minotaur");
  set_long(
"George is a massive Minotuar male who has decided to lower his\n"+
"standards and intermingle with humankind for the sake of learning\n"+
"the arts of sorcery. He figures that by being a sorcerour, he\n"+
"will be the most powerful Minotaur on Minos.\n");

  set_gender(1);
  set_level(12);
  set_ac(9);
  set_wc(16);
  add_money(900 + random(100));
  set_hp(230);
  set_max_hp(230);
  set_al(-200);
  add_class("mage");
  add_class("fighter");
  load_spells(20,({ "magic missile", "acid arrow", "coc", "scare", }));



  load_chat(5, ({"George says: Puny humanoid.\n",
    "George says: I hate Humans!\n",
    "George says: I hate Elves!\n",
    "George says: I hate Dwarves!\n",
    "George says: I hate Gnomes!\n",
    "George says: I hate Halflings!\n",


    }));

  load_a_chat(5,({"George bellows with rage.\n",
    "George asks: Do you really believe that you can defeat me?\n",

    }));


  }
