#include <mudlib.h>
inherit MONSTER;

reset (arg) {
  ::reset(arg);
  if(arg) return;
  set_level(3);
  set_name("mouse");
  set_short("Large brown mouse");
  set_long("This mouse looks larger and meaner than his companions.\n"+
     "It has a ruby inlaid ring around its neck.\n");
  set_hp(60);
  set_wc(7);
  set_ac(4);
  set_al(-50);
  set_dead_ob(this_object());
}

monster_died() {

string NAME, ob;
object ME, house, bag, dagger, woman, *inv;
int i;

  ME = this_player();
  NAME = ME->query_name();
  house = "/d/tempus/w/serepion/house.c";
  inv = all_inventory(ME);
  for(i=0; i < sizeof(inv); i++) {
     ob = inv[i]->query_name();
     if(ob == "cloth" || ob == "match" || ob == "stick" || ob == "food") {
       destruct(inv[i]);
     }
  }
  tell_object(ME, "As soon as the mouse dies, you grab the ring, and pull it off.\n");
  tell_object(ME, "You step through the mouse hole, and grow rapidly.\n");
  tell_object(ME, "The woman seems very happy to see you.\n");
  tell_object(ME, "The woman asks for proof of the demise of the mice.\n");
  tell_object(ME, "You hand the ring to the woman, and she smiles happily.\n");
  tell_object(ME, "The woman hands you a bag, and says: This is all I can give.\n");
  bag = clone_object("/d/tempus/w/serepion/obj/bag.c");
   dagger = clone_object("d/tempus/w/serepion/obj/dagger.c");
  move_object(dagger, bag);
  move_object(bag, ME);
  ME->move_player("#/d/tempus/w/serepion/house.c");
  house->say("The old woman is happy, as "+NAME+" appears in the house.\n");
  house->say("The old woman asks "+NAME+" for something, which they hand to her.\n");
  house->say("The woman is overjoyed, and hands "+NAME+" a small bag.\n");
  tell_room("/d/tempus/w/serepion/house.c", "The old woman leaves the house to enjoy the day.\n");
  call_other("/d/tempus/w/serepion/house.c", "done");
}
