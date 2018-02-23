/* Hall3 -- Bureaucracy */
/* Darkness */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  object ob;

  if(!present("board")) {
    ob = clone_object(BULLETIN);
    ob -> set_save_file("ob_saves/boards/quests");
    ob -> set_creator_only(20);
    move_object(ob, this_object());
 }


  reset_doors(arg);
/*  load_door(({
    "file", "d/coronos/w/darkness/b/secret",  
    "secret door", 18,
    "long", "A small opening in the wall that leads to a narrow passageway.\n",
    "secret door finders", ({}),
    "direction", "secret door",
  }));
*/ 
/* The sercret door will be implemented later. */
  if (arg) return;

  load_door(({
	"direction", "north door",
	"long", "A large door made from red timber.\n",
	"file", "d/coronos/w/angel/city/chambers/quest",
  }));

 
  set_short("a hallway in the Bureaucracy");
  set_long(
    "The high ceilings of the Bureaucracy loom overhead, supported by thick\n"+
    "wooden beams.  Silver chandeliers hang down, reflecting their light off\n"+
    "the marble floor tiles.  The smooth granite walls of the hallway are\n"+
    "decorated with various pieces of framed artwork.  Two large tapestries\n"+
    "hang down from the ceiling to the floor along the north and south walls.\n");  
  set_items(({
    "tapestry#tapestries#north tapestry",
      "The heavy tapestries bear all the crests of the Circle members.\n",
    "south tapestry",
      "The tapestry seems excessively wrinkled, like it has been pushed\n"+
      "asside to gain access to the wall behind it many times.\n",
    "wall#north wall",
      "The wall is made of granite.\n",
    "south wall",
      "The south wall seems a bit odd.  A more thorough search of the\n"+
      "room may turn something up.\n",
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
    "It smells a little damp here.  The faint smell of mildew\n"+
    "lingers lightly from the southern tapestry.\n");
  set_listen(
    "Footsteps echoe through the halls of the Bureaucracy.\n");
  set_weather(2, 1, 0);

  set_exits(({ 
      "d/coronos/w/darkness/b/hall/hall4", "east",
      "d/coronos/w/darkness/b/hall/hall2",  "west",
      }));

}
