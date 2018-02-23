#include <mudlib.h>

inherit MONSTER;

object leather, dagger;
void reset(status arg) {

  ::reset(arg);
  if(arg) return;
  if(!present("dagger")) {
    dagger=clone_object("d/coronos/w/lanfear/weapons/dagger");
    move_object(dagger, this_object());
    init_command("wield dagger");
  }

  if(!present("armour")) {
    leather=clone_object("d/coronos/w/lanfear/armour/leather");
    move_object(leather,this_object());
    init_command("wear armour");
  }

    
    
  set_name("citizen");
  set_short("A Citizen");
  set_long(
       "This is a citizen of ille coronos.\n"+
       "He is looking in to shops searching for some thing.\n"+
       "to buy he seems to be well drest and seems to be a nice guy.\n");
    set_gender(1);
    set_level(8);
  set_al(50);
  set_race("human");
  add_class("fighter");
    
  load_chat(5, ({ "Citizen says Hello there stranger.\n",
       "Citizen says seen any pressent for a child?\n",
       "citizen says i am looking for a pressent for my niece.\n",
  }));

  load_a_chat(6, ({ "Citizen screams YOU horribel creature!\n",
       "Citizen crys now i whont make my niece's birthday.\n",
       "Citizen says i am calling for the guard\n",
       "Citizen shouts GUARDS HELP!!",
  }));
   
  
}

void init() {
  call_out("chat", 1);
  ::init();
}

void chat() {
  if(!this_player()->query_stealth_on() && !this_player()->query_npc()) {
    tell_object(this_player(), "The citizen bows to you.\n");
    say("Citizen says Hello "+ this_player()->query_name() +
    "nice to meet you.\n", this_player());


 }
    set_ac(7);
    set_wc(12);
}

