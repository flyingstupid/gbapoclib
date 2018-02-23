/*DANGOR.C */
/* Author:DarkBringer */
/* 04-24-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  if(!present("baxe")) {
move_object(clone_object("d/coronos/w/nightbringer/manor/weapon/baxe.c"),this_object());
    init_command("wield axe");
    }



  set_short("dangor");
  set_name("dangor");
  set_race("mountain dwarf");
  set_long(
"Dangor is the leader of the local Mountain Dwarves. He is small\n"+
"in stature, but makes up for it in sheer strength and charm. He \n"+
"only stands three and a half feet tall. Dangor has long black hair\n"+
"and a shaggy black beard that almost reaches the floor.\n");

  set_gender(1);
  set_level(15);
  set_ac(12);
  set_wc(20);
  add_class("fighter");


  add_money(1000 + random(600));

  load_chat(5, ({"Dangor says: Ale is not as good as Dwarven Spirits.\n",
    "Dangor says: O'le Penors' starting to loose it.\n",
    " Dangor says: Can you believe it, ghosts?\n",
    }));

  load_a_chat(5,({"Dangor says: By Rorex's beard, I'll kill you.\n",
    "Dangor yells with anger.\n",
    }));


  }
