/* JESSICA.C */
/* Author:DarkBringer */
/* 04-27-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

   set_short("Jessica");
  set_name("jessica");
  set_race("human");
  set_long(
"Jessica is a young girl of about six years. She has blonde hair and,\n"+
"blue eyes. She is very cute looking.\n");

  set_gender(2);
  set_level(4);
  set_ac(4);
  set_wc(8);
  add_class("fighter");


  load_chat(5, ({"Jessica asks: Would you play dolls with me?\n",
    "Jessica asks: Wanna have a tea party?\n",
    "Jessica asks: Wanna play dress up ?.\n",
    }));

  load_a_chat(5,({
    "Jessica cries.\n",
    "Jessica burst out into tears.\n",
    }));


  }
