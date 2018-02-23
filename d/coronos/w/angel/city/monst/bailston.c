#include <mudlib.h>
 
#define NEWBIE_ARMOUR     "/d/coronos/w/angel/city/obj/n_armour"
#define KNIFE             "/d/coronos/w/angel/city/obj/knife"
#define CLUB              "/obj/skills/branch"
#define NEWBIE_WEAPON     "/d/coronos/w/angel/city/obj/n_weapon"
#define NEWBIE_CLOTHING   "/d/coronos/w/angel/city/obj/n_clothing"

#define NAME		  (string)this_player()->query_name()


inherit MONSTER;
 
static string *players;
 
 
void newbie1();
void newbie2(string name);
void newbie3(string name);
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
 
 
  set_name("bailston");
  set_short("Major Bailston");
 
  set_long(
"Bailston is the Man-at-Arms of Lord Shadowbane. A tall man,      \n"+
"whose eyes are a strange grey-blue, and who appears well muscled,\n"+
"and battle hardened. He must have been in many battles with his  \n"+
"lord as he has the look about him of a skilled warrior. \n");
 
  set_gender(1);
  set_level(22);
  set_race("human");
  set_alias("doppleganger");
  add_class("fighter");
  add_class("thief");
 
  players = ({ });
 
  load_chat(10, ({
"Bailston says: Lord Shadowbane fought hard for this land.\n",
"Bailston says: Ille Coronos would not be here today, if it were \n"+
"               not for Lord Shadowbane and Sir WhiteStarr.\n",
"Bailston asks: Are you here to join Shadowbane's infantry.\n",
"Bailston says: Shadowbane is a fair and good lord.\n",
"Bailston asks: Are you new here in our fair city.\n",
"Bailston says: I am glad the IronHand wars are over.\n",
  }));
 
 
 
}
 
 
void init() {
  ::init();
  call_out("newbie1", 1);
}
 
void newbie1() {
  string name;
  name = (string)this_player()->query_name(1);
 
  if(!present(this_player(), environment())) return;
  if(member_array(name, players) != -1) {
    if(!present("surcoat", this_player())) {
      tell_room(environment(), "Bailston exclaims: Where are the items I gave you!\n"+
	"Bailston exclaims: You've deserted the infantry!\n"+
	"\tI'll have to get the black guard onto you, soldier!\n");
      return;
    }
    tell_room(environment(),
	"Bailston says: It's good to see you again, Soldier "+ NAME +".\n");
    return;
  }

  if(this_player()->query_level() > 5)       return;
 
/* leave out for a while
  if(present("fromshadowbane", this_player())) {
    tell_room(environment(),
        "Bailston says: Greetings there "+capitalize(name)+". I see you have \n"+
        "a message from Lord Shadowbane\n");
    destruct(present("fromshadowbane", this_player()));
*/
    call_out("newbie2", 1, name);
    return;
  }
/*
 
  tell_room(environment(),
        "Bailston says: Greetings friend. I am the Man-at-Arms for Lord Shadowbane.\n"+
        "\tI am in charge of his armies. If you wish to join his forces\n"+
        "\tyou will need a letter from him. \n\n"+
        "Bailston says: All of Shadowbane's men are outfitted with suitable armour\n"+
        "\tand weaponry to assist them in their duties.\n");
  return;
}
 
*/


void newbie2(string name) {
  if(!present(this_player(), environment())) return;
  tell_room(environment(),
        "Bailston says: I think you'll be a suitable infantryman. Here is your equipment.\n");
  newbie3(name);
  return;
}
 
void newbie3(string name) {
  object ob;
 
  if(!present(this_player(), environment())) return;
  players += ({ name, });
 
  if(this_player()->query_class("mage")) {
    tell_room(environment(),
      "Bailston exclaims: A mage hmm? ..you won't be needing this armour then!\n");
  }
  else if(present("armour", this_player())) {
    tell_room(environment(),
	"Bailston says: You already seem well equipped for your enlistment.\n");
  }
  else {
    ob  = clone_object(NEWBIE_ARMOUR);
    move_object(ob, this_player());
    write("Bailston gives you "+ob->short()+"\n");
    say("Bailston gives "+NAME+" "+ob->short()+".\n", this_player());
  }
 
  if(this_player()->query_class("mage")) {
    tell_room(environment(), "Bailston says: Hmmm. A wizard.\n");
    ob = clone_object(KNIFE);
  }
  else if(present("weapon", this_player())) {
    tell_room(environment(), "Bailston says: You seem to have a weapon already, good.\n");
  }
  else if(this_player()->query_class("cleric")) {
    tell_room(environment(), 
	"Bailston says: A priest hey? Prays are best left for churches.\n");
    ob = clone_object(CLUB);
  }
  else {
    ob = clone_object(KNIFE);
  }

  move_object(ob, this_player());
  write("Bailston gives you "+ob->short()+"\n");
  say("Bailston gives "+NAME+" "+ob->short()+".\n", this_player());

 
  ob = clone_object(NEWBIE_CLOTHING);
  move_object(ob, this_player());
  write("Bailston gives you "+ob->short()+"\n");
  say("Bailston gives "+NAME+" "+ob->short()+".\n", this_player());
  this_player()->recalc_carry();
  this_player()->save_me(1);

  tell_room(environment(),
	"Bailston says: Now, don't let me see you here wanting equipment again.\n"+
	"Bailston says: Dismissed soldier!\n");
  return;
}
 
 

