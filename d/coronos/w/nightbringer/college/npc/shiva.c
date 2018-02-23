/* SHIVA.C
   Author:DarkBringer
   05-03-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Shiva Silverston");
  set_name("shiva");
  set_race("high elf");
  set_long(
"Shiva is a stunningly beautiful High Elf of royal blood. She was sent\n"+
"to Ille Coronos to futher her eduacation, which she takes very seriously.\n");

  set_gender(2);
  set_level(10);
  set_ac(8);
  set_wc(14);
  add_money(600 + random(100));
  set_hp(175);
  set_max_hp(175);
  set_al(1000);
  add_class("cleric");
  add_class("mage");
  load_spells(20,({ "curse", "prayer", "magic missile", "acid arrow", }));



  load_chat(5, ({"Shiva says: I'm busy...please leave.\n",
    "Shiva says: I must excell!\n",
    }));

  load_a_chat(5,({
    "Shiva says: I'm sorry, I'm too busy to die right now.\n",
    "Shiva screams: LET ME ALONE. I MUST STUDY!\n",

    }));


  }
