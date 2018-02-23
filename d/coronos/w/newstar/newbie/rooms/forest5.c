/* forest5.c -- newbie */
/* Darkness and Newstar */

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
 
  if(!present("raven")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/npc/raven"),this_object());
  }

  if(arg) return;
 
  set_short("a dark forest");
  set_long(
    "The beginnings of the dark forest set the mood for something rather grim\n"+
    "and unfriendly.  The underbrush here is spare, getting thicker a few feet\n"+
    "up ahead.  The tall, somber trees tower above with dense dark folliage that\n"+
    "lets in very little light.  A thin mist hovers just above the ground, adding\n"+
    "to the ominous atmosphere of this forest.  A small path can be in the thick\n"+
    "undergrowth a little ways to the north.  To the south lies a large field.\n");
  set_day_desc(
    "Even though it is day, darkness overwhelms this place.  A few sunbeams\n"+
    "manage to stream through the drab leaves of the ancient trees, illuminating\n"+
    "odd patches of transparent mist.\n");
 set_night_desc(
    "The night sky cannot be seen up above.  Everything is dark and the shadows\n"+
    "seem to devour the surroundings.  A little moonlight manages to seep through\n"+
    "the canopy of leaves.\n");
  set_items(({
    "dark forest#forest",
      "This dark forest exudes an unpleasent atmosphere, making you not want to\n"+
      "stick around very long.  You wonder how anything could flourish here, but\n"+
      "many things do.\n",
    "underbrush#undergrowth",
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
    "folliage#leaves",
      "Large, dark green leaves cover the limbs of the tall, ancient trees.\n"+
      "They grow thick and dense, letting little light touch the ground.\n",
    "ground#forest floor",
      "The ground of the forest is made up of rich loam and is blanketed with\n"+
      "dead leaves and sticks.\n",
    "dead leaves",
      "These are just dry, brown leaves on the forest floor.\n",
    "sticks#stick",
      "Some sticks that have fallen from the tall trees.\n",
    "mist",
      "A bone chilling, transparent mist that slowly rolls in from the deeper\n"+
      "parts of the forest, hovering just above the ground.\n",
    "path#north",
      "A little, well worn path amid the undergrowth that leads northward.\n",
    "sunny field#south",
      "The sunny field to the south is a sharp contrast with the darkness of\n"+
      "the shadows of this forest.\n",
    }));
 set_day_items(({
    "sunbeams",
      "Bright rays of light penetrate the gloom, illuminating cetain patches\n"+
      "of hovering mist.\n",
    }));
  set_night_items(({
     "shadows#shadow",
       "Dark shadows that creep along the edges of your sight, threatening to\n"+
       "to overwhelm you.\n",
     "moonlight",
       "Thin, silvery rays of moonlight filter through the leaves of the trees,\n"+
       "providing scant light.\n",
     "canopy",
       "A thick layer of dark leaves high up above you.\n",
       }));
  set_smell(
    "A dampness assults your nostrils, permiating the air around you.\n"+
    "You also smell something else, something thats just not right.\n");
  set_listen(
    "The wind whistles through the trees, creaking the limbs of the trees.\n"+
    "Other then that, things seem to me unusally still.  Every now and then\n"+
    "you hear a stick snap off in the distance.\n");
  set_weather(1, 4, 0);
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/forest6",  "south",
      "/d/coronos/w/newstar/newbie/rooms/forest4", "north",
      }));
}
