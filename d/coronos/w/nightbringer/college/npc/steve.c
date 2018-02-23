/* STEVE.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Steve Jordan");
  set_name("steve");
  set_race("human");
  set_long(
"Steve Jordan is a small human man. At a distance, he appears to be a\n"+
"Elf. He is frail and willowy, with long blonde hair and blue eyes.\n");

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



  load_chat(5, ({"Steve ponders the origion of the universe.\n",
    "Steve asks: Did you know that the world was created by an explosion?\n",
    "Steve asks: Do you attend the University?\n",
    }));

  load_a_chat(5,({"Steve says: Fighting is not allowed here.\n",
      "Steve asks: Would you strike down an unarmed opponent?\n",

    }));


  }
