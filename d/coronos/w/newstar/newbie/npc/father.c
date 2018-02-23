/* father.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h> 
inherit MONSTER;

void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("Mr Newman");
  set_alias("father");
  set_short("Mr Newman");
  set_long(
    "This Mr Newman.  He is the head of the family and owns this farm.\n"+
    "He is a young man, in his late twenties.  His brown hair falls in\n"+
    "front of his clean shaven face.  Happy blue eyes show that this is\n"+
    "a man good in nature.  Broad shouldered and strong, this soldier \n"+
    "keeps in shape working on his family's farm.\n");
 
   load_chat(5, ({
    "Mr Newman laughs heartily.\n",
    "Mr Newman smiles happily.\n",
    "Mr Newman takes in a deep breath and smiles happily.\n",
    "Mr Newman looks quite content.\n",
    }));
 
  load_a_chat(40, ({
    "Mr Newman calls for help.\n",
    "Mr Newman fights better then probably expected.\n",
    "Mr Newman prays to the All-god.\n",
    "Mr Newman curses frightfully.\n",
    "Mr Newman yells, 'Why I am being attacked, evil one?'\n",
    }));
 
  set_al(350);
  set_level(8);
  set_wc(11);
  set_ac(6);
  set_max_hp(130);
  set_hp(130);
  set_gender(1);
  set_money(250 +random(100));
  set_race("human");
  add_class("fighter");
 
 if (!present("shortsword")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/sword1"),
    this_object());
    command("wield sword");
  }
}
