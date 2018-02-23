#include <mudlib.h>

inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cat");
  set_short("A small cat");

  set_long(
"A small white cat. She looks very content about something.\n");

  set_level(1);
  set_dead_ob(this_object());
  set_alignment(-100);
  set_attack_msg(({
        "missed",       "",
        "pawed",        "lightly",
        "grazed",       "with her claws",
        "brushed",      "with her claws",
        "bites",        "with her fangs",
        "slashes",      "with her claws",
        "bites",        "hard with her fangs!",
  }));
  set_gender(2);

  load_chat(5, ({
        "Cat purrs contentedly.\n",
         "Cat eyes you warily.\n",
        "Cat watches your every move.\n",
        "Cat stares at you.\n",
        "Cat hisses at you.\n",
  }));

  load_a_chat(5, ({
        "Cat hisses at you.\n",
  }));
  set_race("cat");
}
