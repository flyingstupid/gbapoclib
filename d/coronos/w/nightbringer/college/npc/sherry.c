/* SHERRY.C
   Author:DarkBringer
   05-04-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Sherry Priestly");
  set_name("sherry");
  set_race("human");
  set_long(
"Sherry is small in stature, but large in courage. She has long,\n"+
"brown hair and blue eyes. She loves to help others, so she has\n"+
"come to Ille Coronos to study the ways of healing.\n");

  set_gender(2);
  set_level(7);
  set_ac(6);
  set_wc(11);
  add_money(200 + random(100));
  set_hp(170);
  set_max_hp(170);
  set_al(1000);
  add_class("cleric");
  load_spells(20,({ "cure light wounds", "cure medium wounds", "bless" }));



  load_chat(5, ({"Sherry says: I will heal the world.\n"
    "Sherry says: The world is hurting.\n",
    "Sherry says: I will be a great healer.\n",
    }));

  load_a_chat(5,({"Sherry says: But I could help you my friend.\n",
    "Sherry says: You have a problem with self-esteam.\n",

    }));

}
  
