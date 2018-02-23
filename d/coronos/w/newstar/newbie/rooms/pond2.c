/* pond2.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
#define SWIM            (int)this_player()->query_swim()
inherit ROOM;

void reset (status arg){

  if(!present("crack")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/crack"),this_object()); 
  }

  if(!present("duck")) {
    int i;
    for(i=0; i<5; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/duck"),this_object());
    } 
  }

  if(arg) return;

  set_short("a pond");
  set_long(
    "This is the far end of the medium sized pond.  Here the wilderness\n"+
    "is more prevelent and the endless rolling plains are just a few feet\n"+
    "away.  The pond vegetation grows much denser but the water is still\n"+
    "as crystal clear.  Rocks and stones lie scattered about the edges of\n"+
    "the pond.  Off to the distant north, a dark forest still looms.  The \n"+
    "forest starts to the west.  To the south is a cow field.");
  set_day_desc(
    "  The bright,\n"+
    "beaming sun warms the air, traveling across a blue cloudless sky.\n"+
    "A gentle breeze blows, rippling the cool waters of the pond.\n");
  set_night_desc(
    "  Numerous\n"+  
    "stars and a silvery moon, nestled within a dark, velvet sky,\n"+
    "illuminate the atmosphere around the pond.  Little fireflies\n"+
    "blink and dart amoung the tall reeds.\n");
  set_items(({
    "pond",
      "A medium sized, oval body of cool, crisp water.  Many stones are\n"+
      "strewn along its shore amoung the flourishing plants.  This is a\n"+
      "perfect habitat for many shy creatures.\n",
    "water",
      "The water is clean and clear, you think that you can almost see\n"+
      "the bottom.  Little fish swim languidly just beneath the surface.\n"+
      "It looks so cool and inviting. Why not take a little dip?\n",
    "fish",
      "These are just lazy, little sunfish.\n", 
    "surface",
      "The surface of the pond is glassy like a mirror, reflecting\n"+
      "its surroundings perfectly.\n",
    "vegetation",
      "The vegetation of the pond consists of water reed, cattails and\n"+
      "water lilies.  All which flourish along the edges of the pond.\n"+
      "everything around it.\n",
    "reeds#tall reeds#reed",
      "These are tall, green reeds, swaying in the warm breeze.\n"+
      "Being almost as tall as a person, they are perfect for\n"+
      "hiding the shy wildlife living about the pond.\n",
    "plains",
      "The plains undulate out in all directions, blanketed with tall, green\n"+
      "grass, and small groves of trees here and there.\n",
    "cattails#cat tails",
      "Long, slim plants with a dark brown tail on the top of the stalks.\n",
    "lily pads#water lilies#lily pad#water lily#pads",
      "Various sizes of flat, circular leaves that float on the surface of\n"+
      "the pond.  From between the pads, little white, yellow or pink\n"+
      "flowers spring up from the water.  They are very pretty and delicate.\n",
    "dark forest#forest",
      "Far off in the hazy distance, stands a dark, almost gloomy forest.\n"+
      "It does not look too particularly inviting.  You wonder what could\n"+
      "live there, in the darkness.\n",
    "cow field#field",
      "A fair sized, grassy field dotted with a few trees.\n",
    "trees",
      "Trees of different sizes and kinds dot the cow field.\n",
    "flower#flowers#lily#lilies",
      "Delicate, little yellow, white ar pink flowers growing out of\n"+
      "the water and from between the lily pads.\n",
    "edge#edges",
      "The edges of the pond are low all the way around.  There are many\n"+
      "stones lying around on the shore, amoung the plants and the grass.\n",
    "grass",
      "The lush, dark green grass of the plains grows right up to the stone\n"+
      "strewn edges of the pond.\n",
    "stone#stones",
      "Many smooth, oval stones lie along the edge of the pond.  They look\n"+
      "like they would fit perfectly in your hand, perfect for skipping.\n",
    "rock#rocks",
      "A few large rocks lie around the edges of the pond.  You wonder how\n"+
      "they got there, especially one in particular huge rock that sits\n"+
      "half in the water.\n",
    "huge rock#large rock",
      "A rather large rock sits half in and half out of the water.  Its looks\n"+
      "rather odd just sitting there, but at closer inspection you can see\n"+
      "something small glinting in one of the cracks.\n",
      }));
  set_day_items(({
    "sky",
      "The sky is brilliant blue, without a cloud in sight.\n",
    "sun",                   
      "Ow.. the bright sun isn't something you want to be looking\n"+
      "at directly.\n",
    "air",
      "What are you trying to look at, silly? You can't see air!\n",
    }));
  set_night_items(({
    "sky",
      "The dark, velvet sky covers the earth like a black blanket.\n"+
      "A whole other world has come to life under its darkness.\n",
    "stars",
      "The innumerable stars sparkle and twinkle, nestled within the\n"+
      "velvet blanket of sky.\n",
    "moon#moonlight",
      "The silvery moon sheds her pale light upon the pond, moonbeams\n"+
      "dancing on the surface.\n",
    "fireflies",
      "These little insects are like stars fallen from the night sky\n"+
      "as they dance about above the pond.\n",      
    "moonbeams"
      "Little silver rays of light from the silvery moon.\n",  
    }));                               

  set_extra_objects(({
    "stone", "d/coronos/w/newstar/newbie/items/stone", }));

  set_smell(
    "The damp smell of the pond mingles in your nostrils with the fresh\n"+
    "scent of the plains.\n");
  set_listen(
    "It is pretty quiet here, except for the chours of frogs, the chirps\n"+
    "of the crickets and the breeze rustling through the reeds.\n");
  set_weather(2, 4, 0);  /*beginning newbie area. lit by moon at night.*/
}



void init() {
  ::init();
  add_action("swimmer", "swim");
}



status swimmer(string str) {
  string tmp1, tmp2;

  if(!str || sscanf(str, "%spond%s", tmp1, tmp2)) {
    
    if(SWIM > random(4)) {
      write("\nYou lazily swim across the pond.\n"+
            "The water is cool and refreshing!\n\n");
      this_player()->move_player(
      ", swimming across the pond.\n"+
      "#d/coronos/w/newstar/newbie/rooms/pond1");
      return 1;  
    }

    else {
      write("\n\nYou attempt to swim across the pond.\n"+
            "Your swimming skills aren't good enough,"+
            "and you almost drown!\n"+
            "Luckily you make it back to shore.\n");
      say(this_player()->query_name()+
          " tries to swim across the pond, but "+
          this_player()->query_pronoun()+
          " almost drowns!\n", this_player());
      this_player()->hit_player(random(8)+1);
      return 1;
    }
  }

  else {
    write("What are you trying to swim across?\n");
    return 1; }

return 0;
}
