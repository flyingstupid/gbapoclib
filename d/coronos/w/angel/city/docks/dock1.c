#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object ob;

  if(!present("telescope")) {
    ob = clone_object("objects/telescope");
    ob -> set_xy(10, 150);
    move_object(ob, this_object());
  }
    reset_doors(arg);
    load_door(({
        "file", "d/coronos/w/angel/city/sewer/tunnel1",
	"direction", "trap door",
	"long", "Its a man hole which leads down into one pylon and down \n"+
		"underneath the city of Ille Coronos.\n",
	"secret door", 1,
	"secret door finders", ({ }),
      }));

    if(arg) return;
    set_short("the Ille Coronos docks");
    set_long(
      "        This is the busiest part of the docks. Numerous crates\n\
are stacked in apparently random places and porters are constantly\n\
moving them from one place to another. Sea gulls fly from ship to \n\
ship, playing among the ropes and periodically diving for fish in\n\
the ocean. Cabin boys run to and fro on errands from their captains,\n\
their bare feet pattering on the docks.\n"
    );
    set_weather(1, 4, 6);
    set_smell("The briny smell of the ocean fills your nostrils.\n");
    set_listen("The soothing slosh of the water against the pylons is the only calming sound\nin the noisy clamour of the docks. Cries of gulls, shouts of porters and the\nharbormaster overshadow the pleasant lull of the ocean.\n");
    set_exits(({
	"d/affils/ships/open/types/bounty/stern", "bounty",
	"/d/coronos/w/chi/city/streets/dock4","northeast",
	"d/coronos/w/chi/city/streets/dock2", "southwest",
      }));
    set_items(({
	"docks#dock",
	"The docks are simply long stone piers that extend out from the beach.\n\
They are supported from underneath by huge stone pylons, covered with\n\
barnacles.\n",
	"barnacle#barnacles#pylon#pylons",
	"Barnacles cover the huge stone pylons that support the dock here.\n",
	"crate#crates",
	"Wooden crates of all shapes and sizes are stacked in random places\n\
on the dock. Either they haven't been picked up or are waiting to\n\
leave the dock.\n",
	"ocean",
	"The ocean extends away from the docks and is a deep green color.\n\
It is surprisingly clear considering the activity in Ille Coronos.\n",
      }));
}

