#include <mudlib.h>
#include <ansi.h>

inherit PUB;

void reset(status arg) {
reset_doors(arg);
load_door(({
"file","d/coronos/w/mycroft/baker4.c",
"direction", "south door",
"key id","city key",
"long",
"An iron-bound, highly polished wooden door with a sliding\n"+
"grate in the center to allow identification. Above the door\n"+
"hangs a sign which reads:"+
BOLD+BLINK+"YVEGNI's SPEAKEASY"+OFF+"\n",
}));



  set_exits(({
"d/coronos/w/mycroft/baker4.c","south"
  }));

set_short("Yvegni's Speakeasy");
  set_long(
"<<<  Yvegni's Speakeasy  >>>\n"+
"Yvegni's Speakeasy is an very private club owned by a former\n"+
"road commisioner whose only crime wasn't taking bribes, but \n"+
"actually getting caught.  He spends his days here at the bar now,\n"+
"still keeping up on the doings of local politics.\n");

  set_weather(4,1,0);
set_owner("yvegni");

add_drink("port", "a glass of port", "That was refreshing", 3);
add_drink("brandy", "a glass of brandy",
"The world spins around you.", 15);
add_drink("vodka","Elfin Vodka",
"A shock wave travels down your alimentary canal.", 35);
add_food("breadsticks","breadsticks","sticks of bread", 8);
add_food("swordfish","swordfish","over-priced fish", 30);
add_food("caviar","caviar","stinking fish eggs", 20);
  set_items(({
"bar", "a polished brass bar with mirrors in back of it",
  }));

}

void init() {
  ::init();
  add_action("read","read");
}

status read(string str) {
  if(str=="list") {
    write("The fonts on the list are too small to read from here. You should get it\n"+
    "before you can read it.\n");
    return 1;
  }
  return 0;
}
