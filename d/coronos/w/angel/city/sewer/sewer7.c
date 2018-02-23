#include <mudlib.h>

#define CLIMB                   (int)this_player()->query_climb()
#define DIFFICULTY              10
#define SWIM                    (int)this_player()->query_swim()
#define NAME                    (string)this_player()->query_name()
#define DMG                     10
#define PATH                    "d/coronos/w/angel/city/sewer/"

inherit ROOM;

void reset(status arg) {
  string *LONG;

  if(arg) return;
  set_short("the sewers");
  set_weather(0, 1, 0);
  set_long(
"The cold water runs east from here, winding around in the \n"+
"slippery troughs covered with dung and mold. A large crack \n"+
"in the wall collects debris on its way down the tunnels.\n");

  set_smell("The air is full of the cold stench of methane\n");
  set_listen("You can hear the such of water going south\n");

  set_items(({
"debris",
"Debris from fallen rocks, damaged walls, sewage, and other parts of the \n"+
"under ground of the city above funnel into a crack in the wall.\n",

"crack#wall",
"Perhaps you could enter it?",
"ledge",
"It looks very slippery. You had better watch out or you might fall in.",

"trough",
"The trough contains very cold water. You had better not fall in!",

"water",
"It looks very cold, and quite deep. You had better not fall in",
  }));

  set_fall_dam(10);

  set_exits(({
       PATH+"sewer6",  "north",
       PATH+"sewer15", "east",
  }));
}

void init() {
  ::init();
  add_action("enter_it", "enter");
  if(random(DIFFICULTY) > random(CLIMB)) {
    write("\n\nYou slip and fall into the water\n\n"+
           "SPLASH..!!\n\nThe water is freezing cold!\n");
    say(NAME+" falls and slips into the cold water!\n", this_player());
    this_player()->hit_player(random(DMG));
    if(random(DIFFICULTY) > random(SWIM)) {
      this_player()->hit_player(random(DMG));
      write("\nYou cant swim well enough.!\n\n"+
        "The current sweeps you down the sewers!\n");
      this_player()->move_player("south, as the current sweeps "+
        this_player()->query_pronoun()+" away#"+PATH+"pool1");
    }
    else {
      write("Your swimming skill is strong enough for you to pull "+
"yourself out.\n");
    }
  }
  else {
    write("Your knowledge of climbing and dexterity helps "+
"you stay on the ledge.\n");
  }
}

status enter_it() {
  write("You enter the crack in the wall.\n\n");
  this_player()->move_player("into the hole in the wall#"+PATH+"pool1");
  return 1;
}

