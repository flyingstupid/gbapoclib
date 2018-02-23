/* GWYN.C */
/* Author:DarkBringer */
/* 04-25-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("gwyn, the chambermaid");
  set_name("gwyn");
  set_alias("chambermaid");
  set_race("human");
  set_long(
"Gwyn is a stunningly beautiful human woman. She has medium length blonde\n"+
"hair, blue eyes, and body that most wemon would die for.\n");

  set_gender(2);
  set_level(8);
  set_ac(7);
  set_wc(12);
  add_money(150 + random(100));
  add_class("fighter");


  load_chat(5, ({"Gwyn sighs tiredly.\n",
    "Gwyn says: I'm scared of this place.\n",
    "Gwyn asks: When will my Knight in shining armour come for me ?\n",
    "Gwyn says: Some day I Will marry Nightbringer.\n",
    }));

  load_a_chat(5,({"Gwyn yelps in fear.\n",
    "Gwyn asks: Why would you want to kill someone as beautiful as me?\n",
    }));


  }
