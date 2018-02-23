#include <mudlib.h>
#define MONST		"d/coronos/w/angel/city/monst"
#define CITY	"d/coronos/w/angel/city/chambers"

inherit ROOM;

object ob1, ob2;

void reset(status arg) {

  if(!ob2) {
    ob2 = clone_object(MONST+"/bguard");
    move_object(ob2, this_object());
  }
  if(!ob1) {
    ob1 = clone_object(MONST+"/alastaire");
    move_object(ob1, this_object());
  }

  if(present(ob1) && present(ob2))
    ob1 -> add_followers(ob2);
  /* this makes the black guard follow alastaire */

  reset_doors(arg);


  load_door(({
        "file", "d/coronos/w/darkness/b/hall/hall7",
	"direction",	"chamber door",
        "description", "The heavy door is made of sturdy oak.  Iron bracers also\n"+
                        "reinforce the door\n",
  }));
	

  set_short("the Ille Coronos city chambers");

  set_long(
"There is a noticeable ambience of tranquillity as you step into   \n"+
"this grand circular chamber. The ceiling domes high above you,    \n"+
"with twelve windows of fine stained glass filtering the light     \n"+
"from the outside in an array of fine reds and blues, culminating  \n"+
"in bright whites in the center of the room. A fine obsidian table,\n"+
"also circular and dwarvish in design, contrasts the light from    \n"+
"above. At regular intervals wooden chairs stand, each appearing   \n"+
"to be of the same elvish style, yet somehow different. Hanging    \n"+
"behind each chair, on the walls, are the coats of arms of each    \n"+
"of the founding members of Ille Coronos; the members of The Circle.\n");

  set_items(({
	"chamber",
	"You stand in the chamber where the members of The Circle meet \n"+
	"to discuss the business of their city. The whole chamber is   \n"+
"lit by white light streaming in from above.",

	"ceiling#domed ceiling#above",
	"The high vaulted ceiling stands some thirty feet above you,   \n"+
	"illuminated from the light shining through twelve stained     \n"+
	"glass windows. The sight leaves your awe struck.              \n",

	"windows#window",
	"The windows are crafted from stained glass, most likely by    \n"+
	"the local human artisans. Each depicts different scenes from  \n"+
	"the history of the founding of Ille Coronos",

	"stained glass#glass#scene#scenes",
	"There are twelve scenes which stand above each chair below.   \n"+
	"You recognise some of them from the stories you have heard    \n"+
	"about the founding of Ille Coronos from the locals.",

	"table",
	"The table is made from a single block of obsidian, crafted \n"+
	"expertly by the dwarven stone masons in the mountains to   \n"+
	"the south-east of the city. It is rumoured that they are   \n"+
	"the cities greatest allies in the effort against the drow. \n"+
	"Around the table stand twelve fine wooden chairs.",

	"chair#chairs",
	"Each chair appears elfin in design, but unique due to the carved \n"+
	"designs in the backs and arms. The chairs have high backs and    \n"+
	"forest green cushions which make them appear not only regal, but \n"+
	"comfortable as well.",

	"design#carvings#backs",
	"Each design bears the glyphs of the native wood elvish clan \n"+
"indicating various of natures elements, each representing an\n"+
"office on the Circle.",

"cushions",
"They are hand stitched and made from velvet in an ancient \n"+
"elvish design. These, and the chairs they adorn are gifts \n"+
"from the elven clans in the forests nearby the city.",

"coats of arms",
"There are twelve coats of arms, one behind each chair, denoting \n"+
"the founding members of the city of Ille Coronos. They are; a   \n"+
"gold phoenix on a scarlet background; a white star on a blue    \n"+
"field; a pennant halved, with a black eagle on the left and the \n"+
"right in red; an elvish banner with gold stars on a blue        \n"+
"background; a gold rose; a griffon holding a bow in its left    \n"+
"claw, and a score of arrows in its right; a silver sun on a blue\n"+
"field; a war hammer crossed over a clenched and armoured fist;  \n"+
"an ancient metallic dragon over the polar star; george+pothios",
  }));

  set_listen("There is a peace, indescribable in the air...\n");
  set_smell("The leather and wood from the chairs hangs in the air.\n");


  set_weather(2, 2, 0);
}

	
