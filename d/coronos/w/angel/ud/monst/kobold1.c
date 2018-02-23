#include <mudlib.h>
#define OBJ	"d/coronos/w/angel/ud/obj"

inherit MONSTER;

void reset(status arg) {
  if(!present("bag")) 
    move_object(clone_object("objects/bag"), this_object());
  if(!present("torch"))
    move_object(clone_object("objects/torch"), this_object());

  if(!present("rope"))
    move_object(clone_object("objects/rope"), this_object());
  

  ::reset(arg);
  if(arg) return;

  set_name("kiass");
  set_short("Kiass, the kobold");
  set_long(
	"Kiass is the servant, and general dogs body for the drow who \n"+
	"patrol this cave system. He also serves the orc guards lets  \n"+
	"they beat him up also. He looks harmless enough, but appearances\n"+
	"can be deceptive.\n");

  set_race("kobold");
  set_level(5);
  set_wander(50, 600);
  set_domain("ud");

  add_class("thief");
  add_class("fighter");
  add_spell_immunity("cold");
  load_chat(2, ({
	"Kiass asks: Who are you?\n",
	"Kiass says: Youre not one of the drow masters.\n",
  }));

  load_l_chat(5, "kobold", ({
	"Do you have a scorpion?",
	"I love to eat scorpions, especially the claws!\n",
  }));
}

void init() {
  ::init();
  add_action("give_me", "give");
}

status give_me(string str) {
  string tmp1, tmp2;
  object ob, key;

  if(!str) return 0;
  if(sscanf(str, "claw to%s", tmp1, tmp2)) {
    if(ob=present("claw", this_player())) {
      if(ob->id("scorpion") && ob->id("claw") && !ob->id("illusion")) {
        tell_room(environment(), 
	"Kiass exclaims: Thanks a lot! I love scorpions claws!\n");
        tell_object(this_player(), "Kiass gives you a key.\n");
  	say("Kiass gives "+this_player()->query_name()+" a key.\n", this_player());
  	key = clone_object(OBJ+"/key");
  	move_object(key, this_player());
  	destruct(present("claw", this_player()));
  	this_player()->recalc_carry();
        return 1;
 
      }
    }
  }     
  return 0;
}
