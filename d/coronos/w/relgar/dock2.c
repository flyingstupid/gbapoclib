#include <mudlib.h>
#include "/d/coronos/w/chi/city/path.h"
inherit ROOM;
object p;

void reset(status arg) {
    if(!present("porter")){
	p=clone_object(MONSTER);
	p->set_name("porter");
	p->set_short("A tired porter leaning against some crates.");
	p->set_alias("tired");
	p->set_long(
	  "        The dark skinned man before you is a porter for the docks.\n\
He is tanned and weather worn from working in the elements all his\n\
life and he is obviously strong from the pains of his labor. He is\n\
bare from the waist up and wears only simple breeches and a bandana\n\
on his head.\n");
	p->set_level(9);
	p->add_money(random(30));
	p->load_chat(10,({"Porter looks at you boredly.\n","Porter takes a deep breath of the salt air and smiles into the sky.\n"}));
	p->set_race("human");
	p->set_gender(1);
	move_object(p,this_object());
    }
    if(arg) return;
    set_short("the Ille Coronos docks");
    set_long(
      "        Slightly removed from the main bustle of the docks, smaller\n\
ships can dock with their cargo and not be hassled by the larger merchant\n\
boats. Several small crates are lined up along the edge of the dock.\n\
The occasional porter or cabin boy will pass through, focused on their\n\
task at hand.\n"
    );
    set_weather(1, 4, 6);
    set_smell("The briny smell of the ocean fills your nostrils.\n");
    set_listen("The pleasant sloshing of the ocean against the pylons of the docks instills\npeace in even the most harried seaman. Screams of gulls and the shouts of\nworkers on the docks is not as loud here.\n");
    set_exits(({
	"/d/coronos/w/angel/city/docks/dock1", "northeast",
	"/d/coronos/w/chi/city/streets/dock3","southwest",
      }));
    set_items(({
	"crates#crate",
	"Several small crates are lined up along the edge of the dock.\n",
	"dock#docks",
	"The stone docks are supported from underneath by huge stone pylons.\n",
	"pylons#pylon",
	"The huge stone pylons that support the dock disappear into the ocean\n\
and are covered with barnacles.\n",
	"barnacle#barnacles",
	"The barnacles cover the stone pylons from just above water line, as \n\
far down as you can see.\n"
      }));
}

