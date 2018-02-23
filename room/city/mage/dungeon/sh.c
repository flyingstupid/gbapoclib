#define PATH    "room/city/mage/dungeon/"
#define OBJ     "room/city/mage/dungeon/obj/"

inherit PATH+"Dtemp";

#define NAME "josh"


reset (arg) {
    if (arg) return;

    set_short( "south wing");
    set_long(
      "You find yourself standing in the south wing of  mage tower"+
      " dungeon.\n" + "Though the hall is lit by more glowing orbs, you"+
      " have a hard time\n"+ "seeing the black walls here.\n"
    );
    set_items(({
	"globe#globes#light#lights",
	"They appear to be perfectly formed crystal spheres, that emit a steady"+
	"light.\n",
	"stone#stones#brick#bricks",
	"They seem to be large blue bricks. Some of them are carved with arca"+
	"ne glyphs\n"+" of power.\n",
	"glyphs#glyph",
	"The writing is so ancient its true meaning is lost on you, but the power "+ 
	"you\nfeel from them leaves you no doubt they are not for deco, many of which have glyphs"+
	"of \n"+"power carved into them.\n"

      }));
    set_weather(3,1,0);
    set_smell("Sniffing your lungs fill with fresh air.\n");
    set_listen("You faintly hear the sound of  thunder. \n");
    set_exits(({
	PATH+"chamber", "north",
      }));
}
