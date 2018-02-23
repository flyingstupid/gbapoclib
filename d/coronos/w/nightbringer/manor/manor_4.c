/* MANOR_4.C
   AUTHOR:NIGHTBRINGER
   04-23-97 */

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {
  int I;

  if(!present("griselda")) {
      move_object(clone_object("d/coronos/w/nightbringer/manor/mon/griselda.c"),this_object());
                       }

  if(!present("chair")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/item/chair.c"),this_object());
                        }

  if(!present("sofa")) {
      move_object(clone_object("d/coronos/w/nightbringer/manor/item/sofa.c"),this_object());
                       }
if(arg) return;


  set_short("Sitting Room");
  set_long(
"This large room is used to entertain the Lord and Lady's \n"+
"guest. It is tastefully decorated and screams of wealth.\n"+
"Silken blue curtains cover the rooms four large windows.\n"+
"The floor is covered with a plush, deep blue carpet. Several\n"+
"paintings hang on the walls, and there is a handsome wooden\n"+
"cabinet displaying several of Lady Penor's collectibles.\n");

  set_items(({
"wall#walls",
"They are made of fine wooden paneling\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is covered with a beautiful blue carpet.\n",

"painting#paintings",
"They are paintings of a man and woman at various ages.\n",

"cabinet#wooden cabinet#handsome wooden cabinet",
"A finely crafted wooden cabinet sets in the north corner of the room.\n",

"collectible#collectibles",
"Lady Penor must like rabitts, as several figurines of rabbits are\n"+
" displayed in the cabinet.\n",

"curtain#curtains#blue curtain#blue curtains",
"Beautiful blue, silk drapes cover the rooms windows.\n",

"window#large window#windows#large windows",
"There are four large windows covered with drapes here.\n",

"carpet#blue carpet#deep blue carpet",
"A plush, deep blue carpet covers the floor.\n",

        }));


  set_smell("It smells wonderful in here.\n");

set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_1.c", "west",
           }));
}

