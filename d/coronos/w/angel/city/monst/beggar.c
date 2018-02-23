#include <mudlib.h>
#define OBJ	"d/coronos/w/angel/city/obj/mace"

inherit MONSTER;

object food, nicePerson;

void food_check();
void thank_nicePerson();

void reset(status arg) {
  object cup;
  ::reset(arg);

  nicePerson = 0;
  if(!present("cup")) {
    cup = clone_object(TREASURE);
    cup -> set_name("cup");
    cup -> set_short("A cup");
    cup -> set_plural("cups");
    cup -> set_long(
	"A simple wooden cup. It looks very old.\n");
    cup -> set_value(10);
    cup -> set_sell_destruct(1);
    move_object(cup, this_object());
  }    


  set_name("beggar");
  set_short("A hungry beggar");
  set_long(
	"This hungry man is hardly wearing any clothes, and sits\n"+
	"by the side of the road with a cup in his hands. His   \n"+
	"tired old weathered face looks up at you with hope.    \n");

  load_chat(10, ({ "Beggar says: Hello there.\n",
	"Beggar asks: Can you spare me some food?\n",
	"Beggar asks: What's your name?\n",
	"Beggar's tummy rumbles.\n",
	"Beggar looks hungrilly at you.\n",
	"Beggar says: I haven't eaten for days.\n",
	"Beggar says: I can't recall when the last time I ate was.\n",
	"Beggar asks: Can you spare an old man some food?\n",
	"Beggar says: Please, can you help me?\n",
	"Beggar looks hungry.\n",
	"Beggar sighs sadly.\n",
  }));

  add_class("thief");
  add_class("fighter");
  set_level(3);
  set_gender(1);
  set_race("human");

  load_a_chat(7, ({ "Beggar cries out for help!\n",
	"Beggar exclaims: You beast!\n",
	"Beggar says: The Black Guard will have your hide.\n",
	"Beggar tries to run away!\n",
	"Beggar cries out in pain.\n",
  }));	

  add_money(5 + random(10));

}

void catch_tell(string str) {
  string tmp1, tmp2, tmp3;
  
  if(sscanf(str, "%s gives you %s\n", tmp1, tmp2)) {
    nicePerson = this_player();
    call_out("food_check", 2);
    return;
  }
  ::catch_tell(str);
}

void food_check() {
  int i;
  object *inv;

  inv = all_inventory(this_object());

  for(i=0; i<sizeof(inv); i++) {
    if((string)inv[i]->query_object_type() == "Food") {
      tell_room(environment(), "Beggar smiles happily.\n"+
	"Beggar eats "+inv[i]->query_short()+".\n");
      destruct(inv[i]);
      if(!present(nicePerson, environment()))
        nicePerson = 0;
      else
        call_out("thank_nicePerson", 1);
      return;
    }
  }
}

void thank_nicePerson() {
  if(!present(nicePerson, environment())) {
    nicePerson = 0;
    return;
  }

  tell_room(environment(), "Beggar exclaims: Thank you "+
	nicePerson->query_name()+".\n");
  tell_object(nicePerson, "Begger gives you a mace.\n");
  say("Beggar gives "+nicePerson->query_name()+" a mace.\n", nicePerson);
  move_object(clone_object(OBJ), nicePerson);
  nicePerson->recalc_carry();
  
  this_object()->set_short("A happy beggar");
  this_object()->set_long(
	"This happy man is hardly wearing any clothes, and sits \n"+
	"by the side of the road with a cup in his hands. His old\n"+
	"weathered face looks up at you with the joy of a happy man.\n");
  this_object()->load_chat(10,
	({ "Beggar smiles.\n",
	   "Beggar smiles happily.\n",
	   "Beggar pats his full tummy.\n",
	   "Beggar says: Some nice person gave me some food.\n",
	   "Beggar says: Let the All-God be praised.\n",
	   "Beggar says: The All-God has answered my prayers, someone \n"+
	   "		 gave me some food to fill my belly.\n",
	}));
  return;
}
      
