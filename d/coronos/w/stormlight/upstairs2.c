#include <mudlib.h>
inherit ROOM;

void reset (status arg) {
reset_doors(arg);
if (arg) return;

set_short("Manservants Quaters");
set_long("This room is small and spartanly furnished. There is a bed,  \n"+
        "a small night stand, a desk and a bear skin rug. The \n"+
        "walls are bare and drab with a single window looking out \n"+
        "into town.\n");

set_day_items(({"window", "The window has a clear view overlooking a large part of the \n"+
                   "residential district. It looks to be a nice day outside.\n",
            "candle", "The candle looks as though it has seen alot of use. It is unlit.\n",
         }));

set_night_items(({"window", "The window is small and overlooks the residential district. \n"+
                    "Right now it is too dark outside to see anything.\n",
             "candle", "The candle looks as though it has seen alot of use. It is lit.\n",
          }));

set_weather(2,1,0);

set_items(({"bed", "The bed is small and meager. Barely adaquate for anyone. The \n"+
                "sheets are made from a very itchy material.\n",
             "night stand#stand", "The night stand is a small round oaken table. There is nothing on \n"+
                           " it except a few drops of wax.\n",
             "rug", "The rug is actually the hide of a large black bear. It looks as \n"+
                "though it has seen a good bit of wear.\n",
             "desk", "The desk is neat and tidy. There is a small candle on it and a \n"+
               "small piece of parchment.\n",
            "parchment", "The parchment is old and brittle, it has something scrawled on it: \n"+
                   "Jarvis, \n"+
                    "The fireplace should only be used\n"+
                    "in case of emergancy or by me. \n"+
                    "It goes right to the commerce \n"+
                    "district. \n"+
                    "     Sartan Gildentongue \n",
         }));



load_door(({
"destination", "/d/coronos/w/stormlight/upstairs1",
"direction", "north door",
"description", "A simple wooden door.",
"unlocked",
}));
}


