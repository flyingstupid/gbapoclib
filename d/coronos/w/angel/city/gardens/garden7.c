#include <mudlib.h>

#define OBJ	"d/coronos/w/angel/city/obj/"
#define PATH	"d/coronos/w/angel/city/gardens/"
inherit ROOM;

status enter(string str);
void reset(status arg) {
  int i;
  object obj;

  if(!present("tucker bag")) {
    obj = clone_object("objects/bag");
    obj -> set_name("tucker bag");
    obj -> set_alias("bag");
    obj -> set_short("A small bag");
    obj -> set_long("This is a heshian sack called a tucker bag.\n"+
		    "From the fleece stuck to the insides of it \n"+
		    "it probably held a sheep at once stage.\n");
    move_object(obj, this_object());
  }

  if(!present("knife")) {
    move_object(clone_object(OBJ+"knife"), this_object());
  }
  if(!present("lizard")) {
    for(i=0; i<4; i++) {
      obj = clone_object(MONSTER);
      obj -> set_name("lizard");
      obj -> set_short("A frilled neck lizard");
      obj -> set_long(
               "It is a small, but long lizard with a frill of skin     \n"+
               "around its neck. When it gets excited, or tries to      \n"+
               "fend off preditors, its frill makes it look much larger.\n");
      obj -> set_level(1);
      obj -> set_hp(35 + random(10));
      obj -> set_gender(1);
      obj -> set_race("reptile");
      obj -> set_wc(5);
      obj -> set_ac(3);
      obj -> load_chat(5,({ "Lizard hisses at you.\n",
               "Lizard flares up its frills.\n",
               "Lizard scurries around the bank of the billabong.\n",
               "Lizard sniffs at you.\n",
               "Lizard scurries around the campfire.\n",
            }));
      obj -> load_a_chat(5,({ "Lizard growls at you.\n",
               "Lizard hisses meanicingly at you.\n",
               "Lizard flares up its frills.\n",
            }));
      obj -> set_attack_msg(({
               "scrapes",          "lightly with his claws",   
               "scrapes",          "with his claws",        
               "gnaws",            "with his teeth",
               "strikes",          "with his tail",
               "lashes",           "with his claws",
               "bashes",      "hard with its tail",
               "scrapes",     "hard with its claws",
            }));
      move_object(obj, this_object());
    }
  }

  if(arg) return;
  set_short("the city garden");
  set_long(
     "A coolibah tree stands tall, guarding the gentle waters of a   \n"+
     "of a billabong in the centre of this clearing. The cobblestone \n"+
     "path winds around its edges, spreading in all directions. The  \n"+
     "bank of the billabong bears many tracks. There is also the sign\n"+
     "of a fresh campfire. Perhaps someone has been here before you?\n");

  set_day_desc(
     "The sunlight beams down on you from on high, peeking through the \n"+
     "white fluffy clouds.\n");
  set_night_desc(
     "The moon stares down at you as dark sinister clouds pass by.\n");

  set_listen("You think you hear someone singing...\n");
  set_smell("The air is full of eucalyptus\n");

  set_items(({
     "campfire#fire",
          "Someone has been boiling some billy tea here and there \n"+
          "is a sign of a scuffle here; horses and a few soldiers",
     "coolibah tree#tree",
          "The bark is redish in colour, while underneath, as some of the \n"+
          "bark peals off, the wood is a grey white, similar to the ghost \n"+
          "gum near the garden gates. Its wide spreading arms are perfect \n"+
          "for shade",
     "billabong#water",
          "The billabong is a small natural lake. Perhaps you could go \n"+
          "for a quick swim in its quiet waters",
     "bank", 
          "The bank bears some tracks",
     "tracks",
          "They seem to be of a large creature, possisbly a reptile. You \n"+
          "also notice the tracks of several soldiers boots and horses",
  }));
  set_day_items(({
     "sunlight#sun#light",
          "Do you want to go blind?",
     "cloud#clouds",
          "They are white and fluffy. One reminds you of a big kangaroo",
  }));
  set_night_items(({
     "moon",
          "A white barron moon",
     "cloud#clouds",
          "They look dark and sinister...and very spooky",
  }));
  set_exits(({
	PATH+"garden3", "north",
	PATH+"garden11", "south",
	PATH+"garden6", "west",
	PATH+"garden8", "east",
  }));
  set_weather(1,4,0);
}


void init() {
  ::init();
  add_action("enter", "enter");
  add_action("enter", "swim");
}

status enter(string str) {
  write("\nYou'll never catch me alive said he...\n\n");
  /* some words to watzing matilda where he jumps into the 
   * billabong  a lesson in australian culture 
   */
  this_player()->move_player("for a swim in the billabong"+
	"#"+PATH+"bbong");
  return 1;
}

