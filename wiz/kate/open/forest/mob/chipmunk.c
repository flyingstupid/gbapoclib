//
//  wiz/kate/open/forest/mob/chipmunk.c
//  Second Chance
//


#include <mudlib.h>
inherit MONSTER;


void reset(status arg)

{
    ::reset(arg);
    
 /*
    if(!present("skin")) {
        object ob = clone_object("skin.c");
        move_object(ob, this_object());
    }
   */ 
    if (arg) return;
    
    set_name("Chipmunk");
    set_race("chipmunk");
    set_short("a tiny red chipmunk");
    set_long("A tiny little red chipmunk scuttles amongst the  "+
             "trees and bushes.\n");
    set_level(random(2)+2);
    set_gender(random(2) + 1);
    set_aggressive(0);
    
    load_chat(10, ({ "Chipmunk scurries around a tree.\n",
        "Chipmunk nibbles on an acorn.\n",
        "Chipmunk stuffs a nut into it's cheeks.\n",
    }));
    
    load_a_chat(13, ({ "Chipmunk squeals in pain!\n",
        "Chipmunk spits nuts at you.\n",
        "Chipmunk nibbles at you.\n",
        
    }));
    
    set_attack_msg(({
        "nibbled",     "on the leg",
        "gnawed",     "on the ankle",
        "nibbled",     "with it's teeth",
        "spits nuts",   "in your face",
    }));
    
}