//
//  fox.c
//  Second Chance
//


inherit "inherit/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    
    set_name("Fox");
    set_race("fox");
    set_short("a small red fox");
    set_long("A small red fox darts amongst the trees "+
             "and underbrush.\n");
    set_level(random(3)+2);
    set_gender(random(2) + 1);
    set_aggressive(0);
    
    load_chat(10, ({ "Fox roots in the leaves and underbrush.\n",
        "Fox regards you with curiosity.\n",
        "Fox yips at you.\n",
    }));
    
    load_a_chat(13, ({ "Fox yelps in pain!\n",
        "Fox gnaws on you.\n",
        "Fox scratches at you.\n",
        
    }));
    
    set_attack_msg(({
        "bit",         "deep at the throat",
        "bit",         "on the arm",
        "nibbled",     "on the leg",
        "chomped",     "on the ankle",
        "nibbled",     "with it's teeth",
        "scratched",    " with it's claws",
    }));
}