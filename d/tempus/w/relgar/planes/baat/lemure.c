inherit "/players/relgar/temple/crypt/demons/baatezu.c";

void make_items();
void reset(status arg) {
    ::reset(arg);
    if(arg) make_items();

    else {
	set_name("lemure");
	set_alias("baatezu");
	set_al(-1000);
	set_short("A Lemure Baatezu");
	set_long(
	  "\tThe lemure is the lowliest denizen of the Nine Hells. Their bodies\n"+
	  "are disgusting blobs of molten flesh, with a vaguely humanoid torso and head.\n"+
	  "Its face is horribly disfigured and molten,molded into a permanent expression\n"+
	  "of horrid anguish. It has claws that it flexes as it looks at you.\n"
	);
	set_gender(0);
	set_race("demon");
	add_class("fighter");
	add_spell_immunity("fire");
	add_spell_immunity("poison");
	add_spell_immunity("cold");
	set_level(2);
	set_aggressive(1);
	set_hp(2+random(18));
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
