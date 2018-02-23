#define PATH    "room/city/mage/dungeon/"
#define OBJ     "room/city/mage/dungeon/obj/"

inherit PATH+"Dtemp";

#define NAME "josh"


reset (arg) {
    if (arg) return;

    set_short( "southeast wing");
    set_long(
	"You find yourself standing in the southeast wing of  mage tower"+
	" dungeon.\n" + "The hall is light by more glowing orbs, filling the"+
	" hall with \n"+"bright light. The walls have a brown clolor here.\n"

     
    );
        set_items(({
        "globe#globes#light#lights",
   "They appear to be perfectly formed crystal spheres, that emit a steady"+
"light.\n",
        "stone#stones#brick#bricks",
   "They seem to be  large brown bricks. Some of them are carved with arca"+
	"ne glyphs\n"+" of power.\n",
        "glyphs#glyph",
     "The writing is so ancient its true meaning is lost on you, but the power "+ 
     "you\nfeel from them leaves you no doubt they are not for decoration.\n"+
"You do reconize the earth symbol repeared in several places.\n",
        "walls#wall",
        "The walls are made up of  strong brown bricks, many of which have glyphs"+
 "of \n"+"  power carved into them.\n",

	      }));
    set_smell("You nose is filled with the smell of earth.\n");
set_weather(3,1,0);
    set_listen("You hear a faint crunching sound. \n");
    set_exits(({
	PATH+"chamber", "northwest",
        	 }));
}
