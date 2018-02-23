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
  set_name("Damon");
  set_alias("Lurange");
 
  set_short("Damon Lurange");
  set_long(
    "Damon Lurange looks like a true leader.  His clean cut look eminates\n"+
    "an aura of innosence, but looks can be decieving.  He has a tattoo of\n"+
    "a blade on his arm, and a scar over his left cheek.\n");   
  load_chat(5, ( {
    "Damon grins as he counts the coins.\n",
    "Damon says, 'Be quiet and let me think.'\n",
    }));
  load_a_chat(40, ({
    "How dare you attack me!\n",
    "Feel my blade!\n",
    "So you think you can beat me?\n",
    "You'll regret attacking me.\n",
    }));
  
  load_spells(20, ( {
    "magic missile", "fireball", 
    }));  
 
  set_al(-200);
  set_level(18);
  set_gender(1);
  set_race("human");
  add_class("thief");
  add_class("mage");
  add_class("fighter");
  set_wc(30);
  set_ac(17);
  set_money(300);

  if (!present("gloves")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/items/gloves1"),
    this_object());
    command("wear gloves");
  }
 
  if (!present("sword")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/items/shtswd1"),
    this_object());
    command("wield sword");
  }

  if (!present("bag")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/items/bag1"),
    this_object());
  }
  
}
