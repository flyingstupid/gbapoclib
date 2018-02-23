#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
    ::reset(arg);
    if(arg)return;
    set_name("mother dingo");
    set_alias("dingo");
    set_short("The mother dingo");
    set_long(
      "A large doglike creature with a light brown coat. Her ears \n"+
      "are perked up as she listens to everything around her. She \n"+
      "looks as if she has just had her pups.\n");
    set_gender(2);
    set_level(24);
    set_race("dog");
    load_chat(5,({"Dingo looks at you with curious eyes.\n",
	"Dingo growls at you, warning you that she is no easy pup.\n", 
	"Dingo yips at you, as if warning you against attacking her.\n",
	"Bearing her teeth, the mother dingo warns you that it \n"+
	"would be dangerous to attack her.\n",
      }));
    set_domain("den");
    load_a_chat(20,({"Dingo bites you HARD with very sharp teeth!\n",
	"Dingo growls at you and snaps her powerful jaws at you.\n",
	"Dingo pounces, slamming you to the ground hard!\n",
      }));
}
