#include <mudlib.h>
inherit MONSTER;

void make_items();
void reset(status arg) {
    ::reset(arg);
    if(arg) make_items();

    else {
	set_name("baatezu");
	set_alias("demon");
	set_al(-1000);
	set_short("A baatezu demon");
	set_long(
	  "A demon that looks like a baatezu.\n"
	);
	set_gender(0);
	set_race("demon");
	add_class("mage");
	add_class("cleric");
	add_class("fighter");
	load_spells(30,({ 
	    "heal", "cure light wounds", "cure serious wounds", "poison",
	    "lightning bolt", "chain lightning", "bbb", 
	    "fire ball", "fire shield", "chill touch", "death spell",
	    "disintegrate", "ice storm", "comet", "meteor swarm",
	    "energy drain", "burning hands", "curse", "bless",
	    "mks", "monster summon 1", "monster summon 2", "monster summon 3",
	  }));
	add_spell_immunity("fire");
	add_spell_immunity("poison");
	add_spell_immunity("cold");
	set_level(2);
set_aggressive(1);
	set_hp(3000);
	set_magic_resist(55);
load_chat(50,({
"Baatezu growls fiercely.\n",
"Baatezu flares at the nostrils demonically.\n",
"Baatezu howls in an eerie, demonic tone.\n",
	  }));
load_a_chat(50,({
"Baatezu grabs you by the throat and sinks its teeth in.\n",
"Baatezu brings in friends from the levels of hell.\n",
	  }));
    }
}

void make_items() {
    if(!present("robes")) {
	move_object(clone_object("room/city/obj/grobe"),this_object());
	command("wear robes", this_object());
    }
set_wc(5);
set_ac(5);
}
