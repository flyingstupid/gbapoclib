#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The deep forest rises all around. Tall oak and pine trees \n"+
      "struggle with undergrowth for the nourishment of the soil. A \n"+
      "solitary lilac bush has managed a weak position west of the \n"+
      "path. The growth in the forest has become very thick, making\n"+
      "it barely discernable that the path once lead to the east, \n"+
      "and can only be seen slightly better to the north.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for15", "north",
      FOREST_ROOMS+"for10", "east"
    }));
    set_items(({
      "lilac#lilac bush",
        "A blossoming lilac grows along the edge of the path. Its pale blue flowers\n"+
        "add a beautiful contrast to the earth tones of the forest.\n",
      "oak",
        "Many oak trees fill the forest, droppng their acorns on the forest floor.\n",
      "pine#pines#pine trees",
        "Stately firs, they leave their needles on the ground creating a soft\n"+
        "blanket.\n",
      "undergrowth#scrub#shrubbery",
        "Ground level plants spread out across the forest floor.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "path",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
    }));
}
