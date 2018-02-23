//
//  rabbit.c
//  Second Chance
//


inherit "inherit/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    
    set_name("Rabbit");
    set_race("rabbit");
    set_short("a small brown rabbit");
    set_long("A small brown rabbit hops amongst the grass "+
             "and underbrush.\n");
    set_level(random(3)+2);
    set_gender(random(2) + 1);
    set_aggressive(0);
    
    load_chat(10, ({ "Rabbit hops peacefully through the grass.\n",
        "Rabbit wiggles it's nose at you.\n",
        "Rabbit hops around your feet.\n",
    }));
    
    load_a_chat(13, ({ "Rabbit squeals in pain!\n",
        "Rabbit gnaws on you.\n",
        "Rabbit nibbles at you.\n",
        
    }));
    
    set_attack_msg(({
        "nibbled",     "on the leg",
        "gnawed",     "on the ankle",
        "nibbled",     "with it's teeth",
    }));
}