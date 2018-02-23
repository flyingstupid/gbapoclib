#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
    ::reset(arg);
    if(arg) return;
    set_name("scorpion");
    set_short("a little scorpion");
    set_long(
      "This tiny scorpion has a nasty stinger on the end of it's tail.\n");
    set_gender(1);
    set_race("reptile");
    load_chat(5, ({
	"Scorpion raises his tail toward you.\n",
	"Scorpion nips at your toes.\n",
      }));

    load_a_chat(5, ({
	"Scorpion tries to sting you!\n",

	"Scorpion tries to nip you!\n",
      }));

    set_attack_msg(({
	"misses", "with his pincers",
	"nips", 
	"pinches",
	"scrapes",
	"stings", "with his tail",
	"pierces", "with his tail",
	"gouges", "with his pincers",
      }));

    set_level(1);
}

