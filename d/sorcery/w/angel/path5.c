#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(!present("cat")) {
    move_object(clone_object("d/sorcery/w/angel/monst/cat"), this_object());
  }

  if(arg) return;
  set_short("the isle of sorcery");

  set_long(
"A few pine trees stand beside the road that leads up toward a \n"+
"majestic building that supports several towers that spirals   \n"+
"toward the heavens. The road here is a little more dusty,     \n"+
"turning the basalt rock a little grey. There are a few smaller\n"+
"houses to the west, giving the overall view of the mountain top\n"+
"a quaintness you would normally associate with a village.\n");

  set_items(({
"tree#trees#pine trees",
"A few lone pine trees. It is rumoured that magic keeps them growing",
"mountain#mountain top",
"Youre at the top of the mountain on the Isle of Sorcery.\n"+
"The view is very beautiful from up here.\n",

"view",
"You can see the whole south side of the island from up here",

"house#houses",
"It appears that a small village has sprung up in order to support \n"+
"the needs of the wizards who live on the Isle of Sorcery", 

"road", "Its a bit dusty, and has many tracks",
"tracks", "It seems that many people have passed through here",
"basalt", "It seems to have been magically raised from the earth",

"building",
"A long manor style house which is several stories high. It has \n"+
"a very gothic feeling to it, except for the entrance hall which\n"+
"from here appears to be made from glass",

"entrance hall#hall",
"The entrance hall is a little further up the road. It appears to \n"+
"be made from glass. It is then that you notice the amount of stained\n"+
"glassed windows that abound within the grand mansion",

"stain glass#stained glass",
"There are many windows that line the front walls of the Council \n"+
"building. Some depict scenes from the beginning of the Second Age\n"+
"of Magic when the One Whose Name is Spoken in Whispers battled \n"+
"the Three in a titanic war for control of magic across the realms",

  }));

  set_weather(2, 1, 0);
  set_exits(({
	"d/sorcery/w/angel/path4", "north",
	"d/sorcery/w/angel/path6", "south",
	"d/sorcery/w/angel/path7", "west",
  }));

  set_listen("You can hear laughter from the west.\n");
  set_listen("You can smell freshly baked bread from the west.\n");
}
