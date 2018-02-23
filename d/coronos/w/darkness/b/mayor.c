/* Mayor Handlefoot   mayor.c  */
/* Darkness and Blake*/

#include <mudlib.h>
inherit MONSTER;
int count; 

void reset(status arg) {
    ::reset(arg);
    if(!present("ring")) {
        move_object(clone_object("d/coronos/w/blake/ring"),this_object());
        command("wear ring");
    }
    if(!present("dagger")) {
        move_object(clone_object("d/coronos/w/blake/dagger"),this_object());
        command("wield dagger");
    }

    if(!present("mayor's key")) {
        move_object(clone_object("d/coronos/w/darkness/b/mayorkey.c"),this_object());
    }

    if(arg) return;
    set_name("Mayor Handlefoot");
    set_alias("mayor");
    set_alt_name("Handlefoot");
    set_level(14);
    set_gender(1);
    set_short("Mayor Handlefoot");
    set_long(
      "Mayor Handlefoot is a short and tubby man. Several rings and armbands\n"+
      "embellish his fat fingers and hands. He has a purse in his belt full of\n"+
      "many coins that jingle as he walks around the Bureaucracy.\n");
    set_alignment(100);
    add_money(random(450)+400);
    set_race("human");
    set_magic_resist(10);
    set_domain("hall");
    set_heart_ob(this_object());

    load_chat(5, ({
        "Mayor Handlefoot says: Hello fair traveller.\n",
        "Mayor Handdlefoot looks at you and says: I think you should buy some\n"+
        "new clothes.\n",
        "Mayor Handlefoot polishes some of his rings on his jacket. \n",
        "Mayor Handlefoot scratches his nose.\n",
      }));
    load_a_chat(6, ({ "The Mayor screams: I have a bad heart, leave me alone!\n",
        "Mayor Handlefoot bursts into tears.\n",
        "Mayor Handlefoof pants completely exhausted.\n",
      }));
}


void monster_heart_beat() {
  object mon;
 
  if(this_object()->query_attack()) {
    if(count!=1) {
      mon = clone_object("d/coronos/w/angel/city/monst/guard1");
      move_object(mon, environment());
      mon -> add_secondary_attacker(this_object()->query_attack());
      mon = clone_object("d/coronos/w/angel/city/monst/guard1");
      move_object(mon, environment());
      mon -> add_secondary_attacker(this_object()->query_attack());

      tell_room(environment(),
        "\nHandelfoot shouts: Guards! Help me!\n"+
        "A couple City Guards come running to the Mayor's aid.\n");
      count = 1;
    }
  }
}
