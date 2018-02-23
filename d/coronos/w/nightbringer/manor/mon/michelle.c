/* MICHELLE ROCHESTER*/
/* Author:DarkBringer */
/* 04-26-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  if(!present("dagger")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/weapon/dagger.c"),this_object());
    init_command("wield dagger");
    }


  set_short("michelle rochester");
  set_name("michelle rochester");
  set_alias("michelle");
  set_race("human");
  set_long(
"Michelle Rochester is a six year old little sniveling, coniving brat.\n"+
"She relies on her father to bail her out of any trouble that she gets\n"+
"into, which is quite alot, as she has a tendency to take things that\n"+
"don't belong to her\n");

  set_gender(1);
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_al(-100);

  add_money(200 + random(50));
  add_class("thief");


  load_chat(5, ({"Michelle says: I can do whatever I want, my daddy's rich.\n",
"Michelle sticks her tounge out at you.\n",

    }));

  load_a_chat(5,({"Michelle screams: DADDDDYYYYYY!\n",
    }));


  }
