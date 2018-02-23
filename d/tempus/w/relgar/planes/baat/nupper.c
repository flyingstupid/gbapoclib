#include <mudlib.h>
inherit MONSTER;

void make_items();
void reset(status arg) {
    ::reset(arg);
    if(arg) make_items();

    else {
	set_name("nupperibo");
	set_alias("demon");
	set_al(-1000);
	set_short("A nupperibo demon");
	set_long(
	  "        Nupperibos are slightly higher in station in the Nine Hells than\n"+
	  "the lemures. It is amorphous, vaguely humanoid in appearance with no    \n"+
	  "discernible features. It has several appendages which might be construed\n"+
	  "as its head and arms. A milky, white film covers its eyes.\n"
	);
	set_gender(0);
	set_race("demon");
	add_class("mage");
	add_class("fighter");
	load_spells(30,({ 
	    "scare",
	  }));
	add_spell_immunity("fire");
	add_spell_immunity("poison");
	add_spell_immunity("cold");
	set_level(14);
	set_aggressive(1);
	set_hp(3000);
	set_magic_resist(55);
	load_chat(50,({
	    "Nupperibo looks about vacantly.\n",
	    "Nupperibo mumbles something incoherently.\n",
	    "Nupperibo hefts its enormous mass around the room in search of prey.\n",
	  }));
	load_a_chat(25,({
	    "Your weapon sinks deeply into the Nupperibos flesh but does no damage.\n",
	    "The nupperibo seems to heal itself as you attack it.\n",
	  }));
    }
}

void make_items() {
    if(!present("robes")) {
	move_object(clone_object("room/city/obj/grobe"),this_object());
	command("wear robes", this_object());
    }
    set_hp(1+random(9));
    set_ac(9);
    set_wc(2);
    set_strength(9);
    set_wc(5);
    set_ac(5);
}
