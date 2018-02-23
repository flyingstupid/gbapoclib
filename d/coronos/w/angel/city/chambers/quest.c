#include <mudlib.h>
#include <linewrap.h>

#define NAME	(string)this_player()->query_name()
#define OWNER	"Julie"
#define TELL(X)	tell_room(this_object(), X)

inherit ROOM;

string *quests;

static status busy;
static int i;
void reset(status arg) {
  if(!present("julie")) {
    move_object(clone_object("d/coronos/w/angel/city/monst/quest"),this_object());
  }

  reset_doors(arg);

  busy = 0;
  if(arg) return;

  load_door(({
	"direction", "south door",
	"long", "A large door made from red timber.\n",
	"file", "d/coronos/w/darkness/b/hall/hall3",
  }));

  set_short("the chamber offices");


  set_long(
"A grand circle of gold with the symbol of the All-God stands on the \n"+
"back wall of this spartain office. With only a desk and a few chairs\n"+
"it is certainly devoid of any regality.\n");

  set_items(({
"symbol#circle",
"The circle of gold with the holy symbol of the All-God in it's centre \n"+
"is the image of Ille Coronos city itself\n",

"chairs", "They seem to be comfortable enough",
"desk", "The desk is carved from a dark wood, and has many papers on its surface",

"paper#papers", "They seem to be city ordinances, and signed by the regent",
  }));


  set_weather(2, 1, 0);
}

void init() {
  ::init();
  call_out("quest1", 2);
}

void quest_explain() {
  string *messages;

  messages = ({
	OWNER +" says: Ille Coronos is a free city on the Northern Continent of Magia",

	"It was formed by a circle of a few good and noble men, in order to restore "+
	"peace and law to this region, torn appart by the IronHand War.",

	"Today, Ille Coronos, which means 'The Circle', is still dedicated to serving "+
	"it's people and keeping the peace.",

	"To this end, "+NAME+", we offer all manner of services of trainning, and in "+
	"return, we hope that our citizens will offer their help when we require it",
  });

  if(i == sizeof(messages)) {
    call_out("quest3", 2);
    i = 0;
    return;
  }

  writelw(messages[i] +"\n\n");
  i++;
  call_out("quest_explain", 2);
  return;
}


status quest1() {
  if(!present(lower_case(OWNER))) return 1;
  if(busy) {
    writelw(OWNER+" says: I'm sorry, but I'm busy right now. "+
    ", I'll attend to you when I have the time.\n");
    return 1;
  }

  if(this_player()->query_current_quest()) {
    writelw(OWNER +" says: Hello "+NAME+". You still have not completed your "+
    "quest as yet. I'll read it to you again . . . \n\n");

    this_player()->quest_hint();

    busy = 0;
    return 1;
  }

  quests = (string *)this_player()->query_done_quests();
  write(OWNER+" says: Hello there. I am the city clerk. Have you come about \n"+
  "\tour city ordinances and quests? (y/n) > ");
  input_to("quest2");
  return 1;
}

status quest2(string arg) {
  if(arg != "y") {
    write(OWNER+" says: Very well then. Feel free to look around.\n");
    busy = 0;
    return 1;
  }

  busy = 1;

  if(!quests || !sizeof(quests)) {
    write(OWNER+" exclaims: I thought you looked like the type to want to adventure! "+
	"Before we begin, let me explain a few things about our city, Ille Coronos.\n");
    call_out("quest_explain", 2);
    return 1;
  }
  else
    writelw(OWNER +" says: I remember you now, "+NAME+". I see the "+
	quests[sizeof(quests)-1] +" adventure went well.\n\n");

  call_out("quest3", 2);
  return 1;
}

status quest3() {
  string tmp;
  write(OWNER +" sifts through a few papers.\n"+
  OWNER +" says: I'll see if I can find a new assignment for you, "+NAME+"\n\n");

  if(!this_player()->assign_quest()) {
    write(OWNER +" says: We don't have anything for you at this time "+NAME+".\n"+
          "\tPerhaps you can come back later?\n");
    busy = 0;
    return 1;
  }
  write(OWNER +" says: I think this one is suitable for you.\n\n"+
  OWNER+" reads the Circle's ordinance...\n\n");

  this_player()->quest_hint();

  write(OWNER +" says: Happy questing, "+NAME+"\n");
  busy = 0;
  return 1;
}



    

