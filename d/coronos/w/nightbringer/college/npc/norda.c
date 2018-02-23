/* NORDA.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Norda Proi");
  set_name("norda");
  set_race("elf");
  set_long(
"Norda Proi is an regal looking High Elf of royal ancestory. He\n"+
"is tall a willowy, and bears the features of the Elvin royal\n"+
"bloodline.\n");

  set_gender(1);
  set_level(4);
  set_ac(4);
  set_wc(8);
  add_money(100 + random(50));
  set_hp(70);
  set_max_hp(70);
  set_al(100);
  add_class("mage");
  add_class("fighter");
  load_spells(20,({ "magic missile", "bbb", }));

  load_chat(5, ({"Norda says: Shut up you stupid cow.\n",
    "Norda asks: Can you believe they made me roommates with this stupid\n"+
    "beast?\n",
    "Norda says: And he smells.\n",
    }));

  load_a_chat(5,({"Norda yells: Kill the cow, Kill the cow!\n",
    "Norda yells: Not me, you fool. The COW!\n",

    }));


  }
