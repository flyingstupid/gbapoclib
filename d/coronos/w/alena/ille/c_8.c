#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

    reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/darkness/genstore.c",
     "direction", "east door",
     "long",
          "A huge iron bound set of double doors.\n",
  }));
 

   load_door(({
   "destination",     "d/coronos/w/newstar/rooms/pub.c",
   "direction",       "west door",
   "description",
     "The heavy, old door of the pub is made out of solid oak,\n"+
     "smooth and shiny from wear.  The thick hinges, long bindings\n"+
     "and curved handle are of intricately molded cast iron.  In\n"+
     "the top half of the door is a little stain glass window\n"+
     "depicting a wyvern at sunset.\n",
 
    }));

    if (arg) return;
 
    set_short("the commercial sector of Ille Coronos");
    set_long(
      "The grey cobblestones making up Eastern Commerce seem to especially \n"+
      "well placed and well cared for. Bushes line the street and grass \n"+
      "tries to push its way up through the stones, growing very sparsely \n"+
      "within this road. The sea lies to the east, along with the docks \n"+
      "of Ille Coronos.  A pub stands on the west of the road, and opposite\n"+
      "it is a general store.\n");
    set_items(({
      "road#stone#stones#walk#walkway#street",
        "Stones laid side by side in careful fashion, worn a great deal \n"+
        "but maintained.\n",
      "bush#bushes",
        "Small leafy plants that have grown to about two feet in height \n"+
        "and form a line along the side of the road.\n",
      "grass",
        "Pushing its way up through the stones the blades seemingly \n"+
        "reach for the sky.\n",
      "seas",
        "The seas are very rough.\n",
      "docks",
        "The docks are full of bustling people.\n",
      "pub",
        "The pub looks very inviting.\n",
      "general store#store",
        "The grey stone and iron walls of the general store\n"+
        "give it the look of a small castle.\n",
      }));
    set_day_items(({
        "lamp#light#oil lamp post#lamp",
        "The oil lamp stands about seven feet tall and the wick is \n"+
        "encased by glass and steel, unlit for now.\n",
 
      }));
    set_night_items(({
        "lamp#light#oil lamp post#lamp",
        "The oil lamp stands about seven feet tall and the wick is \n"+
        "lit, illuminating the street below. It has been encased by \n"+
        "glass and steel, protecting the flame from wind and rain.\n",
      }));
    set_smell(
      "Salty sea air seems to follow PyRosh Avenue.\n");
    set_listen(
      "Boots upon stone, voices, and other bustling sounds fill the air \n"+
      "about you in this busy section of the city of Ille Coronos.\n");
    set_weather(2, 4, 0);
    set_exits(({
        "/d/coronos/w/alena/ille/c_9","northeast",
        "/d/coronos/w/alena/ille/c_7","southwest",
      }));
}

