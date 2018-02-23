inherit "/players/relgar/temple/crypt/demons/baatezu.c";

void make_items();
void reset(status arg) {
    ::reset(arg);
    if(arg) make_items();

    else {
	set_name("spinagon");
	set_alias("winged spinagon");
	set_short("A winged spinagon");
	set_al(-1000);
	set_long(
	  "        The smallest demon you've seen, this Spinagon looks much like a \n"+
	  "gargoyle. It is a small humanoid with wings and a spiked tail. It has   \n"+
	  "long razor-sharp talons extending from its feet.\n"
	);
	set_gender(0);
	set_race("demon");
	add_class("mage");
	add_class("cleric");
	add_class("fighter");
	load_spells(30,({ 
	  }));
	add_spell_immunity("fire");
	add_spell_immunity("poison");
	add_spell_immunity("cold");
	set_level(2);
	set_aggressive(1);
	set_hp(3000);
	set_magic_resist(55);
	load_chat(50,({
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
