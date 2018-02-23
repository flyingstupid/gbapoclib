
#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
    if(arg) return;

    set_short("the waterfall");        
    set_long(
      "A tall and magnificant waterfall stands just to the north of \n"+
      "this lush field of the softest grass you have ever walked \n"+
      "upon. It rushes downward with such power that it creates a roar \n"+
      "much like that of thunder on a stormy night. A river flows from \n"+
      "its base, cutting its way through the field, running westward \n"+
      "as if trying to escape its powerful source.\n");
    set_day_desc(
      "The waterfall seems magical as the light catches the many \n"+
      "dropplets of water which combine to create such a thing of \n"+
      "power and beauty.\n");
    set_night_desc(
      "You hear the crashing of water through the darkness.\n");

    set_listen("The roaring of the falling water reaches your ears.\n");
    set_smell("Combined together is the sweet smell of lush grass \n"+
      "and the scent of clear water.\n");

    set_items(({
	"waterfall#falls#tall waterfall#magnificant waterfall",
	"The water cascades from a high cliff onto the rocks below. It \n"+
	"creates the fast running river that flows off to the west.", 
	"river#fast river",
	"It moves quickly off to the west, gurgling as it flows over \n"+
	"rocks in it's way",
"grass#green grass",
"Little blades make up the soft blanket of grass found here \n"+
"in the field.",
	"field#green field",
	"A seemingly empty field full of lush green grass",
      }));

    set_day_items(({                
	"sunlight#sun",
	"Do you want to go blind?",
      }));
    set_night_items(({
	"darkness#night",
	"As dark as ash",
      }));
set_exits(({
"/players/alena/ooc/ooc4","southeast",
}));
set_weather(1,4,0);
}
