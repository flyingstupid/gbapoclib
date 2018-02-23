/* Lady Penor.C */
/* Author:DarkBringer */
/* 04-27-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("lady penor");
  set_name("lady penor");
  set_alias("lady");
  set_race("human");
  set_long(
"lady penor is a pleasent looking, middle-age woman. She is tall, and\n"+
"stout with coal black hair and blue eyes.\n");

  set_gender(2);
  set_level(15);
  set_ac(12);
  set_wc(20);
  add_class("fighter");


  load_chat(5, ({"Lady Penor says: I can't sleep at night.\n",
    "Lady Penor says: The noises have to stop.\n",
    }));

  load_a_chat(5,({
    "Lady Penor says: Please don't do that.\n",
    "Lady Penor cries.\n",
    }));


  }
