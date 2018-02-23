#include <mudlib.h>
inherit MONSTER;
 
#define NAME            capitalize((string)this_player()->query_name(1))
#define KNIFE           "d/coronos/w/angel/city/obj/knife"
#define NEWBIE_SCROLL   "/objects/n_scroll"
mapping newbies;
string *knife_given;
object scroll;
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("bastian");
  set_short("Bastian, the guide");
  set_alias("guide");
  set_level(7);
  set_long(
        "Bastian is an old scholar who has lived his life \n"+
        "adventuring to lands both near and far. He looks \n"+
        "as though he may be able to assist you.\n");
 
  set_race("human");
  set_gender(1);
 
  load_chat(5, ({
"Bastian says: Greetings there, fair traveller.\n",
"Bastian says: I have scrolls here of many places.\n",
"Bastian says: Well now, if you were a bit younger I could help more.\n",
"Bastian says: I'm here for the newer ones.\n",
"Bastian asks: Are you new to the city?\n",
"Bastian reads his scroll on Ille Coronos.\n",
"Bastian says: The gardens are to the north, in the centre of the city.\n",
"Bastian asks: What is you business in Ille Coronos.\n",
"Bastian says: This is a fine city, isn't it.\n",
"Bastian asks: What do you think of our fair city?\n",
"Bastian says: I like what you're wearing today.\n",
"Bastian asks: Are you heading somewhere?\n",
"Bastian exclaims: Ask me anything!\n",
"Bastian says: The gardens are a nice place to visit.\n",
"Bastian says: I think if I were new to Ille Coronos, I would like \n"+
"                 to visit the gardens at the centre of the city.\n",
  }));
 
  newbies = ([
	"Alena" : 10,		
  ]);
 
  is_npc = 0; /* that'll stop a few attacks */
  knife_given = ({ });
}
 
void init() {
  ::init();
  if(this_player() != this_object()) call_out("newbie1", 1);
}
 
void newbie1() {
  object obj;
  string name;
  int level;
 
 
  /* a few precautionary checks */
  if(!environment()) return;
  obj = this_player();
 
  if(!obj) return;
  if(!present(obj, environment())) return;
  if(!obj->id("PLAYER")) return;
  if(obj->query_invis() || obj->query_hide_in_shadows()) return;
 
  name = capitalize((string)obj->query_name(1));
  level = (int)obj->query_level();

  /* if i have seen them before */
  if(newbies[name]) {
    if(level > newbies[name]) {
      tell_room(environment(),
        "Bastian exclaims: Hello there "+NAME+"!\n"+
        "       You seem to be a little more experienced since\n"+
        "       I last saw you come by these parts of the city!\n");
      newbies[name] =level;
    }
    else {
      tell_room(environment(),
        "Bastian asks: Why haven't you been out adventuring "+NAME+"?\n");
    }
  }

  if(!present("newbie scroll", obj) && (int)obj->query_level() < 5) { 
    if(!newbies[NAME]) {
      tell_room(environment(),
                "Bastian says: You seem to be new in the city.\n"+
                "       I think you will need one of these.\n");
    }
    else {
      tell_room(environment(),
              "Bastian asks: Lost you way again "+NAME+"?\n"+
              "       I think you could do with one of these.\n");
    }

    newbies += ([ name : level ]);
    scroll = clone_object(NEWBIE_SCROLL);
    move_object(scroll, obj);
    obj -> recalc_carry(); /* just in case */

    say("Bastian gives "+NAME+" a scroll with a map.\n", obj);
    tell_object(obj, "Bastian gives you a scroll with a map drawn on it.\n");
    return;
  }

  tell_room(environment(),
	"Bastian says: Hello there "+NAME+". It's nice to see you.\n");
  return;
}

 
 
void catch_tell(string str) {
  string tmp1, tmp2, tmp3;
  string *responses1;
  object knife;
 
 
  responses1 = ({
        "Bastian says: That's a tough one indeed.\n",
        "Bastian says: That's a tough one indeed.\n",
        "Bastian says: I haven't studied on that one.\n",
        "Bastian says: I have no idea.\n",
        "Bastian asks: Why do you ask me that?\n",
        "Bastian says: Perhaps the Black Guard have the answer.\n",
        "Bastian says: Perhaps Lord Alastaire knows.\n",
        "Bastian says: I think I've read something about that once.\n",
        "Bastian says: An interesting question . . .\n",
        "Bastian looks puzzled.\n",
        "Bastian asks: I'm not sure I understand the question?\n",
        "Bastian asks: Perhaps you could put it simpler?\n",
        "Bastian says: Perhaps the Circle has the answers.\n",
        "Bastian says: I am a learned traveller, but I don't have a \n"+
        "              clue about that one.\n",
  });
 
  if(sscanf(str, "%s asks:%swhat%s\n", tmp1, tmp2, tmp3)) {
    if(sscanf(tmp1, "%sBastian%s", tmp1, tmp2)) return;
    tell_room(environment(),
                responses1[random(sizeof(responses1)-1)]);
  }
 
  if(sscanf(str, "%s says: %shelp%s\n", tmp1, tmp2, tmp3)) {
    if(sscanf(tmp1, "%sBastian%s", tmp1, tmp2)) return;
    call_out("newbie1", 1);
    return;
  }
   ::catch_tell(str);
}

 


mapping query_newbies() { return newbies; }

