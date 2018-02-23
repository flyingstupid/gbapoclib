#include <mudlib.h>
inherit ROOM;

object g1, g2, g3, ob; 

void reset (status arg){

  reset_doors(arg);
  load_door(({
    "destination",      "d/coronos/w/angel/city/chambers/chambers",
    "direction",        "chamber door",
    "long",             "The heavy door is made of sturdy oak.  Iron bracers also\n"+
                        "reinforce the door\n",
    "door id",          "north door",
    "key id",           "city key",
  }));
    
  load_door(({
    "destination",      "d/coronos/w/russkie/rooms/27",
    "direction",        "oak door",
    "long",             "This is a wooden door made of oak.\n",
    "door id",          "south door",
    "key id",           "city key",
  }));

  g1 = clone_object("d/coronos/w/darkness/b/guard1.c");
  g2 = clone_object("d/coronos/w/darkness/b/guard2.c");
  g3 = clone_object("d/coronos/w/darkness/b/guard3.c");

/*  if(!find_living(g1)) {
    move_object(g1, this_object());  
  }

  if(!find_living(g2)) {
    move_object(g2, this_object());  
  }

  if(!find_living(g3)) {
    move_object(g3, this_object());  
  }
*/

  if(!present("Mayor Handlefoot")){
    move_object(clone_object("/d/coronos/w/darkness/b/mayor"),
    this_object());
  }



  set_short("a hallway in the Bureaucracy");
  set_long(
    "The high ceilings of the Bureaucracy loom overhead, supported by thick\n"+
    "wooden beams.  Silver chandeliers hang down, reflecting their light off\n"+
    "the marble floor tiles.  The smooth granite walls of the hallway are\n"+
    "decorated with various pieces of framed artwork.  A large door to the\n"+
    "north is adorned with the crest of the city.  Next to the door is a\n"+
    "bulletin board and a small book case.\n");
  set_items(({
    "case#book case",
      "The simple wood book case is empty save for a small stack of papers.\n"+
      "They seem to be lists of some sort.\n",
    "papers#paper#list#lists",
       "These are lists of the current parties of Heaven 7.\n",
    "wall#walls",
      "The walls are made of solid granite.  They are decorated with artwork.\n",
    "granite",
      "There is granite masonry all around you here.\n",
    "crest",
      "The crest hs been ornately carved and painted on\n"+
      "a variety of metals and wood.\n",
    "ceiling#ceilings#up",
      "The granite ceilings are very high above the floor of the hallway.\n"+
      "Silver chandeliers hang down from metal chains.\n",
    "chain#chains",
      "These chains hold up the chandeliers.\n",
    "chandeliers#chandeliers",
      "The silver chandeliers are very ornate and well crafted.\n",
    "beams#beam#wood beam",
      "The thick wooden beams that support the ceiling are recessed into the\n"+
      "granite walls of the hallway.\n",
    "floor#down#",
      "The floor is made of marble tiles.\n",
    "light",
      "The light emanates from the chandeliers up above.\n",
    "tiles#tile#floor tiles",
      "The marble tiles are mostly dark blue, black and white, but streaks of\n"+
      "red, violet and green can be seen here and there.  The tiles have been\n"+
      "pollished very well, casting reflections like many little mirrors.\n",
    "hall#halls",
      "The halls are large and wide.  Chandeliers and marble tiles give the\n"+
      "halls a feeling of warmth and elegance.\n",
    "art#artwork#framed artwork",
      "Many different kinds of art can be seen.  Oil paintings and portraits\n"+
      "seem to be in majority, but sketches on paper, ink drawings, and all\n"+
      "other sorts of art can be seen.\n",
    "frame#frames",
      "There are as many frames as there are pieces of art, for the frame\n"+
      "is also a piece's accompanyment.\n",
    }));

  set_extra_objects(({
    "list", "objects/party_list", 
    }));

  set_smell(
    "The smell of the chandelier's oil is the only scent here.\n");
  set_listen(
    "Footsteps echoe through the halls of the Bureaucracy.\n");
  set_weather(2, 1, 0);

  set_exits(({ 
      "d/coronos/w/darkness/b/hall/hall8", "northwest",
      "d/coronos/w/darkness/b/hall/hall6", "northeast",
      }));

}
