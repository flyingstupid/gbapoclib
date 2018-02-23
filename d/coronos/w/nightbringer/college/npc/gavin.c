/* GAVIN.C 
   Author:DarkBringer 
   05-29-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Gavin Lightfoot");
  set_name("gavin");
  set_race("elf");
  set_long(
"Gavin is a proud man of Elven heritage. He considers all other\n"+
"races as inferior. He stands about five and a half feet tall and\n"+
"is very slender. He has short, cropped silvery colored hair and a\n"+
"fair complexion.\n");

  set_gender(1);
  set_level(8);
  set_ac(7);
  set_wc(12);
  add_money(300 + random(50));
  set_hp(130);
  set_max_hp(130);
  set_al(50);
  add_class("cleric");
  add_class("mage");
  load_spells(20,({ "cure light wounds", "bless", "curse", "prayer",
  "magic missile", "acid arrow", "burning hands", "chill touch", }));



  load_chat(5, ({"Gavin says: That Amanda is one hot chick.\n",
    "Gavin says: You know, I think i'll marry her.\n",
    }));

  load_a_chat(5,({"Gavin exclaims: Hey, i'm telling my mom!\n",
    "Get your hands off of me, you big brute!\n",

    }));


  }
