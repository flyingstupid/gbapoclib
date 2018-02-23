#include <mudlib.h>

inherit MONSTER;
void reset(status arg) {
    ::reset(arg);

    set_name("priest");
    set_short("An insane, heretic priest");
    set_long(
      "\tThis tall man walks up to you immediately when you walk\n"+
      "into the cathedral. He starts preaching to you about religion and\n"+
      "obviously wants to convert you. He is old and is getting wrinkled\n"+
      "around his insane and wandering eyes. They keep darting around\n"+
      "as if he is very concerned about something.\n"
    );
    set_alias("heretic");
    set_gender(1);
    set_race("human");
    load_chat(7,({
	"Priest says: Come pray with me. You must cast away your sins.\n",
	"Priest gives you a short sermon about religion and your lack thereof.\n",
	"Priest says: You must confess your sins! Repent! Repent!\n",
	"Priest looks over a chapter in his holy book.\n",
      }));

    set_attack_msg(({
	"swings wildly at","",
	"clips","on the shoulder with his left fist",
	"bruises","in the ribs with his holy book",
	"pummels","mercilessly with his fists",
	"slams","in the face with his holy book",
	"smashes","in the nose with his holy book.\n"+
	"You can see stars!",
	"gives","a paper cut with the Holy Book!!!\n"+
	"THAT REALLY HURT!!!",
      }));
    load_a_chat(4,({
	"Priest shouts: You will burn in hell for this heretic!\n"+
	"Priest slams you with his holy book.\n",
	"Your feeble weapon makes no physical marks in the priests robes.\n",
	"Priest slams you with his holy book! THAT REALLY HURT!!\n",
      }));
    set_level(5+(random(2)));
    set_wc(13 + random(4));
    set_ac(8 + random(4));
} /* End of reset */

void init() {
    call_out("chat", 1);
    ::init();
} /* end of init */

void chat() {
    if(!this_player()->query_stealth_on() && !this_player()->query_npc()){
	tell_object(this_player(),"The insane, heretic priest walks up to you.\n");
	say("The insane, heretic priest walks up to "+
	  capitalize(this_player()->query_name())+".\n",this_player()); }
} /* End of Chat */

