#include <mudlib.h>
#define OBJ "d/coronos/w/angel/city/obj/"
inherit MONSTER;

object sword;
void reset(status arg) {
  if(!present("broadsword")) {
    sword = clone_object(OBJ+"defender");
    move_object(sword, this_object());
  }
  ::reset(arg);

  if(arg) return;


  set_name("thorbest");
  set_short("Captain Thomas Thorbest");
  set_alias("captain");
  set_race("human");
  set_gender(1);
  set_level(55);
  set_max_hp(2000);
  set_hp(2000);

  set_magic_resist(50);
  add_spell_immune("fear");
  add_spell_immune("charm");
  add_spell_immune("fire");
  add_spell_immune("death");
  add_spell_immune("cold");
  add_spell_immune("lightning");

  set_long(
"Thorbest is tall, and well muscled, with strong features and a        \n"+
"short cut beard, contrasted with blue roguish eyes; a man of high     \n"+
"morals and high standing within the church of Saint Arion. A military \n"+
"man for many years he tends not to fair well outside the comfort of   \n"+
"the men who he leads. Thomas is, however, a good and just man, who    \n"+
"always strives for justice, law and order. Foolishness is often looked\n"+
"down upon, accept, of course, if it is within the confines of a       \n"+
"pleasant country inn, where the food is hot, and the ale refreshing.  \n"+
"Thorbest carries the portfolio of internal security within Ille       \n"+
"Coronos, and heads the black guard with Curzon Bain.\n");


  load_chat(10, ({
"Thorbest says: Do you know the might of St. Arion?\n",
"Thorbest exclaims: You are a puny one, arent you!\n",
"Thorbest asks: What are you doing here?\n",
"Thorbest says: I hope that is not illegal.\n",
"Thorbest asks: Have you seen Curzon?\n",
"Thorbest says: I am proud to serve St. Arion.\n",
"Thorbest asks: Will you join me in a drink?\n",
"Thorbest says: Where is that scoundrel DiIllan?\n",
"Thorbest says: Give me one good reason why I should not lock you up.\n",
"Thorbest says: Dark Elves have no honour.\n",
"Thorbest asks: Are you one who follows the great St. Arion?\n",
"Thorbest polishes his broadsword.\n",
"Thorbest says: The best weapon is a broadsword, all else is inferior.\n",
"Thorbest says: All honour is gained in battle.\n",
"Thorbest says: All glory in war is to St. Arion.\n",
  }));

  load_a_chat(10, ({
"Thorbest says: By St. Arions arm you fight well.\n",
"Thorbest says: With St. Arion by my side I shall be victorious.\n",
"Thorbest says: War is the flowering of manhood.\n",
"Thorbest says: You are too puny for the might of my blade.\n",
"Thorbest exclaims: You have little honour!\n",
"Thorbest says: Leave now before I slay you.\n",
  }));

  add_class("cleric");
  add_class("fighter");

  load_spells(75, ({
	"heal", "cure light wounds", "cure wounds", "cure critical wounds",
	"death curse", "earthquake", "barkskin", "bless", "curse",
	"fire storm", "prayer", "holy word", "harm", "holy strike",
	"cause wounds", "cause light wounds", "cause serious wounds",
	"call lightning", "cause blindness", "poison", "sts", 
	"slay living", "star burst",
  }));
  set_dead_ob(this_object());
  set_domain("coronos");
}

void monster_died() {
  tell_room(environment(), 
"Thorbest offers up a prayer to St. Arion.\n"+
"Thorbest says: The honour is yours, farewell, until we meet \n"+
"again before the throne of the Mighty St. Arion.\n");
}

