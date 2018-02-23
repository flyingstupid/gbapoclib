/* barn1.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  if(!present("barrel")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/barrel"),this_object());
  }

  if(!present("stallion")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/npc/stallion"),this_object());
  }

  if(!present("mare")) {
    int i;
    for(i=0; i<2; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/mare"),this_object());}
  }

  if(!present("pony")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/npc/pony"), this_object());
  }

  if(arg) return;
 
  set_short("inside a barn");
  set_long(
    "This is a fairly simple barn.  It has a single, large room with\n"+
    "various seperations for animals, feed, and other equipment.  A\n"+
    "ladder leads to a small loft where excess hay is kept.  There\n"+
    "is a window, level with the loft, that is used to haul up the hay.\n"+
    "A small barrel, in which lanterns are usually stored, stands at\n"+
    "the foot of the ladder.  The heavy barn doors are partially open,\n"+
    "swinging back and forth in the wind.\n");
      
  set_items(({
    "barn#room",
      "The barn is large but simple.  It is well\n"+
      "kept and in good condition.\n",
    "seperations#seperation#fences#fence#partitions",
      "Several areas are partitioned with wooden fences to seperate\n"+
      "animals, such as horses, pigs and goats.  A few other partitions\n"+
      "hold hay, bags of chicken feed, and other such items.\n",
    "animals#animal",
      "Many different animals can be kept in this barn.\n",
    "hay",
      "The hay is fresh and clean for the animals to eat.\n"+
      "There is a large pile of hay below the loft.\n",
    "pile",
      "The pile of hay is quite tall.  It looks soft and comfortable.\n",
    "chicken feed#feed",
      "The chicken feed is fresh and nutritious for the chickens.\n",
    "ladder",
      "The ladder is sturdy, but its rungs look well worn from much\n"+
      "use. Don't fall if you try and climb it.  You might hurt yourself.\n",
    "loft#up",
      "Up above, is a small loft used for storing excess hay.  It can't\n"+
      "really be inspected from ground level, but you notice a ladder\n"+
      "leading up to the loft.\n",
    "window",
      "This is more of a set of double doors set high into the wall of the\n"+
      "barn.  It is mainly used to haul bushels of hay into barn, directly\n"+
      "up to the loft.\n",
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
      "/d/coronos/w/newstar/newbie/rooms/field1.c", "out",
      }));
}



void init() {
  ::init();
  add_action("climber", "climb");
}

status climber(string str) {
  string tmp1, tmp2;
  if(!str) {
    write("What are you trying to climb?  The ladder, maybe?\n");
    return 1;
  }
  if(sscanf(str, "%sladder%s", tmp1, tmp2)) { 
    write("You carefully climb up the ladder\n");
    this_player()->move_player(
        "as "+this_player()->query_pronoun()+" climbs "+
        "up the ladder#d/coronos/w/newstar/newbie/rooms/barn2");
    return 1;
  }
 
  return 0;
}
