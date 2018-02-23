#include <mudlib.h>

inherit MONSTER;
void reset(status arg) {
    ::reset(arg);

    set_name("lunatic");
    set_short("A crazed lunatic");
    set_wander(50,10);
    set_long(
      "\tAs you approach this man and study him carefully, you\n"+
      "notice that he looks to be in extreme fear of something. He is always\n"+
      "looking fearfully around him. He looks at you in fear often and seeing\n"+
      "your inaction seems to relax and looks to something else. His paranoia\n"+
      "immediately sets back in and he begins to scream gibberish again.\n"
    );
    set_alias("crazed lunatic");
    set_level(1);
    set_race("human");
    set_al(-50);
    set_gender(1);
    load_chat(7,({
	"Lunatic whimpers: Don't let them take me again... Please, don't let them.\n",
	"Lunatic curls up into a ball as if trying to get away from some unseen\n"+
	"person that's trying to do him harm.\n",
	"Lunatic grabs you roughly by the front of your clothes and whispers harshly\n"+
	"into your ear: It bleeds! It bleeds all the time! All over everything! Dark,\n"+
	"               evil blood. It'll bleed all over you too.\n",
	"Lunatic screams: I DON'T WANT TO DIE!\n",
      }));

    load_a_chat(50,({
	"The lunatic whimpers as you pound on him viciously.\n",
	"Your pity for this person almost makes you want to stop this violence.\n",
	"Lunatic begs of you: Please stop hurting me! I am faithful!\n",
	"Lunatic shouts: PLEASE, SOMEONE HELP ME!!\n",
      }));
    set_heart_ob(this_object());

} /* End of reset */

void init() {
    ::init();
} /* end of init */

