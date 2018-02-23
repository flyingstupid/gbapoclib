#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
object pajamas;

  if (arg) {
  return;  
  }
 
  ::reset(arg);
  set_name("guard");
  set_short("a City Guard");
  set_long(
    "This city guard looks quite groggy, as if he had just waken\n"+
    "from sleep.  His hair is a mess and he is still wearing his\n"+
    "pajamas.  He has a blank look on his face and his eyes are\n"+
    "barely open.\n");
  load_chat(1, ( {
    "The guard yawns.\n",
    "Guard: Is somebody there?\n",
    "The guard rubs his eyes.\n",
    "The guard scratches himself.\n",
    "Guard: I'll be ready in a sec, commander...\n",
    }));
  load_a_chat(20, ( {
    "Guard: Wha...Wha... What's going on?!\n",
    "Guard: Somebody help!\n",
    "Guard: What do you think you're doing?!\n",
    "The guard looks very confused and shocked.\n",
    "The guard is taken by surprise.\n",
    })); 
 
  set_al(50);
  set_level(5);
  set_gender(1);
  set_race("human");
  add_class("fighter");
  set_max_hp(75);
  set_hp(75);
  set_wc(9);
  set_ac(5);
  set_money(random(200)); 

  if(!present("pajamas")) {
    pajamas = clone_object(CLOTHING);
    pajamas -> set_name("pajamas");
    pajamas -> set_plural("pairs of pajamas");
    pajamas -> set_weight(2);
    pajamas -> set_value(130);
    pajamas -> set_sell_destruct(1);
    pajamas -> set_short("a pair of old pajamas");
    pajamas -> set_long("A pair of old pajamas.\n");
    move_object(pajamas, this_object());
    init_command("wear pajamas");
  }
}

void catch_tell(string str) {
  return;
}
