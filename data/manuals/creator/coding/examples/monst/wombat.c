#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
    ::reset(arg);
    if(arg) return;
    set_name("wombat");
    set_short("A large wombat");
    set_long(
      "A furry, chubby critter that seems to be scanning the ground \n"+
      "before him with little squinted eyes. His fur is a light brown \n"+
      "and full of dirt. He moves with a slight waddle and occasional \n"+
      "soft grunt.\n");
    set_gender(1);     
    set_level(3);
    set_race("marsupial");
    set_wc(6);
    set_ac(4);
    set_hp(60);
    load_chat(6, ({"Wombat searchs the ground.\n",
	"Wombat bumps his nose on a rock he didn't see.\n",
	"Wombat begins to dig at the ground with long, "+
	"sharp claws.\n",
	"Wombat begins to dig at the earth with long, sharp claws \n"+
	"but seems to loose interest quickly and stops.\n",
      }));
    set_domain("garden");
    load_a_chat(7,({"Wombat tries to dig a quick burrow for escape!\n",
	"Wombat rips at your legs with sharp claws.\n",
      }));
    set_dead_ob(this_object());
}
void monster_died() {
    object obj;
    tell_room(environment(), "Wombat falls over with a thud!\n");
}

