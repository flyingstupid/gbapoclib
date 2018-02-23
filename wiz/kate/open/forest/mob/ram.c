//
//  ram.c
//  Second Chance
//


inherit "inherit/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    
    set_name("Ram");
    set_race("sheep");
    set_short("a large ram");
    set_long("A large male sheep with an impressive set "+
             "of curved horns.\n");
    set_level(4);
    set_gender(1);
    set_aggressive(0);
    
    load_chat(10, ({ "Ram grazes at the forest floor.\n",
        "Ram regards you with suspicion.\n",
        "Ram snorts in your direction\n",
    }));
    
    load_a_chat(13, ({ "Ram cries out in pain!\n",
        "Ram gores you.\n",
        "Ram charges you with it's head lowered.\n",
        
    }));
    
    set_attack_msg(({
        "bit",         "deep at the throat",
        "bit",         "on the arm",
        "nibbled",     "on the leg",
        "chomped",     "on the ankle",
        "nibbled",     "with it's teeth",
        "gored",       "with strong horns",
    }));
}