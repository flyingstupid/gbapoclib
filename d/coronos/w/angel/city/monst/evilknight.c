#include <mudlib.h>
#define OBJ "d/coronos/w/angel/city/obj/"
inherit MONSTER;

object sword;
void reset(status arg) {
  ::reset(arg);

  if(arg) return;


  set_name("Sir Evergard");
  set_alias("evergard");
  set_short("Sir Evergard, High-knight of Tiamut");
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
"Evergard is the first priest in the order of Darkness. Such priests \n"+
"are a military lot, following the ways of knights and of darkness.  \n"+
"Evergard is Tiamut's most devout follower, and may admit you to the \n"+
"order, if you prove yourself worthy of Her power.\n");



  load_chat(10, ({
"Sir Evergard says: Worship the mighty Tiamut.\n",
"Sir Evergard looks upon you with casual regard.\n",
"Sir Evergard asks: Do you worship the Queen of Darkness?\n",
"Sir Evergard polishes his armour.\n",
"Sir Evergard smiles at the image of his deity.\n",
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
}

