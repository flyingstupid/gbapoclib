/* CINTHIA.C
   Author:DarkBringer
   05-03-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("cinthia Barlow");
  set_name("cinthia");
  set_race("grey elf");
 set_long(
"Cinthia is a young elven maiden. She has long silver hair and almond\n"+
"shaped brown eyes. She is tall and willowy, and is very attractive.\n");

  set_gender(2);
  set_level(6);
  set_ac(5);
  set_wc(10);
  add_money(200 + random(50));
  set_hp(95);
  set_max_hp(95);
  set_al(400);
  add_class("mage");
  load_spells(20,({ "magic missle", "chill touch", "acid arrow", }));



  load_chat(5, ({"Cinthia says: Please stop singing...I'm trying to study.\n",
    "Cinthia rolls her eyes at Jewels wantoon antics.\n",
    "Cinthia studies a spell.\n",
    }));

  load_a_chat(5,({"Jewel cries.\n",
    "Cinthia screams: CAN'T YOU SEE I'M TRYING TO STUDY!!!!\n",
    "Please leave me be....finals start tomorrow.\n",

    }));

}
