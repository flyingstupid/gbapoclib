#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("the commercial sector of Ille Coronos");
    set_long(
      "Lines of well trimmed bushes and small oak trees help to define the \n"+
      "sides of D'Tagma Way to the northwest, while Eastern Commerce \n"+
      "branches off to the northeast. A large oak tree stands just to \n"+
      "the north, its huge branches hanging overhead.");
    set_day_desc(
      " The tall oil \n"+
      "lamp remains unlit at this time of day.\n");
    set_night_desc(
      " The oil lamp \n"+
      "shines very brightly, illuminating the intersection.\n");
    set_items(({
	"road#stone#stones#walk#walkway#street",
	"Stones laid side by side in careful fashion, worn a great deal \n"+
	"over time, forming the intersection of Eastern Commerce and \n"+
	"D'Tagma Way.\n",
	"bush#bushes",
	"Small leafy plants that have grown to about two feet in height \n"+
	"and form a line along the side of the road.\n",
	"grass",
	"Pushing its way up through the stones the blades seemingly \n"+
	"reach for the sky.\n",
	"oak tree#tall oak tree#big oak#oak",
	"Its trunk is thick and very sturdy, and its branches hang overhead.\n",
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
  "glass and steel, brightly shining through the night.\n",
      }));
    set_smell(
      "A smell of salty sea water floats in from the east.\n");
    set_listen(
      "Boots upon stone, voices, and other bustling sounds fill the air \n"+
      "about you in this busy section of the city of Ille Coronos.\n");
    set_weather(2, 4, 0);
    set_sign_message(
      "Northeast: Eastern Commerce \n"+
      "Northwest: D'Tagma Way \n"+
      "Southeast: Docks of Ille Coronos \n");
    set_exits(({
	"/d/coronos/w/alena/ille/c_8","northeast",
	"/d/coronos/w/alena/ille/c_6","northwest",
"/d/coronos/w/angel/city/docks/dock6","southeast",
        "/d/coronos/w/russkie/rooms/14", "southwest",
      }));
}
