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
  set_name("Ray");
  set_alias("thief");
  set_short("Ray the cutpurse");
  set_long(
    "This human is middle aged with graying hair and a beer belly.\n"+
    "He either hasn't showered in a few days, or he's spent the last\n"+
    "hour in the sewers.  He greedily looks over the day's bounty.\n");
  load_chat(5, ({
    "Ray counts his share of the loot.\n",
    "Ray belches.\n",
    })); 
 
  load_a_chat(40, ({
    "I'm gonna kill you!\n",
    "You'll pay for that!\n",
    "Grr! Bad move\n",
    "Take that!\n",
    "You're not taking my coins!\n",
    }));
  set_al(-150);
  set_level(10);
  set_gender(1);
  set_race("human");
  add_class("thief");
  add_class("fighter");
  add_money(700);
 
  if(!present("dagger")){
    move_object(clone_object(
    "/d/coronos/w/darkness/items/dagger1"),
    this_object());
    init_command("wield dagger");
  }
}
