# include <mudlib.h>

inherit ROOM;

void reset (status arg){
    if(arg) return;

    set_short("a dirt path\n");
    set_long(
      "This is a dirt path that leads west to the gardens.  Many trees and\n"+
      "patches of wildflowers grow along the sides of the path.  Some tufts\n"+
      "of grass grow tall next to a large boulder. Many different splashes \n"+
      "of color draw your eyes to the west.");
    set_day_desc(
      "  An oil lamp hangs from\n"+
      "a lamp post next to the path.\n");
    set_night_desc(
      "  A lit oil lamp lights \n"+
      "the way along the path.\n");
    set_items(({
	"post#lamp post",
	"This is a simple lamp post, with an oil lamp hanging from it.\n",
	"leaf#leaves", "These are the leaves of the trees.\n",
	"path#dirt path", "This is a dirt path.\n",
	"tree#trees", "These are large trees that grow next to the path.\n",
	"wildflowers#flowers#flower#patches of wildflowers",
	"These wildflowers are very colorful and pretty.\n",      
	"gardens#garden",
	"The city gardens are to the west.",
  "tufts#tufts of grass#grass",
	"These are tall tufts of green grass.",
	"boulder#rock",
	"This large rock sits on the ground close to the path.",
	"cricket#crickets",
	"You can't seem to find the hiding crickets.",
      }));
    set_day_items(({
	"lamp#oil lamp",
	"This is a simple oil lamp that hangs from a post.  It is has a metal\n"+
	"frame and glass panels.  The lamp is unlit right now.\n",
      }));
    set_night_items(({
	"lamp#oil lamp",
	"This is a simple oil lamp that hangs from a post.  It has a metal\n"+
	"frame and glass panels.  The lamp shines brightly, illuminating the\n"+
	"area.\n",
      }));
    set_smell("You smell the scent of fragrant wildflowers.\n");
    set_listen("You crickets chirping in the grass.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/dpath1", "east",
        "/d/coronos/w/angel/city/gardens/garden9", "west",
      }));
}
