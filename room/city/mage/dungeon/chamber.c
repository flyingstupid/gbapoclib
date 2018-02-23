#define PATH    "room/city/mage/dungeon/"
#define OBJ     "room/city/mage/dungeon/obj/"

inherit PATH+"Dtemp";

#define NAME "josh"


reset (arg) {
    if(!present("jallon")) {

	move_object(clone_object(OBJ+"journeyman"), this_object());

    }
    if (arg) return;

    set_short( "Stair case landing");
    set_long(
      "This room is brightly lit by dozens of glowing orbs. With this light "+
      "you can \n"+ "see that this room is shaped like a pentagon. Each wall "+
      "is etched with \n"+"protective glyphs that your eyes have a hard time "+
      "focusing on. Five carved\n"+ "columns support the ceiling.\n"
+"\n \n"

    );
    set_items(({
	"globe#globes#light#lights",
	"They appear to be perfectly formed crystal spheres, that emit a steady"+
	" light.\n",
	"stone#stones#brick#bricks",
	"They seem to be large granite bricks. Some of them are carved with arca"+
	"ne glyphs\nof power.\n",
	"glyphs#glyph",
	"The writing is so ancient its true meaning is lost on you, but the power "+ 
	"you\nfeel from them leaves you no doubt they are not for decoration.\n",
	"walls#wall",
	"The walls are made up of large strong bricks, many of which have glyphs"+
	" of \npower carved into them.\n",
	"columns#column","Which column? There are five. i.e. look at "+
	"ne collum \n",

	"ceiling","High above you see a arching domed roof. \n"

      }));
    set_smell("This place smells dank and musky.\n");
    set_listen("Your ears feel the dull roar of pressure. \n");
    set_weather(3,1,0);
    set_exits(({
	PATH+"stcase", 		"up",
	PATH+"neh",		"northeast",
	PATH+"sh",		"south",
	PATH+"shw",		"southwest",
	PATH+"nwh",		"northwest",
      }));
}
