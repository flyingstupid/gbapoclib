/* JEWEL.C
   Author:DarkBringer
   05-03-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Jewel Summers");
  set_name("jewel");
  set_race("human");
  set_long(
"Jewel is an attracive young woman. She has long brown hair and deep,\n"+
"intelligent brown eyes. Her smile dazzles men and leaves them in awe.\n");

  set_gender(2);
  set_level(3);
  set_ac(4);
  set_wc(7);
  add_money(50 + random(50));
  set_hp(60);
  set_max_hp(60);
  set_al(100);
  add_class("mage");
  load_spells(20,({ "magic missle", "chill touch", "acid arrow", }));



  load_chat(5, ({"Jewel sings sweatly.\n",
    "Jewel smiles at you seductively.\n",
    "Jewel bats her eyes at you.\n",
    }));

  load_a_chat(5,({"Jewel cries.\n",
    "Jewel screams: I'm too beautiful to die.\n",
    "Jewel says: I think we could find a better way to spend this energy....\n",

    }));


  }
