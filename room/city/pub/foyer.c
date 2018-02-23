#include <mudlib.h>
#include <linewrap.h>
inherit ROOM;

static string *players;
static status pannel;

status query_players(string str);

void reset(status arg) {
  pannel = 0;
  if(!present("samantha")) {
    move_object(clone_object("room/city/pub/sam"),this_object());
  }

  if(arg) return;

  set_short("the inn above skandles downfall");
  set_long(
     "The shadows from the fire in the bar spread their long dark \n"+
     "fingers across the floor and walls here, enveloping everything \n"+
     "in a soft, blanket of grey. A long thin wooden staircase extends \n"+
     "upward to the north, and a small table against the base of the   \n"+
     "staircase bears a small white book with a blue grey cover.       \n");
  
  set_search_array(({
   "pannel", "It looks like you might be able to move it",
    "room", "One of the pannels on the wall looks like it might"
    "be able to be moved"
  }));

  set_items(({
     "book#register",
     "It appears to be the register for the inn and the rooms upstairs.\n"+
     "Perhaps you could read it?",

     "stairs#staircase#stair",
     "A thin wooden staircase of old rotting wood creaks upward "+
     "to the rooms of the inn",

     "shadows#shadow#fingers#finger#darkness#blanket",
     "They eminate from the bar",

     "bar", "It is in the next room",

     "floor",
     "The floor is made of simple wooden boards, once polished to a \n"+
     "high sheen, and now scuffed and dirty with the many travellers \n"+
     "who have passed through here on their journeys",

     "wall#walls",
     "The walls are made of wood pannels",
     "pannel#pannels",
     "As you look closer at one of the pannels it seems to be slightly \n"+
     "adjar from the others. Perhaps you could move it?"
  }));

  set_exits(({
   "room/city/pub/hall1", "up",
   "room/city/pub/pub",   "south"
  }));
  players = ({});
  set_weather(2, 1, 0);
}

void init() {
  add_action("read", "read");
  add_action("move_pannel", "move");
  add_action("enter", "enter");
  add_action("enter", "squeeze");
  add_action("enter", "crawl");
  ::init();
}

status read(string str) {
  string tmp;

  if(str == "book" || str == "register") {
    write("If you want to rent a room, just ask samantha about one.\n"+
     "Commands: say <room> \n"+
     "Items found missing from rooms is not the concern of the management.\n");

    if(!players || !sizeof(players)) {
      write("No one has checked into the inn today.\n");
      return 1;
    }
    else {
      tmp = implode(players, ",");
      write("The following people are staying here in the inn...\n");
      writelw("\t"+tmp+"\n");
      say(this_player()->query_name() +" reads the inn's register.\n");
    }
    return 1;
  }
  return 0;
}

status move_pannel(string str) {
  string tmp1, tmp2;
  if(sscanf(str, "%spannel%s", tmp1, tmp2)) {
    if(pannel) {
      write("The pannel has already been moved to one side.\n");
      write("It reveals a hole in the wall big enough to crawl through.\n");
      return 1;
    }
    write("You move the pannel in the wall to one side.\n");
    write("It reveals a hole in the wall big enough to crawl through.\n");
    pannel = 1;
    say(this_player()->query_name() +" opens a pannel in the wall.\n");
    return 1;
  }
  return 0;
}

status enter( string str) {
  string tmp1, tmp2;
  if(sscanf(str, "%shole%s", tmp1, tmp2) ||
     sscanf(str, "%swall%s", tmp1, tmp2)) {
    if(!pannel) return 0;
    if(!this_player()->add_weight(5)) {
      write("You're carrying too much to be able to squeeze through.\n");
      return 1;
    }
    write("You squeeze through the hole in the wall.\n");
    if(!this_player()->query_stealth_on())
      say(this_player()->query_name() +" crawls through a hole in "+
          "the wall.\n");
    move_object(this_player(), "room/city/pub/saferoom");
    command("look", this_player());
    return 1;
  }
}

void add_players(string str) {
  if(!str || query_players(str)) return;
  players += ({ str, });
}

status query_players(string str) {
  if(!players || !sizeof(players)) return 0;
  if(member_array(str, players) != -1) return 1;
}
