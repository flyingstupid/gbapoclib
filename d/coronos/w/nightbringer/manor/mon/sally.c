/* SALLY.C */
/* Author:DarkBringer */
/* 04-27-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("sally");
  set_name("sally");
  set_race("human");
  set_long(
"sally is a little baby girl of about one year. She has blonde hair and,\n"+
"blue eyes. She is very sweat looking.\n");

  set_gender(2);
  set_level(1);
  set_ac(3);
  set_wc(5);

  load_chat(5, ({"sally gurgles happily.\n",
    "sally says: Dah.\n",
    "sally coo's at you.\n",
    }));

  load_a_chat(5,({
    "sally cries.\n",
    }));


  }
