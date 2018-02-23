#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
    ::reset(arg);


    if (arg) return;

    set_name("squirrel");
    set_short("A squirrel");
    set_plural("squirrels");
    set_long(
      "A small, tree dwelling rodent with a slender body, heavy fur, a long, \n"+
      "bushy tail and large prominent eyes.\n");
    set_level(1);
    set_dexterity(15);
    set_alignment(50);
    set_race("mammal");
    set_gender(random(2) + 1);
    set_attack_msg(({
	"misses", "\b.",
	"scatches", "slightly with its claws",
	"nips", "with sharp teeth",
	"draws blood from", "with nasty claws",
	"bites", "hard with its wicked teeth",
	"leaps on", "trying to bite your neck",
      }));

}

