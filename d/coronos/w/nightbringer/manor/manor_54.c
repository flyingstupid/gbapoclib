/* MANOR_54.c
   AUTHOR:NIGHTBRINGER
   04-23-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  if(arg) return;


  load_door(({
"file", "d/coronos/w/nightbringer/manor/manor_55.c",
    "secret door",
       3,
    "long", "A trap door in the floor",
    "secret door finders", ({}),
    "direction", "trap door",
  }));


  set_short("Wine Cellar");
  set_long(
"A big dark chamber that is used to store wine. Hundreds of bottles\n"+
"of wine rest in wooden wine racks. The floor and walls are made of\n"+
"earth. The room is very dark, making vision without a light source\n"+
"impossible.\n");


  set_items(({
"wall#walls#floor",
"It is made of earth.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"bottles of wine#wine#bottle#bottles",
"Hundreds of bottles of wine of different types and ages rest in  wooden\n"+
"wine racks.\n",

"wine rack#wine racks#rack#racks",
"Tall wine racks made of wood span the room from floor to ceiling. They\n"+
"are made with thin strips of lattice wood, crisscrossing to make hundreds\n"+
"of small openings just big enough for a bottle of wine to fit snugly in.\n",


           }));


  set_smell("It smells damp and musty in here.\n");

  set_weather(0,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_14.c", "up",
           }));
}

