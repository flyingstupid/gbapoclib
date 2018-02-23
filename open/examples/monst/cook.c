#include <mudlib.h>
inherit MONSTER;

object spoon, apron;

void reset(status arg) {
  ::reset(arg);

  if(!present("spoon")) {
    spoon = clone_object(TREASURE);
    spoon -> set_name("spoon");
    spoon -> set_short("A spoon");
    spoon -> set_long(
	"A fine old wooden spoon, used for stirring stew.\n");
    spoon -> set_weight(1);
    spoon -> set_value(10);
    spoon -> set_sell_desturct(1);
    move_object(spoon, this_object());
  }

  if(!present("apron")) {
    apron = clone_object(CLOTHING);
    apron -> set_name("apron");
    apron -> set_short("A leather apron");
    apron -> set_long(
	"A dirty leather apron. It looks well used.\n");
    apron -> set_weight(1);
    apron -> set_value(100);
    move_object(apron, this_object());
    init_command("wear apron");
  }

  if(arg) return;

  set_name("gadrian");
  set_short("Gadrian, the cook");

  set_long(
"Gadrian has been the head cook here within the university \n"+
"for several years now, and knows each student and master  \n"+
"of magic by name, and by their favourite desert and meal. \n");
  set_gender(1);
  set_level(11);
  set_max_hp(200);
  set_hp(200);

  set_wc(15);
  set_ac(9);
  load_chat(5, ({
	"Gadrian smiles happily.\n",
	"Gadrian stirs some stew.\n",
	"Gadrian asks: Have you come for something to eat?\n",
	"Gadrian says: I havent seen you here before.\n",
	"Gadrian tends to some vegetables.\n",
	"Gadrian reads his cook book.\n",
  }));

  load_a_chat(5, ({
	"Gadrian exclaims: Get out of my kitchen!\n",
	"Gadrian exclaims: Thief! Thief! Thief!\n",
	"Gadrian exclaims: Youre stealing my food arent you!\n",
  }));
}
