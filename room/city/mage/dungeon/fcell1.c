#define PATH    "room/city/mage/dungeon/"
#define OBJ     "room/city/mage/dungeon/obj/"

inherit PATH+"Dtemp";

#define NAME "josh"


reset (arg) {
    reset_doors(arg);
    load_door(({
	"file", PATH+"neh",
	"direction", "southeast door",
	"long",
	"This is a strong steel door. There is a huge circle"+
	" of protection from fire carved in it.\n",

	"key id", "silver key",
	"lock id", "silver lock",
	"lock description", "A shiny silver lock that glows softly\n",
	"open", "unlocked"
      }));

    if (arg) return;

    set_short( "fire cell");
    set_long(
      "A red glow emits from the wall here, casting strange shadows about"+
      " the cell.\n"+"Strong chains of gleaming steal are fastened to the walls,"+
      "floor, and ceiling.\n" 
      +"\n \n"
    );
    set_items(({

	"stone#stones#brick#bricks",
	"They seem to be made of red bricks. Some of them are carved with arca"+
	"ne glyphs\n"+" of power.\n",
	"glyphs#glyph",
	"The writing is so ancient its true meaning is lost on you, but the power "+ 
	"you\nfeel from them leaves you no doubt they are not for decoration.\n"+
	"You do reconize the fire symbol repeared in several places.\n",
	"walls#wall",
	"The walls are made up of  red bricks, many of which have glyphs"+
	"of \n"+"  power carved into them.\n",

      }));
    set_weather(3,1,0);    
    set_smell("Sniffing your lungs fill with smokey air.\n");
    set_listen("You faintly hear the sound of  fire crackling. \n");
    set_exits(({

      }));
}
