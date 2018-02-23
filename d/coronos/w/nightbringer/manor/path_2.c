/* PATH_2.C
   AUTHOR:NIGHTBRINGER
   05-28-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;


 set_short("Path to the Manor");
 set_long(
"This narrow cobblestone path heads north to a majestic looking building \n"+
"that sets on a small hill overlooking the town of Ille Coronos. Small \n"+
"meticulously trimmed shrubs line the path on its northern and southern \n"
"sides.\n");

  set_items(({
"narrow cobblestone path#narrow path#path#cobblestone path#",
"It is a narrow path made of cobblestone. It heads west and south.",

"majestic looking building#majestic building#building",
"A white manor house stands atop a hill overlooking the city of Ille \n"+
"Coronos. It is a grand building with tall spires, a collection of\n"+
"lightning rods, and windows that catch the light from the sky and\n"+
"toss it back as a beautiful splash of color.\n",

"meticulously trimmed shrubs#shrubs#shrub#trimmed shrub#trimmed shrubs",
"They are small shrubs that are very well taken care of.\n",
}));

  set_listen("You can hear the hustle and bustle of the city to the north\n"+
"and south of here.\n");


  set_weather(1,4,0);

  set_exits(({
        "d/coronos/w/nightbringer/manor/path_3.c", "north",
        "d/coronos/w/nightbringer/manor/path_1.c",  "east",
  }));
} 


