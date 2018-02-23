#include <mudlib.h>
#define OBJ "d/coronos/w/angel/city/obj/"
inherit MONSTER;

object sword;
void reset(status arg) {
  ::reset(arg);

  if(arg) return;


  set_name("Running Bear");
  set_alias("bear");
  set_alt_name("running bear");
  set_short("Running Bear, of the Werebear clan");
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
"Running Bear is the first son of the chieftan of the clan Werebear.\n"+
"From his sheer size and muscle you assume he is also the strongest \n"+
"and most brave warrior of the whole tribe. His dress is simple, wearing\n"+
"moccasins and brown leather pants. He wears no shirt so that the sun \n"+
"tans his dark skin. Running Bear has been known to teach other clan\n"+
"members how to fight and how to kill. Perhaps he will also train you?\n");



  load_chat(10, ({
	"Running Bear says: Hello to you.\n",
	"Running Bear asks: Do you have the heart of the Bear spirit?\n",
	"Running Bear asks: Do you have the courage of the Bear spirit?\n",
	"Running Bear says: I am from the Werebear clan.\n",
	"Running Bear says: You look to weak, you should train with me.\n",
	"Running Bear says: I will teach you how to be strong.\n",
	"Running Bear says: I am here to help you, little bear.\n",
  }));




  add_class("thief");
   add_class("ranger");
  add_class("fighter");

}

