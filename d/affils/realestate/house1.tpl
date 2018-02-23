void reset(status arg) {
  if(arg) return;

#ifndef NAME
#define NAME "someone"
#endif /* NAME */

  set_short(NAME+"'s dwelling");

  set_long(
    "With a wooden table and simple chairs, this dwelling must belong to \n"+
    "someone of spartan tastes. A cot stands by the wall, with a large  \n"+
    "shelf opposite it, beside the wood burning stove. \n");

  set_weather(1, 1, 0);
  set_items(({
	"stove",
	"The stove is small, and made from iron, with a little chimeny \n"+
	"stack poking through the ceiling",

	"chimeny stack#chimeny#stack",
	"It looks quite tough, but has a little soot on it",

	"soot", "It looks quite black",

	"ceiling",
	"It looks quite sound, and will definitely keep the rain in",

	"table",
	"The table is made from a sturdy hard wood, and looks very functional",

	"chair#chairs",
	"The chairs are of the same hard wood of the table and look very "+
	"comfortable",

	"cot#bed",
	"A fold up bed stands beside the wall, with a small pile of \n"+
	"blankets at its end. It beckons you to come to sleep...\n",

	"shelf#large shelf",
	"The shelf contains some simple nicnaks, plates and bowels, and \n"+
	"some pictures of friends and family",

	"nicnaks#items",
	"They are some items collected by an adventurer, over his carreer",

	"plates",
	"The plates on the shelf are delicately painted by hand",

	"bowels",
	"The bowels seem to have been painted with the same pains taking \n"+
	"designs as the plates on the shelf below",

	"pictures",
	"There is a picture of "+NAME+" on one of the shelves",
  }));
}

string query_house_type() { return "House"; }
