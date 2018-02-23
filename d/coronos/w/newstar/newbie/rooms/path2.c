/* path2.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if(arg) return;
 
  set_short("a long path");
  set_long(
    "This is a very long path that goes northeast from the  walls of Ille\n"+
    "Coronos.  It leads away from the city, towards some plains.  A dark\n"+
    "mountain range rises out of the horizon, far to the north.  Tall grass\n"+
    "grows in all directions around the dirt path.  The path seems to end\n"+
    "at a small farm.");
  set_day_desc(
    "  The blue sky, and the warm sun bring about a\n"+
    "peaceful atmosphere here.\n");
  set_night_desc(
    "  The atmosphere is very peacfull at along this path.\n"+
    "The silvery moon, and the many stars illuminate the quiet, night sky.\n");
  set_items(({
    "farm",
      "The farm is to the north.\n",
    "horizon",
      "The horizon is very beautiful, no matter what time of day it is.\n",
    "path#down#ground",
      "There isn't anything special about the path.  It is just packed\n"+
      "dirt, from many years of use.  Fairly skinny in width, this is\n"+
      "definitely only a path despite it's long stretch towards a farm.\n",
    "dirt",
      "The dirt is the same soil that the grass is growing in.",
    "grass",
      "The grass is fairly tall, reaching an average sized human's knees.\n"+
      "Green and healthy, the grass stretches far in all directions, swaying\n"+
      "in the wind, like an ocean.\n",
    "Ille Coronos#city",
      "The city of Ille Coronos lies far to the southwest.  Its walls and\n"+
      "only a few building tops can be seen.\n",
    "walls",
      "These are the strong walls of Ille Coronos.\n",
    "plains",
      "The plains stretch out in all directions, blanketed with green\n"+
      "grass, and small groves of trees here and there.\n",
    "mountain#mountains#range#mountain range",
      "Large, dark mountains lie far to the north.  Rising out of the\n"+
      "horizon, their peeks are shrouded in a blanket of clouds.\n",
    "peaks",
      "The peaks are covered in clouds.\n",
    }));
  set_day_items(({
    "sky",
      "Ths sky is a light blue, filled with fluffy white clouds and lit\n"+
      "by the warm, yellow sun.\n",
    "sun",
      "Ouch. The sun hurts your eyes as you stare into it.\n",
    "clouds",
      "The clouds look like mounds of white cotton floating in the sky.\n",
    }));
  set_night_items(({
    "sky",
      "The black sky is speckled with stars, and illuminated by the\n"+
      "silvery moon.  A few clouds catch the moonlight, and appear to\n"+
      "be magical castles in the night sky.\n",
    "stars",
      "Thousands of glowing points of light fill the night sky.\n",
    "moon#moonlight",
      "The silvery moon glows bright in the plains.  It gives you a\n"+
      "sense of calm out here where all is quiet and peavefull.\n",
    "clouds",
      "Fluffy clouds float across the sky, catching the moonlight.\n"+
    "castels",
      "The magical castles are really just clouds, floating by.\n",
    }));
  set_smell(
    "Fresh country air fills your lungs and gives you a feeling of\n"+
    "freedom out in these open plains.\n");
  set_listen(
    "Silence fills the plains.  Only the faint sound of grass, swaying\n"+
    "in the wind, can be heard.\n");
  set_weather(2, 4, 0);  /*beginning newbie area. lit by moon at night.*/
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/yard", "northeast",
      "/d/coronos/w/newstar/newbie/rooms/path1", "southwest",
      }));
}
