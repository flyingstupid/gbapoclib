/* GEEVES.C */
/* Author:DarkBringer */
/* 04-25-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Geeves, The Butler");
  set_name("geeves");
  set_alias("butler");
  set_race("human");
  set_long(
"Geeves is an old man with a crooked back and an even crookeder\n"+
"smile. He has a long hock-shaped nose and dark, beady eyes that dart\n"+
"back and forth nervously. He has black hair that looks like it was cut\n"+
"by using a bowl as a mold. He is balding on top of his head and his hair\n"+
"makes a ring around the dome of his head.\n");

  set_gender(1);
  set_level(12);
  set_ac(9);
  set_wc(16);
  set_al(-100);
  add_money(500 + random(500));
  add_class("fighter");

  load_chat(5, ({"Geeves whistles through his teeth.\n",
    "Geeves chuckles slyly to him self.\n",
    " Geeves puts a plate on the tabe and says: Rats in cellar.\n",
    }));

  load_a_chat(5,({"Geeves giggles insanely.\n",
    "Geeves smiles evily.\n",
    }));


  }
