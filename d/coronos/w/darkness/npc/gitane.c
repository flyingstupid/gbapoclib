#include <mudlib.h>
inherit MONSTER;

void init() {
  call_out("chat",1);
  ::init();
}

void reset(status arg) {
  if (arg) {
  return;
  }

  ::reset(arg);
  set_name("Gitane");
  set_alias("shop keeper");
  set_short("Lady Gitane, the Gypsie.");
  set_long(
    "A young woman standing behind the half oval desk.  She is tall and\n"+ 
    "slender, filled with a lithe grace.  Her most striking feature is her\n"+
    "long white hair that falls lightly down her back, curling at her waist.\n"+
    "It contrasts with her soft, olive skin and her slanted, midnight eyes.\n"+ 
    "Her level gaze is as deep as evening pools, penetrating and radiating\n"+ 
    "calm.  She is dressed in a dark burgandy skirt that brushes the floor,\n"+
    "and a white blouse that hangs loosly at the sleeves. A burgandy cloak\n"+
    "is draped lightly upon her shoulders.  An enigmatic aura surrounds the\n"+
    "keeper of this quiet candle shop.\n");

  load_chat(1, ({
    "Gitane says to you, 'Welcome to The Dancing Flame.'\n",
    "Gitane asks politely, 'Can I be of any assistence?'\n",
    "Gitane watches you silently from behind the desk.\n",
    "Gitane takes a deep breath, smelling the armoas that permiate the shop.\n", 
    "Gitane comments 'We have some beautiful candles in stock.'\n",
    "Gitane adjusts her burgandy cloak ever so slightly.\n", 
    "Gitane brushes her long hair back from her face.\n",
    }));

  set_al(275);
  set_level(15);
  add_class("thief");
  set_steal_chance(90);
  set_wc(20);
  set_ac(24);
  set_max_hp(350);
  set_hp(350);
  set_money(1600);
  set_gender(2);
  set_race("half elf");


if (!present("cloak")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/items/gcloak"),
    this_object());
    command("wear cloak");
  }
}
/*Newstar & Darkness 97*/
