/* MANOR_49.C
   AUTHOR:NIGHTBRINGER
   04-27-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;



  set_short("Hallway");
  set_long(
"A long hallway heads off into the distance southward. A peach colored\n"+
"carpet covers the floor, and the walls are painted blue. Silver sconces\n"+
"hang on the walls holding white candles. The air here is a bit chilly.\n");

  set_items(({
"wall#walls",
"They are made out wood and painted blue.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is covered with a peach colored carpet.\n",

"sconce#sconces#silver sconce#silver sconces",
"Silver sconces hang on the walls at spaced intravals, holding white candles\n",

"candle#candles#white candle#white candles",
"Long, white candles are held by silver sconces",

"carpet#peach colored carpet",
"An attractive peach colored carpet covers the floor, it is in immaculate\n"+
"condition.\n",

           }));


  set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_47.c",  "north",
        "d/coronos/w/nightbringer/manor/manor_51.c",  "south",
  }));

}

