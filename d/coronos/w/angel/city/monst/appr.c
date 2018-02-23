#include <mudlib.h>
inherit MONSTER;

object spoon, apron;

void reset(status arg) {
  ::reset(arg);

  if(!present("apron")) {
    apron = clone_object(CLOTHING);
    apron -> set_name("apron");
    apron -> set_short("A leather apron");
    apron -> set_long(
	"A very dirty leather apron. It looks well used.\n");
    apron -> set_weight(1);
    apron -> set_value(100);
    move_object(apron, this_object());
    init_command("wear apron");
  }

  if(arg) return;

  set_name("apprentice");
  set_alias("cook");
  set_short("An apprentice cook");

  set_long(
"This apprentice cook looks very busy stirring the cooking \n"+
"stew, chopping vegetables, and doing general cleaning. While\n"+
"he looks pretty nave with respect to cooking, he still looks\n"+
"aggressive with that chopping knife.\n");
  set_gender(1);
  set_race("human");
  set_level(5);
  set_max_hp(80);
  set_hp(80);

  set_wc(9);
  set_ac(5);
  add_class("thief");
  add_class("mage");
  load_spells(5, ({ "magic missile", }));

  load_chat(5, ({
	"Apprentice hurries around the kitchen.\n",
	"Apprentice asks: What do I do now?\n",
	"Apprentice looks around for the head cook.\n",
	"Apprentice hurries to finish his duties.\n",
	"Apprentice asks: Have I finished yet?\n",
	"Apprentice asks: When can I go home?\n",
  }));
}

