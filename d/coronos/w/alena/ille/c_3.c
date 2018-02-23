#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
set_short("the commercial sector of Ille Coronos");
  set_long(
"Stone pavement lines the street, worn smooth due to the constant \n"+
"wear of countless boots and hooves. Western Commerce runs to the \n"+
"northeast and southwest, joining to University running northward.\n"+
"Bushes grow along the side of the road and grass tries to make \n"+
"its way up through the stones.");
  set_day_desc(
" The lamp post is lit and \n"+
"stands at the side of the road.\n");
  set_night_desc(
" The oil lamp is lit and lights \n"+
"up Western Commerce.\n");
  set_items(({
"road#stone#stones#walk#walkway#street",
"Stones laid side by side in careful fashion, worn a great deal \n"+
"over time, forms Western Commerce of Ille Coronos.\n",
    "bush#bushes",
"Small leafy plants that have grown to about two feet in height \n"+
"and form a line along the side of the road.\n",
    "grass",
"Pushing its way up through the stones the blades seemingly \n"+
"reach for the sky.\n",
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
"The scent of what seems to be freshly baked bread seems to \n"+
"be carried upon the air from the northeast.\n");
  set_listen(
"Boots upon stone, voices, and other bustling sounds fill the air \n"+
"about you in this busy section of the city of Ille Coronos.\n");
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/darkness/univst4", "north",
"/d/coronos/w/alena/ille/c_2","northeast",
"/d/coronos/w/alena/ille/c_4","southwest",
      }));
}
