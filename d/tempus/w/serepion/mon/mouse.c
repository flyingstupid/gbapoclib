#include <mudlib.h>
inherit MONSTER;

object f1, f2, f3;

reset (arg) {
  if(!f1) {
     f1 = clone_object("/d/tempus/w/serepion/obj/food.c");
     move_object(f1, this_object());
  }
  if(!f2) {
     f2 = clone_object("/d/tempus/w/serepion/obj/food.c");
     move_object(f2, this_object());
  }
  if(!f3) {
     f3 = clone_object("/d/tempus/w/serepion/obj/food.c");
     move_object(f3, this_object());
  }
  ::reset(arg);
  if(arg) return;
  set_level(1);
  set_al(-10);
  set_name("mouse");
  set_short("Brown mouse");
  set_long("This is just a normal brown mouse, with one exception. It is\n"+
     "as big as you are! It's teeth and claws seem deadlier than normal.\n");
  set_hp(50);
  set_wc(5);
  set_ac(3);
  set_wander(25,20);
  load_chat(({"A mouse squeaks noisily.\n",
     "A mouse looks around for more food.\n",
     "A mouse sniffs you for food.\n"}));
}
