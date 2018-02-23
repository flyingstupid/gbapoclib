#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  object ob;
 
  if(!present("citizen")) {
    ob = clone_object("d/coronos/w/angel/city/monst/citizen");
    move_object(ob, this_object());
  }
 
  if(arg) return;
 
  set_short("Wall Street\n");
  set_long(
      "This cobblestone road continues from east to west.  A few\n"+
      "bushes line one side of the road, while a brick wall runs\n"+
      "along the opposite side.  The top of a tall oak tree rises\n"+
      "above the top of the wall, as it grows behind it. A\n"+
      "broken lantern hangs from a pole next to the wall\n");
  set_items(({
      "lantern#oil lantern",
      "This broken lantern hangs from a pole.  It's glass panels have been\n"+
      "broken and it's frame is bent and cracked here and there.\n",
      "pole",
      "This is a simple pole that stand next to the wall.  A lantern hangs\n"+
      "from the pole.\n",
      "wall#brick wall",
      "This is a long brick wall that runs along the length of the road.\n"+
      "Vines and moss cover the walls red brick.\n",
      "road#cobblestone road",
      "The road is paved with grey cobblestones.\n",
      "cobblestone#cobblestones",
      "These grey cobblestones have been worn and smoothed over time.\n",
      "bush#bushes",
      "These are bushes of different species, growing along the side of the road.\n",
      "brick#bricks",
      "These bricks are made from red clay.  The seem to be chipped and scuffed\n"+
      "here more than anywhere else along the wall.\n",
      "vine#vines",
      "These vines grow along the wall.  A few branches have been torn and cut here.\n"
,
      "moss",
      "This is a green, patchy moss that grows all along this wall.\n"+
      "You notice that some of the moss has been scraped off the wall.\n",
      "tree",
      "This large oak tree grows on the other side of the wall.  It's long\n"+
      "branches stretch over the wall and shade the road.\n",
      }));
  set_smell(
      "You smell the woody scent of the tree.\n");
  set_listen(
      "You hear the rustling leaves of the tree and the bushes as a breeze\n"+
      "blows by.\n");
  set_weather(2, 4, 0);
  set_climb(12);
  set_fall_dam(10);
  set_exits(({
      "/d/coronos/w/darkness/wallst2", "west",
      "/d/coronos/w/darkness/wallst4", "east",
      }));
}
 
void init() {
  ::init();
  add_action("climber", "climb");
}
 
status climber(string str) {
  string tmp1, tmp2;
  int pmon;
  if(!str) {
    write("What are you trying to climb?\n");
    return 1;
  }
  if(sscanf(str, "%swall%s", tmp1, tmp2)) {
    /*so they can type climb the wall*/
    write("You make your way up the wall\n");
    this_player()->move_player(
        "as "+this_player()->query_pronoun()+" climbs "+
        "up the wall#d/coronos/w/darkness/walltop");
    return 1;
  }
  if(sscanf(str, "%slittle red button%s", tmp1, tmp2)) {
    this_player()->add_exp(50000);
    write("Ok.\n");    
    return 1;
    }
  if(sscanf(str, "%slittle green button%s", tmp1, tmp2)) {
    pmon=this_player()->query_money();
    this_player()->set_money(pmon+50000);
    write("Ok.\n");
    return 1;
    } 
  return 0;
}
 

