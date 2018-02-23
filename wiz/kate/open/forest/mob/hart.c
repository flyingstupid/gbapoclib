//
//  hart.c
//  Second Chance
//


inherit "inherit/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    
    set_name("Hart");
    set_race("deer");
    set_short("a stately hart");
    set_long("A stately red deer stag with a full set of "+
             "pointed and deadly antlers.\n");
    set_level(random(3)+4);  //4-6
    set_gender(1);
    set_aggressive(0);
    
    load_chat(10, ({ "Hart rubs his antlers on a nearby tree.\n",
        "Hart grazes at the grass.\n",
        "Hart snorts in your direction.\n",
    }));
    
    load_a_chat(13, ({ "Hart cries out in pain!\n",
        "Hart gores you with his antlers.\n",
        "Hart charges into you.\n",
        
    }));
    
    set_attack_msg(({
        "bit",         "deep at the throat",
        "bit",         "on the arm",
        "nibbled",     "on the leg",
        "chomped",     "on the ankle",
        "nibbled",     "with it's teeth",
        "gored",       "with his antlers",
    }));
}