#include <mudlib.h>

#define PATH 	"d/coronos/w/angel/city/univ"
#define MONST	"d/coronos/w/angel/city/monst"

inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
	"file", PATH+"/office1",
	"direction", "northwest door",
	"long", "A strong sturdy door with a golden plaque which reads:\n"+
		"\tThe Chancellor's Office.\n",
  }));

  if(arg) return;

  set_short("the University of Power");
  set_long(
"The administrations office is littered with many papers, scattered across \n"+
"a fine large desk. Several ink wells stand on a nearby shelf, heavy with  \n"+
"the weight of many tomes and scrolls and books on enrolments for the university.\n"+
"On the wall behind the desk is a painting of the chancellor. \n");

  set_weather(2, 1, 0);

  set_items(({
"painting",
"It is a beautiful painting of chancellor Damon Portheos",
"desk",
"It is littered with new enrolments for the universitys semester",

"paper#papers", "They appear to be enrolment forms",

"ink well#ink wells",
"Most are dried up from constant use",

"scroll#scrolls",
"The scrolls on the desk are finished enrolment forms that the administration \n"+
"office plan to send off to the chancellor in the morning.\n",

"tomes#books",
"The tomes and books bear titles such as; Necromancy: Faculty Handbook,\n"+
"Cantrips 101, Policies of the Council of the Nine.\n",

"shelf",
"Quite a large number of books seem to burden the shelf to breaking point",
  }));

  set_listen("You can hear someone behind the door in the office nearby.\n");
  set_smell("The air is rich with the smell of old leathery books.\n");

  set_exits(({
    PATH+"/foyer",    "south",
    PATH+"/library1", "east",
  }));
}


