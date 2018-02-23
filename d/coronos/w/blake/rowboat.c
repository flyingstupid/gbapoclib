#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(!present("fisher")) {
    move_object(clone_object("players/blake/fisher"),this_object());
  }
  
  if(!arg) {
    set_short("Rowboat");
    set_long(
    "You are surprised that your foot don't goes through the bottom of the \n"+
    "the boat as you steps into it. A pair of well used oares layes on the \n"+
    "floor together with an old rusty bucket. In the bow an anchor is tied \n"+
    "to a long rope. \n");
   set_exits(({
        "players/blake/",  "out",
    }));
    set_items(({
        "oares",   "They are very old and decayed.",
        "bucket",  "A rusty bucket wich the fisher use to have fish in.",
        "anchor",  "You can't really see the anchor because it's under the water.",
    }));
    set_weather(1,4,6);
 }
}
void init() {
  call_out("chat", 1);
  ::init();
}
void chat() {
  if(!this_player()->query_stealth_on()) {
    tell_object(this_player(), "The boat rocks as you step down in it.\n");
    say("The boat rocks as "+ this_player()->query_name() +"steps down in it.\n", this_player())
  
