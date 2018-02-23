#include <mudlib.h>
inherit MAGIC_SCROLL;

string *Spells, Spell;
void reset(status arg) {
  if(arg) return;

  Spells = ({
	"fire ball", "lightning bolt",
	"magic missile", "cone of cold",
	"energy drain", "warith form",
	"charm monster", "hold person",
	"hold monster",
	"enlarge", "friends",
	"pws", "pwk", "fod",
	"monster summon 1", "monster summon 2", "monster summon 3",
	"shadow door", "vampiric touch", "rope trick",
	"teleport other", "wish",
	"teleport party", "ventriloquism",
	"spell immunity", "shield", "stoneskin",
  });

  Spell = Spells[random(sizeof(Spells)-1)];

  set_name("scroll");
  set_short("A scroll");
  set_long(
	"A scroll with ancient text upon its surface in a flowing \n"+
	"gold and silver script. It looks quite old.\n");
  set_read("The runes are only readable with a detect magic spell.\n");
  set_class(({"mage", }));
  set_cast_level(35); /* that should be able to cast most spells */
  set_charges(100);
  set_max_charges(100);
  add_spell(Spell);
}

  
