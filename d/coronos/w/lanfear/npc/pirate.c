#include <mudlib.h>

inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  
  if(!present("scimitar")) {
    object scimitar;
    scimitar=clone_object("/d/coronos/w/lanfear/weapons/scimitar");
    move_object(scimitar,this_object());
    command("wield scimitar"); 
    }
    
    set_name("pirate");
    set_alt_name("retired pirate");
    set_short("A retired pirate");
set_long("This old salt has given up his pirate life and settled down \n"+ 
         "here in Ille Coronos. He has a wicked smile upon his face and \n"+
         "his dark sinister eyes glares at you. Since his left leg is \n"+
         "cut of below his knee, it is made of wood. With that wooden \n"+
         "leg and the big golden earring, he look like a real pirate.\n");
    set_gender(1);
    set_level(9);
    set_al(-50);
    set_race("human");
    add_class("fighter"); 
    set_wander(50, 500);
    add_money(100 + random(300));   
load_chat(10, ({"The pirate asks: Why can't you leave me alone?\n",
                "The pirate peers at you with his dark, sinister eyes.\n",
                "The pirate sighs: I wish I could get my leg back.\n",
                "The pirate says: I have been a famous pirate.\n", 
                "The pirate scratches his butt.\n",
            "The pirate says: I will hurt you if you don't leave me alone.\n",
 }));

load_a_chat(15, ({ "The pirate screams: You'll pay for your mistake!\n",
         "The pirate says: I'm a veteran fighter. I will hurt you plenty.\n",
                   "The pirate says: Go away you landlubber.\n",
                   "The pirate says: I am calling for the guards!\n",
                   "The pirate shouts: GUARDS HELP ME!!\n",
 }));

}

void init() {
  call_out("chat", 1);
  ::init();
}
void chat() {
  if(!this_player()->query_stealth_on() && !this_player()->query_npc()) {
    tell_object(this_player(), "The old pirate gives you a dark glance.\n");
    say("The pirate says: Scram, you landlubber.\n", this_player());


 }
    set_ac(5);
    set_wc(13);
}


