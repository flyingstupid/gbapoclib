# include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
    ::reset(arg);
    if(!present("ring")) {
	move_object(clone_object("players/blake/ring"),this_object());
	command("wear ring");
    }
    if(!present("dagger")) {
	move_object(clone_object("players/blake/dagger"),this_object());
	command("wield dagger");
    }

    if(arg) return;
    set_name("Mayor Handlefoot");
    set_alias("mayor");
    set_alt_name("Handlefoot");
    set_level(14);
    set_gender(1);
    set_short("Mayor Handlefoot from Moodin");
    set_long(
      "Mayor Handlefoot is a short and tubby man. Several rings and armbands\n"+
      "are embellishing his fat fingers and hands. He has a purse in his belt\n"+
      "and something tells you that this man can buy almost everything he wants.\n");

    set_alignment(100);
    add_money(random(450)+400);
    set_race("human");
    set_magic_resist(10);
    set_wander(50,90);
    load_chat(5, ({
	"Mayor Handlefoot says: Hello fair traveller.\n",
	"Mayor Handdlefoot looks at you and says: I think you should buy some\n"+
	"new clothes.\n",
	"Mayor Handlefoot polishes some of his rings on his jacket. \n",
	"Mayor Handlefoot asks: Do you have anything to sell, I might be interested?\n",
	"Mayor Handlefoot scratches his nose.\n",
      }));
    load_a_chat(6, ({ "The Mayor screams: I have a bad heart, leave me alone!\n",
	"Mayor Handlefoot bursts into tears.\n",
	"Mayor Handlefoof pants completely exhausted.\n",
      }));
}

