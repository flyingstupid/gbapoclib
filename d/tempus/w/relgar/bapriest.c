#include "/players/relgar/private/mydefs.h"

inherit MONSTER;
void reset(status arg) {
    ::reset(arg);

    set_name("priest");
    set_short("A priest of the Baatezu");
    set_long(
      "        This short and stocky fellow has a very angry expression on his\n"+
      "face. Almost foaming at the mouth, he makes you wonder if he is actually\n"+
      "sane or if maybe he's gone crazy. His robes are ripped almost into \n"+
      "tatters and he is extremely dirty. You can smell the stench coming off of\n"+
      "him.\n"
    );
    set_alias("priest of the baatezu");
    set_gender(1);
    set_race("human");
    load_chat(7,({
      }));

    set_attack_msg(({
	"swings wildly at","",
	"clips","on the shoulder with his left fist",
	"bruises","in the ribs with an elbow",
	"pummels","mercilessly with his fists",
	"slams","in the chin with an uppercut",
	"smashes","in the face, splattering your nose!\n",
	"circles around behind","and slams both fists into your kidneys.\n",
      }));
    load_a_chat(4,({
      }));
    set_level(15);
    set_wc(15+random(3));
    set_ac(8+random(3));
} /* End of reset */

void init() {
    call_out("chat", 1);
    ::init();
} /* end of init */

void chat() {
    if(!this_player()->query_stealth_on() && !this_player()->query_npc()){
	tell_object(TP,
	  "The priest jumps all over you in a frenzy!\n"
	);
	say(
	  "The priest of the Baatezu jumps all over "+ CNAME +"!\n"
	);
	say("The insane, heretic priest walks up to "+
	  capitalize(this_player()->query_name())+".\n",this_player()); }
} /* End of Chat */

