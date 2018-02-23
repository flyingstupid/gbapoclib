/* tree1.c  Newbie Area */
/* Darkness & Newstar */

#include <mudlib.h>
inherit ROOM;

void reset (status arg){

 if(!present("weasel")) {
    int i;
    for(i=0; i<2; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/weasel"),this_object());
    } 
 }

 if(!present("goblin")) {
   move_object(clone_object(
   "/d/coronos/w/newstar/newbie/npc/goblin"),this_object());
 }

  if(arg) return;

  set_short("base of tree");
   set_long( 
    "The somber atmosphere of the dark forest lightens with the straightening\n"+
    "of the ancient trees.  The thick undergrowth masks a slight path that ends\n"+
    "before an old, gnarled tree.  The sullen canopy cloaks the forest with its\n"+
    "thick, dark folliage.  An eerie mist blankets the forest floor, making the\n"+
    "path that runs to the east hard to see.");
  set_day_desc(
    "  The shadows of the forest overwhelm,\n"+
    "even by the hours of daylight.  Very little light passes through the dense\n"+
    "canopy of the towering trees, making all things seem unfriendly.\n"+
    "unfriendly.\n");
  set_night_desc(
    "  In the still of the night, the\n"+
    "atmosphere is multiplied tenfold.  Shadows suffocate the surroundings,\n"+
    "playing with the imagination.  Thin streams of moonlight trickle down.\n");
  set_items(({
    "dark forest#forest",
      "This dark forest exudes an unpleasent atmosphere, making you not want to\n"+
      "stick around very long.  You wonder how anything could flourish here, but\n"+
      "many things do.\n",
    "undergrowth",
      "Various different types of ground plants and bushes grow underneath the\n"+
      "ancient trees.  Here its rather thin, but it gets thicker up ahead.\n",
    "tree#trees",
      "The tall, somber trees tower above you with and ancient yet eerie grace.\n"+
      "They have large, thick trunks and limbs, covered in dark, dense leaves.\n"
    "ground plants",
      "There are plants that spread out and grow close to the forest floor.\n",
    "bushes",
      "These are various types of bushes that flourish even without much light.\n",
    "trunk",
      "The tree trunks are thick and gnarled, looking very old.\n",
    "limb#limbs",
      "The tree limbs are thick, gnarled and very strudy.  They grow out high\n"+
      "above the ground, covered with dark green leaves.\n",
    "canopy#leaves#folliage",
      "Large, dark green leaves cover the limbs of the tall, ancient trees,\n"+
      "forming a shadowed canopy.  It grows thick and dense, letting in\n"+
      "little light to illuminate the ground\n",
    "forest floor#ground",
      "The ground of the forest is made up of rich loam and is blanketed with\n"+
      "dead leaves and sticks.\n",
    "dead leaves",
      "These are just dry, brown leaves on the forest floor.\n"+
      "They crunch when you walk on them.\n",
    "sticks#stick",
      "Some sticks that have fallen from the tall trees.\n",
    "mist",
      "A bone chilling, transparent mist that slowly rolls in from the deeper\n"+
      "parts of the forest, hovering just above the ground.\n",
    "path",
      "A thin, barely visible path leads through the underbrush to a\n"+
      "destination unknown.  It is covered in gnarled roots, hindering\n"+
      "passage.  The path continues off to the east.\n",
    "root#roots",
      "Thick, gnarled roots from the ancient trees rising out of the ground,\n"+
      "ready to trip a careless traveler.\n",
    "tree",
      "One large tree can be easily singled out from the rest with its old,\n"+
      "gnarled shape.  It looks easy to climb.\n",					
    }));
  set_day_items(({
    "shadows#shadow",
      "The dark shadows creep along the edges of your sight, playing tricks\n"+
      "with your mind, even in the day.\n",
    "light",
      "A little light penetrates the thick canopy, giving you a little hope.\n",
    }));
  set_night_items(({
     "shadows#shadow",
       "The black shadows settle about you, overwhelming you with their\n"+
       "opressing presense.\n",
     "moonlight",
       "Thin, silvery rays of moonlight filter through the leaves of the trees,\n"+
       "providing scant light.\n",
     }));
  set_smell(
    "A dampness assults your nostrils, permiating the air around you.\n"+
    "You also smell something else, something thats just not right.\n");
  set_listen(
    "A gust of wind rustles the leaves, making the tall trees creak.\n"+
    "Dry leaves crunch and a stick snaps somewhere in the distance.\n"+
    "An unidentifable noise sends chills up your spine.\n");
  set_weather(1, 4, 0);
  set_climb(2);
  set_fall_dam(random(4));  
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/forest4", "east",
      }));
}



void init() {
  ::init();
  add_action("climb1", "climb");
}
 
 
 
status climb1(string str) {
  string tmp1, tmp2;
  if(!str) {
    write("What are you trying to climb?\n");
    return 1;
  }
  if(sscanf(str, "%stree%s", tmp1, tmp2)) {
    /*so they can type climb the tree*/
    write("You scamper up the tree\n");
    this_player()->move_player(
        "as "+this_player()->query_pronoun()+" climbs "+
        "up the tree#d/coronos/w/newstar/newbie/rooms/tree2");
    return 1;
  }
 
  else {
    return 0;
  }
}
