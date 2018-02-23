/*PIERRE.C */
/* Author:DarkBringer */
/* 04-25-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;


  set_short("pierre, the cook");
  set_name("pierre");
  set_race("human");
  set_long(
"Pierre is the cook for Penor Manor. He takes his job very seriously\n"+
"and allows for no foolishness from his young apprentice, George.\n"+
"He is middle aged and has a big belly, probably from sampling too\n"+
"much of his cooking. Pierre is reknowed throughout Ille Coronos for\n"+
"his cooking.\n");

  set_gender(1);
  set_level(9);
  set_ac(7);
  set_wc(13);
  add_class("fighter");


  add_money(300 + random(100));

  load_chat(5, ({"Pierre says: Not like that George, shred the lettuce.\n",
    "Pierre hits George over the head with a carrot.\n",
    "Pierre says: I buy him books, but all he does is eat the pages.\n",
    "Pierre says: If the hauntings don't stop, I'll have to cook somewhere\n"+
    "else\n",

    }));

  load_a_chat(5,({"Pierre cries like a girl.\n",
    "Pierre tries to hide behind George.\n",
    "Pierre screams: Don't just stand there, attack!\n",
    }));


  }
