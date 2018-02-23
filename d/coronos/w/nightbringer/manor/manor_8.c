/* MANOR_8.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("Dining Room");
  set_long(
"The dining toom of the manor is very elegant> A massive oak dining\n"+
"table sets in the center of the room, on top of a silk elvin carpet.\n"+
"Glass oil lamps line the walls of the room, making it very bright.\n"+
"A huge crystal chandelier hangs from the ceiling over the table\n"+
"casting hundreds of miniature rainbows throughout the room as it\n"+
"reflects the light from the lamps. A serving cart, ladden with fine\n"+
"diningware sets beside the table\n");

  set_items(({
"wall#walls",
"They are made of fine wooden paneling.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"The floor is made from a white marble.\n",

"table#dining table#oak dining table#massive oak dining table",
"The table is made from solid oak by someone with extrodinary\n"+
"craftsmanship. Twelve chairs surround the table; five on either\n"+
"side, and two on each end.\n",
"carpet#elvin carpet#silk elvin carpet",
"Made from the best Elvin weavers. It is made of pure silk.\n",

"glass oil lamp#glass lamp#lamp#lamps#glass lamps#glass oil lamps",
"Beautiful glass oil lamps line the walls.\n",

"chandelier#crystal chandelier#huge crystal chandelier",
"It is made out of thousands of tiny crystal prisms.\n",

"cart#serving cart",
"A small wooden serving cart on wheels is resting beside the dining\n"+
"table, it is ladden with diningware.\n",

"chair#chairs",
"Highbacked wooden chairs sorround the table.\n",

"diningware#fine diningware",
"China dishes and silver platters and pitchers are on a serving cart.\n",
"rainbow#rainbows",
"Rainbows dance all over the room, made from light reflecting\n"+
"through the crystals of the chandelier.\n",

           }));


set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_1.c",  "east",
        "d/coronos/w/nightbringer/manor/manor_12.c", "north",
           }));

}

