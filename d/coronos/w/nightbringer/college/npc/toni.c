/* TONI.C
   Author:DarkBringer
   05-04-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Toni Brightblade");
  set_name("toni");
  set_race("human");
  set_long(
"Toni is a distant descendant of the long Solamnic Knight, Sturm\n"+
"Brightblade. She is very proud of her heritage, and wants to see\n"+
"the Knights resurface.\n");

  set_gender(8);
  set_level(7);
  set_ac(6);
  set_wc(11);
  add_money(250 + random(50));
  set_hp(110);
  set_max_hp(110);
  set_al(1000);
  add_class("cleric");
  load_spells(20,({ "cure light wounds", "bless", "curse", "prayer", }));



  load_chat(5, ({"Toni says: The Solamnic Knights will rise again.\n",
    "Toni says: My great, great, great grandaddy was a hero.\n",
    "Toni studies her school work intently.\n",
    }));

  load_a_chat(5,({"Toni sighs with frustration.\n",
    "Toni says: Leave me be.\n",

    }));


  }
