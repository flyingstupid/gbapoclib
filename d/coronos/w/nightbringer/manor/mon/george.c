/*GEORGE.C */
/* Author:DarkBringer */
/* 04-25-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;


  set_short("George, The Cooks Apprentice");
  set_name("george");
  set_race("human");
  set_long(
"George is the cooks apprentice for Penor Manor. He has been working\n"+
"with Pierre for two years now. He puts up with Pierre's abusive\n"+
"treatment because he knows that Pierre is the finest chef in the land\n");

  set_gender(1);
  set_level(5);
  set_ac(5);
  set_wc(9);
  add_class("fighter");


  add_money(150 + random(50));

  load_chat(5, ({"George says: Nag, nag, nag.....\n",
    "George rolls his eyes at Pierre .\n",
    "George sticks his toungue out at Pierre.\n",

    }));

  load_a_chat(5,({"George says: It's a good day to die.\n",
    "George says: Kill the fat one, not me.\n",
    }));


  }
