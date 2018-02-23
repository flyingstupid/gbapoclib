/* WILLIAM.C 
   Author:DarkBringer 
   05-29-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("William Wallace");
  set_name("william");
  set_race("dwarf");
  set_long(
"William is a short and stocky dwarf. He stands only three feet tall\n"+
"but weighs nearly one-hundred pounds. He has a long, flowing beard\n"+
"that nearly reaches the floor.\n");

  set_gender(1);
  set_level(10);
  set_ac(8);
  set_wc(14);
  add_money(650 + random(50));
  set_hp(175);
  set_max_hp(175);
  set_al(-50);
  add_class("cleric");
  load_spells(20,({ "cure light wounds", "bless", "curse", "prayer",
              }));



  load_chat(5, ({"William says: Do you believe?\n",
    "William is in deep thought over the situation.\n",
    }));

  load_a_chat(5,({"William screams: By Rorex's beard, I don't think so!\n",
    "William screams in rage: Die, you scum-sucking pig!\n",

    }));


  }
