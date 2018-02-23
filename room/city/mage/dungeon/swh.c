#define PATH    "room/city/mage/dungeon/"
#define OBJ     "room/city/mage/dungeon/obj/"

inherit PATH+"Dtemp";

#define NAME "josh"


reset (arg) {
    if (arg) return;

    set_short( "southwest wing");
    set_long(
      "You find yourself standing in the southwest wing of mage tower"+
      " dungeon.\n" + "The hall is light by more glowing orbs, filling the"+
      " hall with \n"+"bright light. The walls have a deep blue clolor here.\n"     
    );
    set_items(({
	"globe#globes#light#lights",
	"They appear to be perfectly formed crystal spheres, that emit a steady"+
	"light.\n",
	"stone#stones#brick#bricks",
	"They seem to be  large blue bricks. Some of them are carved with arca"+
	"ne glyphs\n"+" of power.\n",
	"glyphs#glyph",
	"The writing is so ancient its true meaning is lost on you, but the power "+ 
	"you\nfeel from them leaves you no doubt they are not for decoration.\n"+
	"You do reconize the water symbol repeared in several places.\n",
	"walls#wall",
	"The walls are made up of  blue bricks, many of which have glyphs"+
	"of \n"+"  power carved into them.\n",


      }));
    set_weather(3,1,0);
    set_smell("Sniffing your lungs fill with wet air.\n");
    set_listen("You faintly hear the sound of waves breaking.  \n");
    set_exits(({
	PATH+"chamber", "northeast",
      }));
}
