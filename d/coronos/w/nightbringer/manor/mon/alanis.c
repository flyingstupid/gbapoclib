/* ALANIS.C */
/* Author:DarkBringer */
/* 04-25-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Alanis, the Chambermaid");
  set_name("alanis");
  set_alias("chambermaid");
  set_race("human");
  set_long(
"Alanis is an attracive young woman. She has long brown hair and deep,\n"+
"intelligent brown eyes. Her smile dazzles men and leaves them in awe.\n");

  set_gender(2);
  set_level(8);
  set_ac(7);
  set_wc(12);
  add_money(150 + random(100));
  add_class("fighter");

  load_chat(5, ({"Alanis yawns sleepily.\n",
    "Alanis smiles at you seductively.\n",
    "Alanis bats her eyes at you.\n",
    }));

  load_a_chat(5,({"Alanis cries.\n",
    "Alanis says: I'm too young and talented to die.\n",
    }));


  }
