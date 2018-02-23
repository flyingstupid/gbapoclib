/* barn2.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  if(!present("rooster")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/npc/rooster"),this_object());
  }
 
  if(!present("pigeon")) {
    int i;
    for(i=0; i<3; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/pigeon"),this_object());}
  }
 

  if(arg) return;
 
  set_short("inside a barn");
  set_long(
    "This is the loft of the barn.  Up here, there is a good second story\n"+
    "view of the large room.  The loft is about a third the size of the\n"+
    "ground floor, and has a railing going across one side.  There is a\n"+
    "ladder leading back down to ground level. Bushels of hay are stacked\n"+
    "neatly up here.  The window, used to bring up the hay, is wide open\n");
  set_day_desc("to air out the humid and stuffy barn.\n");
  set_night_desc("to let in the cool, night air.\n");
  set_items(({
    "barn",
      "The barn is large but simple.  It is well kept and in good\n"+
      "condition.  The ground floor of the barn is far below.\n",
    "down#floor#ground floor#ground",
      "The ground floor of the barn is far below.  Don't even think\n"+
      "about jumping.  You're much to high to safely jump down.\n",
    "up",
      "The ceiling is far above you.",
    "loft#room",
      "The loft is well kept.  Bushels of hay are neatly stacked here.\n",
    "view",
      "The ground floor is far below.  The ceiling of the barn is about\n"+
      "another storie up.\n",
    "side#railing",
      "The wooden railing is like a small fence meant to keep the hay\n"+
      "from falling off the loft onto the ground floor.  It is also a\n"+
      "prevents people from jumping off the loft.\n",
    "animals#animal",
      "Many different animals can be kept in this barn.\n",
    "hay#bushels",
      "The hay is fresh and clean for the animals to eat.\n",
    "chicken feed#feed",
      "The chicken feed is kept on the ground floor.\n",
    "ladder",
      "The ladder is sturdy, but its rungs look well worn from much\n"+
      "use. Don't fall if you try and climb it.  You might hurt yourself.\n",
    "window",
      "This is more of a set of double doors set high into the wall of the\n"+
      "barn.  It is mainly used to haul bushels of hay into barn, directly\n"+
      "to the loft.  It is wide open to let in fresh air.  Outside you can \n"+
      "see a vast and beautiful landscape of forests and fields.\n",
    "doors#door",
      "These barn doors are about ten feet high, and look very heavy.\n"+
      "The sway slightly back and forth in the wind.\n",
    "wind",
      "You can't see the wind, but it does kick up dust and debris off\n"+
      "the floor.  It also howls through the large, open barn.\n",
    "dust#debris",
      "It's just your everyday dust, dirt, loose hay, etc.\n",
    "walls#cracks#wall#crack#board#boards",
      "The old barn walls are made of long wooden boards nailed together.\n"+
      "Over the years, the boards have warped and bent, creating small\n"+
      "cracks where the boards used to meet.\n",
    }));
 
  set_extra_objects(({
    "hay#some hay", "d/coronos/w/newstar/newbie/items/hay", }));
 
  set_smell(
    "You sniff the air.\n"
    "Many different smells fill the air in the barn. The most prominent\n"+
    "is the smell of animals and their feed.  It is also quite musty in \n"+
    "the humid barn.\n");
  set_listen(
    "You hear the wind beating against the outter walls of the barn.\n"+
    "The howling of the wind whistles as it enters through cracks in\n"+
    "the walls.\n");
  set_weather(1, 2, 0);
  set_climb(2);
  set_fall_dam(4);
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/barn1", "down",
      }));
}
 


void init() {
  ::init();
  add_action("jump", "jump");
}


 
status jump(string str) {
  string tmp1, tmp2;
  if(!str) {
    write(
      "\n\nYou see a pile of hay to jump into.\n"+
      "You jump off the loft and into the pile of hay!\n"+
      "WHHHEEEEEEEEEEE!!!!\n\n");
    this_player()->move_player(
      "suddenly, jumping off the loft!   "+
      "WHHHEEEEEEEEEEE!!!!\n#d/coronos/w/newstar/newbie/rooms/barn1");
    say(this_player()->query_name()+" jumped from the loft, "+
       "and landed in a pile of hay!\n"+
       "WHHHEEEEEEEEEE!!!!\n", this_player());
    return 1;
  }
  return 0;
}
