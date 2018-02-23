#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
    reset_doors(0);
 
    load_door(({
      "destination", "d/coronos/w/darkness/cshop",
      "direction",   "west door",
      "closed",
      "description",
      "The slender door is made of pine.  Many intricate designs are carved\n"+
      "into the door as well as the frame.  An oval window of glass, decorates\n"+
      "the center of the door.\n",
      }));


    ::reset(arg);
    if (arg) return;  
        set_short("the commercial sector of Ille Coronos");
        set_long(
          "On the west side of the street a candle shop has been established, \n"+
          "while on the opposite side well maintained green bushes are growing \n"+
          "along side of D'Tagma Way. A magestic oak tree stands to the east \n"+
          "and looking southeasterly the docks of Ille Coronos can be seen.");
        set_day_desc(
          " The \n"+
          "lamp doesn't need to be lit right now and stands dark.\n");
        set_night_desc(
          " The \n"+
          "oil lamp shines brightly, illuminating the street.\n");
        set_items(({
            "road#stone#stones#walk#walkway#street",
            "Stones laid side by side in careful fashion, worn a great deal \n"+
            "over time, form D'Tagma Way of Ille Coronos.\n",
            "bush#bushes",
            "Small leafy plants that have grown to about two feet in height \n"+
            "and form a line along the side of the road.\n",
            "grass",
            "Pushing its way up through the stones the blades seemingly \n"+
            "reach for the sky.\n",
            "oak tree#tall oak#oak",
            "Huge limbs branch off from a thick, sturdy trunk.\n",
            "candle shop#shop",
            "The candle shop is located in a small wooden building.\n",
            "tree",
            "The oak tree is many years old and is very tall.\n",
            "docks",
            "There is much bustling around the docks of Ille Coronos.\n",
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
          "Salty air floats in from the southeast, stinging your nose.\n");
        set_listen(
          "Boots upon stone, voices, and other bustling sounds fill the air \n"+
          "about you in this busy section of the city of Ille Coronos.\n");
        set_weather(2, 4, 0);
        set_exits(({
            "/d/coronos/w/alena/ille/c_5","northwest",
            "/d/coronos/w/alena/ille/c_7","southeast",
          }));    
}
