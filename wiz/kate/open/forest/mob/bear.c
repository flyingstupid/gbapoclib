//
//  bear.c
//  Second Chance
//


inherit "inherit/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    
    set_name("Bear");
    set_race("bear");
    set_short("a large black bear");
    set_long("An enormous black bear towers above you, it's maw is splattered "+
             "with blood and it's sharp teeth and claws are exposed.\n");
    set_level(random(4)+7);
    set_gender(random(2) + 1);
    set_aggressive(1);
    
    load_chat(10, ({ "Bear growls at you menacingly.\n",
        "Bear lumbers through the forest.\n",
        "Bear snorts and snuffs.\n",
    }));
    
    load_a_chat(13, ({ "Bear growls in pain.\n",
        "Bear swipes at you with his paw.\n",
        "Bear mauls you with his sharp teeth.\n",
        
    }));
    
    set_attack_msg(({
        "bit",         "deep at the throat",
        "bit",         "on the arm",
        "gnawed",     "on the leg",
        "chomped",     "on the ankle",
        "mauled",     "with it's teeth",
        "grazed",      "with its claws",
    }));
}