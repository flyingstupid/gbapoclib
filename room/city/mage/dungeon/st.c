#define PATH    "room/city/mage/dungeon/"
#define OBJ     "room/city/mage/dungeon/obj/"

inherit PATH+"Dtemp";

#define NAME "josh"


reset (arg) {
    if (arg) return;

    set_short( "Stair case landing");
    set_long(
      "You are standing at the top of a spiral staircase. There are several \n"+

      "glowing orbs on the walls providing a dim light. The room is filled with \n"+
      "the low buz of magical wards.\n"
    );
    set_weather(3,1,0);
    set_items(({
        "globe#globes#light#lights",
        "They appear to be perfectly formed crystal spheres, that emit a steady"+
"light.\n",
        "stone#stones#brick#bricks",
        "They seem to be large granite bricks. Some of them are carved with arca"+
"ne glyphs\nof power.\n",
        "glyphs#glyph",
        "The writing is so ancient its true meaning is lost on you, but the power "+ 
	"you\nfeel from them leaves you no doubt they are not for decoration.\n",
        "walls#wall",
        "The walls are made up of large strong bricks, many of which have glyphs"+
 "of \npower carved into them.\n",
      }));
    set_smell("This place smells dank and musky.\n");
    set_listen("Your ears feel the dull roar of preasure.\n");
    set_exits(({
	"room/city/mage/bfloor2", "south",
	PATH+"chamber",	"down",
      }));
}
