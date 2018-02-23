/* forest3.c  Newbie Area */
/* Darkness & Newstar */
 
#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
 
 if(!present("goblin")) {
    int i;
    for(i=0; i<2; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/goblin"),this_object());
    }
 }
 
 if(!present("kobold")) {
   move_object(clone_object(
   "/d/coronos/w/newstar/newbie/npc/kobold"),this_object());
 }
 
  if(arg) return;
 
  set_short("a dark forest");
  set_long(
    "The dark forest is dense and wild here with thick undergrowth spreading\n"+
    "over the small, thin path.  The tall, dark trees looms above, blocking\n"+
    "out the light with their broad folliage. An eerie mist hovers between\n"+
    "the shadowed canopy and the the ancient roots of the dense vegatation\n"+
    "The slim path continues off into the darkness to the north and west.\n");
  set_day_desc(
    "The shadows of the forest overwhelm, even by day.  Little light passes\n"+
    "through the dense canopy of the towering trees, making all things seem\n"+
    "unfriendly.\n");
  set_night_desc(
    "In the still of the night, the unpleasent atmosphere is multiplied\n"+
    "tenfold.  Shadows suffocate the surroundings, playing with the\n"+
    "imagination.  Thin streams of moonlight trickle down.\n");
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
    "canopy#folliage#leaves",
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
      "passage.  The path continues off to the north and to the west.\n",
    "root#roots",
      "Thick, gnarled roots from the ancient trees rising out of the ground,\n"+
      "ready to trip a careless traveler.\n",
    "west",
      "The forest seems a little less dense a ways to the west.\n",
    "north",
      "The forest gets darker off to the north.\n",
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
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/forest2", "north",
      "/d/coronos/w/newstar/newbie/rooms/forest4", "west",
      }));
}
