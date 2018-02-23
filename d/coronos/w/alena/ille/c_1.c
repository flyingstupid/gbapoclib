#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  object ob;

  if(!present("cat")) 
    move_object(clone_object("d/coronos/w/angel/city/monst/cat"),this_object());
    if (arg) return;

    set_short("the commercial sector of Ille Coronos");
    set_long(
      "Western Commerce meets up here with PyRosh Avenue, a street well \n"+
      "known by the men, and women, of the sea. Grey stones line both \n"+
      "roads, worn down by countless boots and wagon wheels. A tall sign \n"+
      "has been placed at the northern tip of the intersection, next \n"+
      "to a lamp post.");
    set_day_desc(
      " The lamp is unlit.\n");
    set_night_desc(
      " The lamp has been lit and illuminates the roads.\n");
    set_items(({
	"road#stone#stones#walk#walkway#street",
	"Stones laid side by side in careful fashion, worn a great deal \n"+
	"over time, forming the intersection of Western Commerce and \n"+
	"PyRosh Avenue.\n",
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
      "Salty sea air seems to follow PyRosh Avenue.\n");
    set_listen(
      "Boots upon stone, voices, and other bustling sounds fill the air \n"+
      "about you in this busy section of the city of Ille Coronos.\n");
    set_weather(2, 4, 0);
    set_sign_message(
      "Southwest: Western Commerce \n"+
      "Southeast: PyRosh Avenue \n");
    set_exits(({
	"/d/coronos/w/alena/ille/c_13","southeast",
	"/d/coronos/w/alena/ille/c_2","southwest",
      }));
}
