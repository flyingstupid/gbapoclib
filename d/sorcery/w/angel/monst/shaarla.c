#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  object robe, staff;

  ::reset(arg);

  if(!present("robe")) {
    robe = clone_object("d/coronos/w/angel/city/obj/brobe");
    move_object(robe, this_object());
    init_command("wear robe");
  }


  set_level(20);
  set_name("shaarla");
  set_gender(2);
  set_race("human");
  set_alignment(-1000);
  set_short("Shaarla, the High Mage of the 1st Circle");

  set_magic_resist(75);
  add_spell_immune("death");
  add_spell_immune("fire");
  add_spell_immune("lightning");
  set_long(
"Shaarla is a young wizard, who studied from a young age, and found \n"+
"the ways of the Black Robes to her liking. She is an experienced  \n"+
"wizard who is surely a force to be reckoned with on the battle field.\n"+
"Shaarla is a Black Robe Mage.\n");

  load_chat(5, ({
	"Shaarla asks: What are you doing here?\n",
	"Shaarla says: Be gone. I am studying.\n",
	"Shaarla says: Stop disturbing me.\n",
  }));

  load_a_chat(5, ({
	"Shaarla says: I am a powerful wizard.\n",
	"Shaarla exclaims: Dont fool with a Black Robe mage!\n",
	"Shaarla says: Be gone from my sight.\n",
  }));


  add_class("mage");
  add_class("fighter");

  load_spells(50, ({
	"rope trick", "bbb", "charm", "burning hands", "chain lightning",
	"enchanted weapon", "chill touch", "enlarge", "hold person", "coc",
	"ice storm", "fire ball", "dispel magic", "monster summon 1",
	"monster summon 2", "fire shield", "lightning bolt",
	"energy drain", "shadow door", "msk",
  }));


  set_wander(50, 600);
  set_domain("sorcery/w");
}
