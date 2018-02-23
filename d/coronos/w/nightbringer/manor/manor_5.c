/* MANOR_5.C
   AUTHOR:NIGHTBRINGER
   04-24-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {

if(!present("herman")) {
   move_object(clone_object("d/coronos/w/nightbringer/manor/mon/herman.c"),this_object());
                       }


if(!present("sal")) {
   move_object(clone_object("d/coronos/w/nightbringer/manor/mon/sal.c"),this_object());
                        }

if(!present("dangor")) {
   move_object(clone_object("d/coronos/w/nightbringer/manor/mon/dangor.c"),this_object());
                        }

if(!present("lord penor")) {
   move_object(clone_object("d/coronos/w/nightbringer/manor/mon/lpenor.c"),this_object());
                       }
if(arg) return;


  set_short("smoking room");
  set_long(
"This is Lord Penors' private play place, it is where he\n"+
"entertains some of Ille Coronos' nobles in nightlong bouts\n"+
"of high stakes gaming. The room is masculine in\n"+
"design. A card table sets in the center of the room,\n"+
"surrounded by four high backed wooden chairs. A large\n"+
"bearskin rug lays on the floor beside the table, and\n"+
"several of Lord Penors' trophies hang on the walls throughout\n"+
"the room.\n");

  set_items(({
"wall#walls",
"They are made of fine wooden paneling\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is fashioned out wooden planks.\n",

"table#card table",
"It is a small wooden table designed to play cards on.\n",

"chair#chairs#wooden chair#wooden chairs",
"This chair is finely crafted out of oak wood\n",

"rug#bearskin rug#large bearskin rug",
"It is the pelt of a very large cavebear.\n",

"trophy#trophies",
"The stuffed and mounted heads of a several wild creatures have been\n"+
" displayed on the walls of the room.\n",


        }));


  set_smell("It smells of ale and cigar smoke.\n");

set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_1.c", "southwest",
        "d/coronos/w/nightbringer/manor/manor_6.c", "west",
        "d/coronos/w/nightbringer/manor/manor_9.c", "north",
           }));
}

