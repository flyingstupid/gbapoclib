/* Hall5 -- Bureaucracy*/
/* Darkness */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  reset_doors(arg);
  load_door(({
    "destination",      "d/coronos/w/russkie/rooms/22",
    "direction",        "east door",
    "long",             "The heavy door is made of sturdy oak.  Iron bracers also\n"+
                        "reinforce the door\n",
    "door id",          "east door",
    "key id",           "city key",
  }));
    
  load_door(({
    "destination",      "d/coronos/w/darkness/b/room4",
    "direction",        "north door",
    "long",             "This is a large wooden door.  It is made of thick oak\n"+
                        "boards held together with wrought iron bands.\n",
    "door id",          "north door",
    "key id",           "mayor's key",
    "lock id",          "iron lock",
    "lock description", "An iron lock\n",
    "lock difficulty",  16,
    "closed", 
  }));


  if (arg) return;
 
  set_short("a hallway in the Bureaucracy");
  set_long(
    "The high ceilings of the Bureaucracy loom overhead, supported by thick\n"+
    "wooden beams.  Silver chandeliers hang down, reflecting their light off\n"+
    "the marble floor tiles.  The smooth granite walls of the hallway are\n"+
    "decorated with various pieces of framed artwork.  The halls to the west\n"+
    "and southwest are lined with many doors.\n");
  set_items(({
    "wall#walls",
      "The walls are made of solid granite.  They are decorated with artwork.\n",
    "granite",
      "There is granite masonry all around you here.\n",
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
  set_smell(
    "The smell of the chandelier's oil is the only scent here.\n");
  set_listen(
    "Footsteps echoe through the halls of the Bureaucracy.\n");
  set_weather(2, 1, 0);

  set_exits(({ 
      "d/coronos/w/darkness/b/hall/hall4", "west",
      "d/coronos/w/darkness/b/hall/hall6", "southwest",
      }));

}

