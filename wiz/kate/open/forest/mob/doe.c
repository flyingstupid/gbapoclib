//
//  doe.c
//  Second Chance
//


inherit "inherit/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    
    set_name("Doe");
    set_race("deer");
    set_short("a young doe");
    set_long("A mediums sized doe with silken born fur "+
             "bit brown eyes.\n");
    set_level(1);
    set_gender(2);
    set_aggressive(0);
    
    load_chat(10, ({ "Doe looks up at you with big brown eyes.\n",
        "Doe grazes at the grass.\n",
        "Doe nibbles at the forest floor.\n",
    }));
    
    load_a_chat(13, ({ "Doe cries out in pain!\n",
        "Doe bites at you.\n",
        "Doe nudges you with her head.\n",
        
    }));
    
    set_attack_msg(({
        "bit",         "deep at the throat",
        "bit",         "on the arm",
        "nibbled",     "on the leg",
        "chomped",     "on the ankle",
        "nibbled",     "with it's teeth",
    }));
}