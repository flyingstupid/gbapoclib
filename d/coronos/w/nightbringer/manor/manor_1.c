/* MANOR_1.C
   AUTHOR:NIGHTBRINGER
   04-23-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
 reset_doors(arg);

  load_door(({
     "file", "d/coronos/w/nightbringer/manor/path_3.c",
     "direction", "south door",
     "long",
     "open",
          "A plain wooden door.\n",
  }));

  if(arg) return;


  set_short("Entrance Hall");
  set_long(
"You have come into a brilliant entrance hall lit by candles. Ahead, a \n"+
"marble staircase, flanked by two suits of plate armour ascends to the\n"+
"second floor of the Manor. A doorway is to your right, leading into\n"+
"some sort of cloakroom. Other doors lead out of the hall: one on either  \n"+
"side of the stairs, one on the left-hand wall, and two more on the right.\n"+
"The entry hall is warm and cheerful. The walls and floor are made of wood\n"+
"while the ceiling is made of stone. A couple of pictures hang on the   \n"+
"walls here, and a small potted plant sets on a table.  \n");

  set_items(({
"wall#walls",
  "It is made out of fine wooden paneling.\n",

"floor", "The floor is made from wooden planks.\n",
"stairs#stair#marble staircase#staircase",
  "A long staircase made of marble leads up to the second floor.\n",

"armour#plate armour#suit of armour#suits of armour",
"Large suits of Plate Armour stand on either side of the staircase.\n"+
"They are for mere decoration though, as they are made of tin.\n",

  "ceiling",
  "The ceiling is made of stone and looks very sturdy.\n",

  "candle#candles",
  "Silver candelbras mounted on the walls hold long, white candles.\n",

"candlebra#candlebras",
"They are made of silver and hold long, white candles.\n",
  "picture#pictures",
  "They are of a man and woman at varies stages in life.\n",

"small potted plant#potted plant#plant#small plant",
"It's a healthy looking ivy plant in a blue flower pot.\n",

  "table",
  "A small table made of wood. A plant rests on it.\n",

"cloakroom",
"To the southest you see a cloakroom.\n",
             }));

  set_listen("You can hear voices coming from the north\n");

  set_smell("It smells nice and clean, someone must take good care of this place.\n");

   set_weather(2,2,0);

  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_29.c", "up",
        "d/coronos/w/nightbringer/manor/manor_2.c",  "southeast",
        "d/coronos/w/nightbringer/manor/manor_4.c",  "east",
        "d/coronos/w/nightbringer/manor/manor_5.c",  "northeast",
        "d/coronos/w/nightbringer/manor/manor_6.c",  "north",
        "d/coronos/w/nightbringer/manor/manor_7.c",  "northwest",
        "d/coronos/w/nightbringer/manor/manor_8.c",  "west",
  }));
}
