/* MANOR_29.C
   AUTHOR:NIGHTBRINGER
   04-26-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;


  set_short("Hallway");
  set_long(
"A small hallway with a marble staircase leading down to the first floor\n"+
"of the manor. The hallway opens up to hallways running north and south\n"+
"on both the east and west sides. The floor is covered with an attractive\n"+
"peach colored carpet that is in immaculate condition. Silver sconces hang\n"
"on the walls holding their candles to provide light for the stairway and\n"+
"hallway. A massive oil painting hangs on the center of the north wall and\n"+
"a table with a small framed portrait sits beneath it.\n");

  set_items(({
"wall#walls",
"They are made of made of wood\n",

"stairs#stair#staircase#marble stairs#marble staircase",
"A long staircase made of marble leads down\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"candle#candles",
"White candles in silver sconces are on the walls.\n",

"carpet#peach colored carpet",
"An attractive peach colored carpet covers the hallway floor",

"small framed portrait#framed portrait#portrait",
"This small picture is of a young boy sitting on a pony",

"north wall",
"A massive oil painting hangs here, beneath it is a small table on which\n"+
"sets a small framed portrait.\n",

"sconce#silver sconce#sconces#silver sconces",
"silver sconces hang on the walls at intervals, holding long, white candels\n",
"floor",
"The floor is covered with a peach colored carpet.\n",

"massive oil painting#oil painting#painting",
"It is a beautiful oil painting of the city of Ille\n"+
"Coronos, as seen from the docks.\n",

"table#small table",
"A small wooden table with a picture setting on top of it.\n",
             }));

  set_smell("It smells nice and clean, someone must take good care of this place.\n");

set_weather(2,2,0);

  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_1.c",   "down",
        "d/coronos/w/nightbringer/manor/manor_47.c"          }));

  set_smell("It smells nice and clean, someone must take good care of this place.\n");

  set_weather(2,4,0);

  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_1.c",   "down",
        "d/coronos/w/nightbringer/manor/manor_47.c",  "east",
        "d/coronos/w/nightbringer/manor/manor_36.c",  "west",
  }));
}
