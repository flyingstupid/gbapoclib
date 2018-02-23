#define PATH    "room/city/mage/dungeon/"
#define OBJ     "room/city/mage/dungeon/obj/"

inherit PATH+"Dtemp";

#define NAME "josh"


reset (arg) {
  int i;
  object ob;

  if(!present("mephit")) {
    for(i=0; i<6; i++) {
      ob = clone_object(OBJ+"mephit");
      move_object(ob, this_object());
    }
  }

reset_doors(arg);
  load_door(({
	"file", PATH+"fcell1",
     "direction", "northwest door",
     "long",
          "This is a strong steel door. There is a huge circle"+
" of protection from fire carved in it.\n",
          
     "key id", "silver key",
     "lock id", "silver lock",
     "lock description", "A shiny silver lock that glows softly\n",
     "open", "unlocked",
     "trap off",
}));
    if (arg) return;

    set_short( "Northeast wing");
    set_long(
"You find yourself standing in the northeast wing of the dungeon. \n"+
"The hall is light by more glowing orbs, filling this room with   \n"+
"a bright light. The walls are red, as is a large circle painted  \n"+
"on the floor.\n");
        set_items(({
	"circle#floor",
	"The circle is one of conjuring, used to summon fiends from \n"+
	"the Nine Hells. I wouldn't disturb it if I were you!",
             "globe#globes#light#lights",
        "They appear to be perfectly formed crystal spheres, that emit a steady"+
"light.\n",
        "stone#stones#brick#bricks",
        "They seem to be  large red bricks. Some of them are carved with arca"+
"ne glyphs\n"+" of power.\n",
        "glyphs#glyph",
        "The writing is so ancient its true meaning is lost on you, but the power "+ 
         "you\nfeel from them leaves you no doubt they are not for decoration.\n"+
	"You do reconize the fire symbol repeared a lot.\n",
        "walls#wall",
        "The walls are made up of  strong red bricks, many of which have glyphs"+
 "of \n"+" power carved into them.\n",

	      }));
set_weather(3,1,0);
    set_smell("You nose is filled with the smell of smoke .\n");
    set_listen("You hear a faint crackling sound. \n");
    set_exits(({
	PATH+"chamber", "southwest",
        	 }));
}
