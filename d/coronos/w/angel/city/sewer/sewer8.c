#include <mudlib.h>

#define CLIMB                   (int)this_player()->query_climb()
#define DIFFICULTY              10
#define SWIM                    (int)this_player()->query_swim()
#define NAME                    (string)this_player()->query_name()
#define DMG                     10
#define PATH                    "d/coronos/w/angel/city/sewer/"

inherit ROOM;

void reset(status arg) {
    load_door(({
        "file", "d/coronos/w/angel/ud/l1/l1r30",
        "direction", "secret door",
        "long", "A small part of the wall seems to move a little, \n"+
                "leading to somewhere else within the sewers.\n",
        "secret door", 17,
        "secret door finders", ({ }),
      }));


  if(arg) return;
  set_short("the sewers");
  set_weather(0, 1, 0);
  set_long(
"There is a portcullis that blocks off the paths to the north\n"+
"where the sewers take on a more cavernous look. The cold water\n"+
"appears to come from that direction, flowing into the troughs \n"+
"either side of this tunnel section.\n");


  set_smell("The air is full of the cold stench of methane\n");
  set_listen(
	"You can hear a delicate voice chanting and praying, but the \n"+
	"sound seems to come out of the very walls itself !\n");


  set_items(({
"portcullis",
"It appears to be held fast, and wont move",

"ledge",
"It looks very slippery. You had better watch out or you might fall in.",

"trough",
"The trough contains very cold water. You had better not fall in!",

"water",
"It looks very cold, and quite deep. You had better not fall in",
  }));

  set_fall_dam(10);

  set_exits(({
	PATH+"sewer9", "south",
       PATH+"sewer15", "east",
  }));
}

void init() {
  ::init();
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
        this_player()->query_pronoun()+" away#"+PATH+"pool2");
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
