inherit "inherit/room2";

reset(arg)
{
	if(arg) return;
	load_door(({
"direction","central gate",
"file", "d/coronos/w/mycroft/baker4.c",
	"key id", "city key",
	"long", "A large iron gate",
	"lock description", "A huge iron lock",
	}));
	
set_short("central gate");
set_alias("gate");
        set_long("\
You are standing at the central gate.  Outside lies the rest of Ille\n"+
"Coronos.\n");
	set_weather(2,4,0);
        set_exits(({
"d/coronos/w/mycroft/baker3.c","west",
"d/coronos/w/mycroft/baker4.c","east",
	  }));
}

to_phaze(str){
    if (str != "north gate") return 0;
    write(
      "You are suddenly engulfed in a shimmering field.  It writhes about you,\n" + 
      "distorting your perception of the world, presenting you with a\n" +
      "nightmarish vision.  You squinch your eyes shut, trying not to lose your\n" +
      "lunch.\n");
    call_out("phaze_two", 3);
}

void phaze_two(){
    write(
      "You can see landscapes flowing beneath you.  Whole continents pass before your\n" +
      "eyes.  Distance passes by the second.  Suddenly, you come to a crash stop.\n" +
      "And you're lost.\n");
    say (
      this_player()->query_name() + " disappears in an explosion of light and sound.\n");
    move_object(this_player(), "/d/mirror/phaze/oracle/room3");
}
