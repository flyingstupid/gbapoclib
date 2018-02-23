#include <mudlib.h>
#include <linewrap.h>


inherit MONSTER;

void check_newbie();

string *newbies;
object vest, knife;

void reset(status arg) {

  if(!present("vest")) {
    vest = clone_object(CLOTHING);
    vest -> set_name("vest");
    vest -> set_short("a wollen vest");
    vest -> set_long("It's made from wool and looks very warm.\n");
    vest -> set_weight(1);
    vest -> set_value(20);
    move_object(vest, this_object());
  }
  
  if(!present("knife")) {
    knife = clone_object(WEAPON);
    knife -> set_name("knife");
    knife -> set_type("slash");
    knife -> set_short("A hunting knife");
    knife -> set_long(
	"It looks a little too sharp for you to be handling like that.\n");
    knife -> set_weight(2);
    knife -> set_value(140);
    knife -> set_wc(6);
    knife -> set_length(12);
    move_object(knife, this_object());
  }



  newbies = ({ });

  ::reset(arg);

  if(arg) return;

  set_name("gadil");
  add_money(100);
  set_gender(1);
  set_short("Gadil, the woodsman");
  set_long(
	"Gadil is a simple man who finds work by setting  \n"+
	"out for the forest Scianthian and collecting wood\n"+
	"to make find carvings and small niknaks.\n");
  
  load_chat(10, ({
"Gadil asks: Would you like a torch?\n",
"Gadil says: I have a fine torch for sale.\n",
"Gadil smiles happily.\n",
"Gadil carves a miniature elf with some wood.\n",
"Gadil asks: Are you new to this city?\n",
"Gadil says: Visit the forest of Scianthian if you can.\n",
"Gadil says: The forest of Scianthian is such a lovely place.\n",
"Gadil says: The gardens in the middle of the city are nice.\n",
"Gadil looks at you with a happy smile.\n",
  }));

  load_a_chat(10, ({
"Gadil winces in pain.\n",
"Gadil says: Leave me alone.\n",
"Gadil exclaims: Guards! Guards! Guards!\n",
"Gadil exclaims: Curzon will get you for this!\n",
"Gadil says: The Black Guard will have your hide for this.\n",
  }));

}

void init() {
  ::init();
  init_command("wield knife");
  init_command("wear vest");
  
  add_action("buy_me", "buy");

  call_out("check_newbie", 1);
}

void check_newbie() {
  object ob, torch;
  string name;

  ob = this_player();
  if(!present(ob, environment())) return;

  name = (string)this_player()->query_name(1);
  if((int)ob -> query_level() < 4) {
    if(member_array(name, newbies) != -1) {
      tell_room(environment(), "Gadil says: Hello again, "+
	capitalize(name) +". It's good to see you.\n");
      return;
    }

    else if(present("torch", ob)) {
      tell_room(environment(), "Gadil says: Nice torch, "+
      capitalize(name)+". I wonder if "+
	"that's one I made.\n");
      return;
    }

    else {
      tell_room(environment(), "Gadil says: Here. You'll need "+
	"this my newbie-friend.\n");
      say("Gadil gives "+capitalize(name)+" a torch.\n", ob);
      write("Gadil gives you a torch.\n");

      newbies += ({ name, });
      torch = clone_object("objects/torch");
      move_object(torch, ob);
      return;
    }
  }
}

status buy_me() {
  object ob;
  string name;

  ob   = this_player();
  name = (string)ob->query_name(1);

  if(member_array(name, newbies) != -1) {
    if(present("torch", ob)) {
      write("Gadil exclaims: But you already have a torch!\n");
      return 1;
    }
    write("Gadil says: But I gave you a torch before.\n");
    return 1;
  }
  writelw("Gadil says: I don't think I have any left. Try the "+
	"general store in the Commercial District.\n");
  return 1;
}

