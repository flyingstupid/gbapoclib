#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("koala");
  set_short("A cuddly koala");
  set_long(
    "This little warm and cuddly creature sits here eating away \n"+
    "at the gum leaves in the tree, which are its only source of \n"+
    "food. This little critter looks like he needs a cuddle!\n");
  set_gender(random(2) + 1);
  set_level(1);
  set_race("marsupial");
  set_wc(5);
  set_ac(3);
  set_hp(50);
  load_chat(5,({ "Koala smiles sleepily.\n",
    "Koala reaches out for a cuddle.\n",
    "Koala gives you a cuddle.\n",
    "Koala snuggles up to you.\n",
    "Koala looks down at the ground way below.\n",
    "Koala munches on some nearby gum leaves.\n",
    "Koala dozes off.\n",
    "Koala snores as it falls off to sleep.\n",
  }));
  set_domain("garden");
  load_a_chat(9,({ "Koala cries out in pain!\n",
    "Koala tries to climb up high in the tree.\n",
    "Koala tries to climb down the tree to get away.\n",
    "Koala cries helplessly.\n",
   }));
   set_dead_ob(this_object());
  set_wander(10,360);
  set_domain("tree");
  move_object(clone_object("obj/soul"),this_object());
}

void monster_died() {
  object obj;
  tell_room(environment(), "Koala falls out of the tree.\n");
  obj = present("corpse");
  if(obj) destruct(obj);
}

void init() {
  ::init();
  add_action("cuddle", "cuddle");
  add_action("cuddle", "kiss");
  add_action("cuddle", "french");
  add_action("cuddle", "snuggle");
  add_action("cuddle", "hug");
}

void cuddle(string str) {
  string tmp1, tmp2;
  string name;
  string verb;
  verb = query_verb();
  name = lower_case((string)this_player()->query_name());
  if(!random(5)) name += " sleepily";
  if(sscanf(str, "%skoala%s", tmp1, tmp2)) 
    command(verb+" "+name, this_object());
}
