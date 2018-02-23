inherit "/players/josh/room/mage/dungeon/Dtemp.c";

#define NAME "josh"


reset (arg) {
    int i;
    reset_doors(arg);
    if(!present("rat")) {

	for(i=0; i<3; i++)  {
	    move_object(clone_object("/players/josh/room/mage/dungeon/obj/rat.c"),this_object());

	}
    } 


    load_door(({
	"file", "/players/josh/room/mage/dungeon/seh.c",
	"direction", "southwest door",
	"long",
	"This is a strong steel door. There is a huge circle"+
	" of protection from water carved in it.\n",

	"key id", "silver key",
	"lock id", "silver lock",
	"lock description", "A shiny silver lock that glows softly\n",
	"open", "unlocked"
      }));

    if (arg) return;

    set_short( "Earth cell");
    set_long(
      "This room is lite by more of those glowing orbs. The cell itself  "+
      "seems \n"+" to have been carved strait out of  solid rock."+
      " Strong chains of gleaming\n"+"steel are fastened to the walls,"+
      "floor, and ceiling.\n \n \n" 

    );
    set_items(({

	"stone#stones#rock",
	"The  walls have glyphs carved into them.\n",   
	"glyphs#glyph",
	"The writing is so ancient its true meaning is lost on you, but the power "+ 
	"you\nfeel from them leaves you no doubt they are not for decoration.\n"+
	"You do reconize the earth symbol repeared in several places.\n",
	"walls#wall",
	"The walls are made up of  solid stone, many of which have glyphs"+
	"of \n"+"  power carved into them.\n",

      }));
    set_weather(3,1,0);    
    set_smell("Sniffing your lungs fill with dusty air.\n");
    set_listen("You hear only the earthworms. \n");
    set_exits(({

      }));
}
