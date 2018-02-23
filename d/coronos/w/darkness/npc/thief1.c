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
  set_name("Mic");
  set_alias("thief");
  set_short("Mic the rogue");
  set_long(
    "This human is a young man.  He wears old clothes and\n"+
    "boots.  His eyes stay trained on his partners as they\n"+
    "count their loot.\n");
  load_chat(5, ({
    "Mic watches his partners.\n",
    "Mic counts his share of the loot.\n",
    }));
 
  load_a_chat(40, ({
    "I'm gonna kill you!\n",
    "You'll pay for that!\n",
    "Ouch!\n",
    "Fight fair!\n",
    "You're not taking my coins!\n",
    }));
  set_al(-100);
  set_level(6);
  set_gender(1);
  set_race("human");
  add_class("thief");
  add_money(250);
 
}
