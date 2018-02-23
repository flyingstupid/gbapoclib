#include <mudlib.h>

inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  
  if(!present("staff")) {
    object staff;
    staff=clone_object("/d/coronos/w/lanfear/weapons/staff");
    move_object(staff,this_object());
    command("wield staff"); 
    }
    
    set_name("man");
    set_alt_name("old man");
    set_short("An old man");
    set_long("This is the oldest citizen of ille coronos.\n"+ 
             "His long gray beard reaches all the way down\n"+ 
             "to his knees. He uses a long staff to support\n"+ 
             "his old weakened body.\n");
    set_gender(1);
    set_level(9);
    set_al(50);
    set_race("human");
    add_class("fighter"); 
    set_wander(10, 400);
    add_money(100 + random(100));   
    load_chat(10, ({"The old man says: Why are everyone in such a hurry?\n",
                    "The old man peers at you with his calm, blue eyes.\n",
                    "The ancient man sighs: I wish I was young again.\n"+ 
                    " I used to have so much fun back then.\n",
                    "The old man asks: What do you think of my nice staff ?\n"+ 
                    " I have made it my self.\n",
                    "The joints of the old man squeas in protest when he takes\n"+
                    " a few staggering steps.\n",
              
                    "The old man says: I will celebrate my ninetieth birthday\n"+
                    " very soon\n",
                    }));

    load_a_chat(6, ({ "The old man screams: YOU horrible creature!\n",
                      "The old man says: I'm an old warrior. I will hurt you.\h",
                      "The old man crys: Now i whon't survive my ninetieth birthday.\n",
                      "The old man says: I am calling for the guards!\n",
                      "The old man shouts: GUARDS HELP ME!!\n",
                      }));

}
void init() {
  call_out("chat", 1);
  ::init();
}

void chat() {
  if(!this_player()->query_stealth_on() && !this_player()->query_npc()) {
    tell_object(this_player(), " The old man bows stiffly to you. \n");
    say("The old man says: Hello "+ this_player()->query_name() +
    " nice to meet you. \n", this_player());


 }
    set_ac(5);
    set_wc(14);
}


