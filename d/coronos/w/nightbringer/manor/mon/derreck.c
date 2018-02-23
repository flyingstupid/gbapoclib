/* YOUNG DERRECK*/
/* Author:DarkBringer */
/* 04-26-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Derreck");
  set_name("derreck");
  set_alias("derreck");
  set_race("halfling");
  set_long(
"Derreck is a small halfling child. He only stands two and a half\n"+
"feet tall and couldn't possibly weigh more than fourty pounds. He \n"+
"has long black hair that he wears in a top knot. People find his\n"+
"impish features irresistable. \n");

  set_gender(1);
  set_level(8);
  set_ac(7);
  set_wc(12);
  set_al(10);

  add_money(200 + random(150));
  add_class("fighter");

  load_chat(5, ({"Derreck says: I'm just so cute.\n",
"Derreck whistles happily.\n",
    }));

  load_a_chat(5,({"Derreck says: Hey! You can't do that to a kid!..\n",
"Derreck says: I'm telling!\n",
"Derreck looks at you with suprise and shock.\n",
    }));


  }
