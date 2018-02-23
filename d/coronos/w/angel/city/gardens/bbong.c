#include <mudlib.h>
#define PATH	"d/coronos/w/angel/city/gardens/"
inherit ROOM;

void monster_died();
void reset(status arg) {
  object obj;
  if(!present("bunyip")) {
    obj = clone_object(MONSTER);
    obj -> set_name("bunyip");
    obj -> set_level(6);
    obj -> set_short("A bunyip");
    obj -> set_long(
               "This creature is huge, bearing a resemblance to a mixture\n"+
               "between a platypus, an crocodile, and something large and\n"+
               "pink! ");  /* alexander the bunyip - but a mean one */
    obj -> set_race("bunyip");
    obj -> set_aggressive(1);
    obj -> set_hp(150);
    obj -> set_wc(10);
    obj -> set_ac(6);
    obj -> load_a_chat(10,({ "Bunyip says: Get out of my billabong!\n",
               "Bunyip says: Go away!\n",
               "Bunyip says: Leave me alone!\n",
               "Bunyip says: it's my billabong!\n",
               "Bunyip says: Leave my billabong!\n",
            }));
    obj -> add_spell_immunity("water");
    obj -> add_spell_immunity("cold");
    obj -> add_spell_immunity("poison");
    obj -> load_spells(10,({ "cure wounds", "bless", }));
    obj -> set_dead_ob(this_object());
    obj -> add_class("cleric");
    obj -> add_class("thief");
    obj -> add_class("fighter");
    move_object(obj,this_object());
  }

  if(arg) return;
  set_weather(1,4,6); /* sea is as close to water as i can get */
  set_short("a billabong");
  set_long(
     "The waters of the billabong are nice and cool; a refreshing change\n"+
     "from the days troubles. \n");
  set_exits(({
	PATH+"garden7", "shore",
  }));
}

void monster_died() {
  object obj;

  tell_room(this_object(),
     "As bunyip dies the illusion covering his treasure dissapears.\n");

  obj = clone_object(MONEY);
  obj -> set_money(100 + random(250));
  move_object(obj, this_object());  

  obj = clone_object(ARMOUR);
  obj -> set_name("ring");
  obj -> set_type("ring");
  obj -> set_short("A golden ring");
  obj -> set_long(
          "A beautiful ring set with a few small precious stones, \n"+
          "that glow a soft blue light. Perhaps its magical?\n");
  obj -> set_arm_light(1);
  obj -> set_ac(1);
  obj -> set_info(
     "The ring is magical and confers special protection on the wearer.\n"+
     "The gems also glow a magic soft blue colour, equal to torch light.\n");
  obj -> set_weight(4);
  obj -> set_value(200); /* because it has light */
  obj -> set_enchanted(1);
  obj -> set_sell_destruct(1);
  move_object(obj, this_object());

  obj = clone_object(WEAPON);
  obj -> set_name("handaxe");
  obj -> set_alias("axe");
  obj -> set_short("A small axe");
  obj -> set_long(
          "A simple hand axe carved from the wood of a mountain ash.\n"+
          "The blade is made of some strong steel and looks quite sharp.\n");
  obj -> set_type("cleave");
  obj -> set_wc(9); /* +1 handaxe */
  obj -> set_weight(5);
  obj -> set_value(320);
  move_object(obj, this_object());
}
