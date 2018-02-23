#include <mudlib.h>

#define NAME	(string)this_player()->query_name()

inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cat");
  set_short("A small cat");
  set_long(
	"A small black cat. Perhaps it belong to a wizard who \n"+
	"lives near by, or maybe it is just a stray.\n");
  set_level(1);
  set_dead_ob(this_object());
  set_alignment(-100);
  set_attack_msg(({
	"missed", 	"",
	"pawed", 	"lightly",
	"grazed", 	"with her claws",
	"brushed",	"with her claws",
	"bites",	"with her fangs",
	"slashes",	"with her claws",
	"bites", 	"hard with her fangs!",
  }));
  set_gender(2);

  load_chat(5, ({
	"Cat purrs contentedly.\n", 
	"Cat eye you warily.\n", 
	"Cat watches your every move.\n",
	"Cat stares at you.\n",
	"Cat hisses at you.\n",
  }));

  load_a_chat(5, ({
	"Cat hisses at you.\n",
  }));
  set_race("cat");
}

  
void catch_tell(string str) {
  string verb;
  string tmp1, tmp2;

  ::catch_tell(str);

  if(this_player() == this_object()) return;

  if(sscanf(str, "%syou%s", tmp1, tmp2)) {
    if(this_player()->query_alignment() < 0) {
      write("Cat snuggles up to you.\n");
      say("Cat snuggles up to "+NAME+"\n", this_player());
      return;
    }
    else {
      write("Cat hisses at you!\n");
      add_secondary_attacker(this_player());
      return;
    }
  }
}
 
void monster_died() {
  object ob;
  if(ob=present("corpse", environment()))
    destruct(ob);
  tell_room(environment(), "Cat vanishes in a puff of smoke!\n");
}

