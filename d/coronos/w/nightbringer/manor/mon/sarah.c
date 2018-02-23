/* SARAH.C */
/* Author:DarkBringer */
/* 04-25-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Sarah, The Maid");
  set_name("sarah");
  set_alias("maid");
  set_race("human");
  set_long(
"Sarah is a middle aged woman with greying hair and sharp,green eyes.\n"+
"she has been a maid for the Penors for over 20 years.\n");

  set_gender(2);
  set_level(6);
  set_ac(5);
  set_wc(10);
  add_money(150 + random(100));
  add_class("fighter");


  load_chat(5, ({"Sarah sighs tiredly.\n",
    "Sarah says: M'lady can't sleep at night.\n",
    "Sarah says: I've tried to give here a potion, but she won't take it.\n",
    }));

  load_a_chat(5,({"Sarah cries sadly.\n",
    "Sarah says: I am old and..I just don't care.\n",
    }));


  }
