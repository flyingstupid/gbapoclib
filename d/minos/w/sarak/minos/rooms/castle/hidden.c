#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

object prince, sword;

void reset(status arg) {
  if (!present("radagast")) {
    /* Radagast's Definition */
    prince = clone_object (MONSTER);
    prince->set_name("radagast");
    prince->set_alias("prince");
    prince->set_short("Radagast the Evil Prince");
    prince->set_long( 
	"This is the Evil Minotaur Prince. He is very evil and very angry\n"+
	"with you for waking him up!!\n");
    prince->set_level(13);
    prince->set_gender(1);
    prince->set_race("minotaur");
    prince->set_ac(10);
    prince->set_hp(260);
    prince->set_max_hp(260);
    prince->set_al(300);
    prince->add_money(250);
    move_object(prince, this_object());
    
    /* Weapon definition */
  
    sword = clone_object(WEAPON);
    sword->set_name("bastardsword");
    sword->set_short("A jewel encrusted bastardsword");
    sword->set_long( 
		"This sword was taken from the Evil Minotaur Prince.\n"+
		"He was probably killed when someone woke him up!\n");
    sword->set_length(54);
    sword->set_weight(5);
    sword->set_wc(16);
    sword->set_type("cleave");
    sword->set_value(3500);
    move_object(sword, prince);
    
    prince->init_command("wield sword");
    prince->set_wc(17);
  }
  
  if(!arg) {
    set_short("Evil Prince's Room");
    set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You have stumbled into the evil prince's room. This is where he sleeps\n"+
"and hides from those he has stolen from. This room has been neglected\n"+
"compared to the other sections of the castle. There is also a bed here.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    set_weather(2,2,0);
    set_items(({
      "lever",  "Perhaps if you were to pull it...",
      "bed", "This is where Radagast sleeps. It provides a good place to hide",
    }));
  }
}


void init() { 
  ::init();
  add_action("pull", "pull"); 
  add_action("hide", "hide");
}

status pull(string lev) {
  if (!lev) {
    notify_fail("Pull what\n");
    return 0;
  }
  if (lev == "lever") {
    if (!present("prince")) {
      say (this_player()->query_name()+" pulls the lever and is returned to "+
		"the castle.\n");
      write(
      "You pull the lever. A grinding noise comes from within the walls as\n"+
      "they begin to move! The whole wall turns around taking you with it!\n"+
      "You are thrown to the ground as the wall stops abruptly to turn back\n"+
      "to it's original position.\n");
    this_player()->move_player("#"+CASTLE_ROOMS+"entrance");
      return 1;
    }
    else {
      write  ("The prince will not let you leave!!\n");
      return 1;
    }
  }
  notify_fail("Pull what?\n");
  return 0;
}
    
    
status hide(string jmp) {
  string what;
  if (!jmp) {
    notify_fail("Hide where?\n");
    return 0;
  }
  if (!sscanf(jmp, "under %s", what) == 1) {
    notify_fail("Hide under what?\n");
    return 0;
  }
  if (what == "bed" || what == "the bed") {
    if (present("prince")) {
      write("You poke the prince in the eyes and jump under the bed. Once\n"+
             "the prince manages to get his sight back, he looks around but\n"+
             "cannot find you. He stands there waiting anyway...\n");
      say (this_player()->query_name()+" pokes Radagast in the eyes and\n"+
           "jumps under the bed!\n");
    }
    else {
      write ("You quickly jump under the bed.\n");
      say (this_player()->query_name()+" jumps under the bed.\n");
    }
    this_player()->move_player(
      "to hide under the bed#"+CASTLE_ROOMS+"ub");
    return 1;
  }
  else {
    notify_fail("Hide under what?\n");
    return 0;
  }
}
