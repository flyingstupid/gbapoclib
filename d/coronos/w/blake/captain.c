# include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(!present("rapier")) {
    move_object(clone_object("players/blake/rapier"),this_object());
    command("wield rapier");
    }
      
  if(arg) return;
  set_name("Old sea captain");
  set_alias("captain");
  set_alt_name("sea captain");
  set_level(10);
  set_gender(1);
  set_short("Old sea captain");
  set_long(
    "The old sea captain has a large white beard. He is quite old but \n"+
    "must have been very strong and sturdy man in his younger days. He is \n"+
    "now retired and wanders the streets of Ille Coronos.\n");
  set_alignment(50);
  add_money(random(150)+100);
  set_race("human");
  set_wander(50,90);
  load_chat(5, ({
    "The old captain looks dreamily in the sky.\n",
    "Captain looks at you with old tired eyes.\n",
    "Captain asks: Have you seen my cat? \n",
    "Captain says: I was a great sailor once\n",
    "Captain scratches his beard.\n",
}));
   load_a_chat(6, ({ "CCaptain screams: How rude! Hurting an old man like me!\n"
                     "The old captain cries for help.\h"
                     "Captain shouts loudely: Help! HELP!.\n"
                    }));
}
