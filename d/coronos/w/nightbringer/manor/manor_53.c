/* MANOR_53.C
   AUTHOR:NIGHTBRINGER
   04-27-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(0);

  load_door(({
     "file", "d/coronos/w/nightbringer/manor/manor_51.c",
     "direction", "west door",
     "long",
          "A plain wooden door.\n",
   "open",
  }));
  load_door(({
     "file", "d/coronos/w/nightbringer/manor/manor_50.c",
     "direction", "north door",
     "long",
          "A plain wooden door.\n",
   "open",
 }));
  if(!present("lady penor")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/lapenor.c"),this_object());
       }
  if(arg) return;

  set_short("Master Bedroom");
  set_long(
"This is an immaculately decorated bed chamber. A plush, pink carpet\n"+
"covers the floor and the walls are painted a baby blue color. A huge\n"+
"canopied bed dominates the room. Oak bedside tables set on either side\n"+
"of the bed, and a  massive oak chest of drawers takes up the entire\n"+
"southern wall.\n");


  set_items(({
"wall#walls",
"They are made of wood and painted a baby blue\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is covered with a plush, pink colored carpet.\n",

"huge canopied bed#canopied bed#bed#huge bed",
"A massive featherbed covered with a canopy dominates the room . A\n"+
"handsome quilt and two fluffy pillow are on the bed.\n",

"chest#chest of drawers#chest of drawer#drawer\
#drawers",
"A massive dresser that has several drawers to store clothes in\n",

"pot#chamber pot",
"This is used by the guest at night to relieve themselves without having\n"+
"to go down stairs.\n",

"quilt#handsome quilt",
"A patchwork quilt covers the small bed\n",

"pillow#fluffy pillow",
"Two fluffy white pillow lays at the head of the bed.",

"table#tables#bedside table#bedside tables",
"Oaken tables set on either side of the bed.\n",

"carpet#pink carpet#plush pink carpet",
"A plush pink carpet covers the floor.\n",

           }));


  set_weather(2,2,0);

}

