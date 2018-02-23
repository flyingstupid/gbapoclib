/* Timmy Rochester*/
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


  set_short("timmy rochester");
  set_name("timmy rochester");
  set_alias("timmy");
  set_race("human");
  set_long(
"Timmy Rochester is a twelve year old little sniveling, coniving brat.\n"+
"He relies on his father to bail him out of any trouble that he gets into,\n"+
"which is quite alot, as he has a tendency to take things that don't belong\n"+
"to him\n");

  set_gender(1);
set_level(6);
  set_ac(5);
  set_wc(10);
  set_al(-100);

  add_money(200 + random(50));
  add_class("thief");


  load_chat(5, ({"Timmy says: I can do whatever I want, my daddy's rich.\n",
"Timmy sticks his tounge out at you.\n",

    }));

  load_a_chat(5,({"Timmy screams: DADDDDYYYYYY!\n",
    }));


  }
