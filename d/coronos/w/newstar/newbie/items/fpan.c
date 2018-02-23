/* NOTE: If you stat the pan, you recieve an illegal weapon
   warning.  This is because the WEAPON is also set as a
   CONTAINER. */

/* fpan.c */
/* Darkness */

#include <mudlib.h>
inherit CONTAINER;
inherit WEAPON;
 
void reset(status arg) {
  if(arg) return;
  set_name("club");
  set_alt_name("frying pan");
  set_alias("pan");
  set_short("a frying pan");
  set_long(
    "The frying pan looks well used, but clean.  It rests on the stove, waiting\n"+
    "to be used again.\n");
  set_max_weight(1);
  set_weight(4);
  set_length(20);
  set_wc(2);
  set_value(32);
  set_sell_destruct(1);
  set_type("crush");
  set_attack_msg(({  
    "missed", "",
    "hit", "hard",
    "smacked", "loudly",
    "bruised", "",
    "smashed", "with a mighty blow",
    "clobbered", "fiercely",
    "bashed", "ferociously",
  }));
}



void init() {
  add_action("cook1", "cook");
  add_action("cook1", "fry");
  add_action("cook1", "crack");
  ::init(); 
}



status cook1(string str) {
  string tmp1, tmp2;

  if(!str) {
  write("What?\n");
  return 1;
  }

  if(sscanf(str, "%segg%s", tmp1, tmp2)) { 
    if(this_player()->query_current_room()==
       "d/coronos/w/newstar/newbie/rooms/house3") {
      if(present("cooked chicken egg", this_object())) {
        write("You have to take the cooked egg out of the pan\n"+
              "before cooking another one.\n");
      }

      else if(!present("chicken egg", this_object())) {
        write("The egg has to be in the frying pan to cook it.\n");
      }

      else if(present("chicken egg", this_object())) {
        object EGG;
        EGG = present("chicken egg", this_object());
        write("You fry the chicken egg in the frying pan.\n");
        say(this_player()->query_name()+" cooks a chicken egg.\n", this_player());
        destruct(EGG); 
        move_object(clone_object(
        "d/coronos/w/newstar/newbie/items/egg2"),this_object());
      }
    }
    if(this_player()->query_current_room()!=
      "d/coronos/w/newstar/newbie/rooms/house3") {
      write("You can not do that here.\n");
    }
  return 1;
  }

  else { 
    return 0;
  }

}
