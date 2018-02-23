/* LADY ANVALON*/
/* Author:DarkBringer */
/* 04-26-97 */


#include <mudlib.h>
inherit MONSTER;

reset(status arg){

  ::reset(arg);

  if(!present("gown")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/armour/wgown.c"),this_object());
    init_command("wear robes");
    }
if(arg) return;


  set_short("Lady Anvalon");
  set_name("lady anvalon");
  set_alias("anvalon");
  set_race("human");
  set_long(
"Lady Anvalon is a priestess of the All-God. She is a devout follower.\n"+
"She stands five and a half feet tall and carries herself with the\n"+
"bearing of royalty. She has long, coal black hair that she keep pulled\n"+
"backed in a tight braid. \n");

  set_gender(2);
  set_level(15);
  set_ac(12);
  set_wc(20);
  set_al(1000);

  add_money(700 + random(300));
  add_class("cleric");

  load_spells(40,({ "cure serious wounds", "bless", "curse",
              "earthquake", "disease",
             }));

  load_chat(5, ({"Lady Anvalon says: May the All-God bless you.\n",
"Lady Anvalon says: I shall dispel the evil creatures who are frightning\n"+
"Lady Penor.\n",
    }));

  load_a_chat(5,({"Lady Anvalon says: My child, anger is not the answer.\n",
"Lady Anvalon says: The All_God can help you find peace, please worship\n"+
"with me.\n",
    }));


  }
