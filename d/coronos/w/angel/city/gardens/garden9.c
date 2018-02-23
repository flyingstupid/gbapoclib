#include <mudlib.h>
#define PATH    "d/coronos/w/angel/city/gardens/"
 
inherit ROOM;
  
void reset(status arg) {
  object obj;
 
  if(!present("tree")) {
    obj = clone_object("obj/skills/tree");
    move_object(obj, this_object());
    obj -> grow();
  }
 
  if(arg) return;
 
  set_short("the city garden");
  set_long(
     "A tall white rotunda stands amid a blossoming bushes of waratah, \n"+
     "its new white paint contrasting the brilliant reds of the native \n"+
     "australian flowers.  To the east is the main square of Ille\n"+
     "Coronos. ");
 
  set_day_desc(
     "The sunlight beams down on you from on high,\npeeking through the "+
     "white fluffy clouds.\n");
  set_night_desc(
     "The moon stares down at you as dark sinister \nclouds pass by.\n");
 
  set_listen("You think you hear the chattering of possums.\n");
  set_smell("The fragrance of the waratah is beautiful.\n");
 
  set_items(({
     "rotunda",
          "A tall white wooden building, mainly used for resting, \n"+
          "or for Sunday picnics. It is a quiet place to sit.     \n"+
          "Perhaps you care to enter the rotunda and rest for a while",
     "waratah#flower#flowers",
          "The brilliant red waratah is in full bloom here, its large \n"+
          "flowers several inches in diameter. it is certainly beautiful",
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
        PATH+"garden4", "northwest",
        PATH+"garden12", "southwest",
        PATH+"garden8", "west",
        "d/coronos/w/darkness/dpath2", "east",
  }));
  set_weather(1,4,0);
}
 
void init() {
  ::init();
  add_action("enter", "enter");
}
 
status enter(string str) {
  if(str == "rotunda") {
    write("You enter the rotunda.\n\n");
    this_player()->move_player(
      "into the rotunda#d/coronos/w/angel/city/gardens/rotunda");
    return 1;
  }
  else {
    notify_fail("Enter what?\n");
    return 0;
  }
}
