/* room1.c in the Bureaucracy */
/* Darkness */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  reset_doors(arg);
  load_door(({
    "destination",      "d/coronos/w/darkness/b/hall/hall1",
    "direction",        "wooden door",
    "long",             "This is a large wooden door.  It is made of thick oak\n"+
                        "boards held together with wrought iron bands.\n",
    "door id",          "south door",
    "key id",           "mayor's key",
    "lock id",          "iron lock",
    "lock description", "An iron lock\n",
    "lock difficulty",  16,
    "closed", 
  }));

  if(!present("candon")){
    move_object(clone_object("/d/coronos/w/darkness/e/candon"),
    this_object());
  }

  if(!present("sliph")){
    move_object(clone_object("/d/coronos/w/darkness/e/sliph"),
    this_object());
  }

  if(!present("f'rane")){
    move_object(clone_object("/d/coronos/w/darkness/e/frane"),
    this_object());
  }

  if (arg) return;
 
  set_short("a guest room in the Bureaucracy");
  set_long(
    "This rectangular room is quite large, and able to accomodate several\n"+
    "occupants.  A few beds run along opposite sides of the room, each bed\n"+
    "seperated by a small armoire.  Thick rugs cover the stone floor and\n"+
    "velvet tapestries hang down from the vaulted ceiling.  A few chairs\n"+
    "and a small table are located in the far corner of the room.\n");
  set_items(({
    "The far corner of the room is furnished with several chairs and a table.\n",
    "rug#rugs",
      "The thick rugs are made from many different animal furs.\n",
    "tapestries#tapestry",
      "The velvet tapestries hand down from the ceiling, covering the\n"+
      "stone walls.  They all have different designs and colors on them\n",
    "chair#chairs",
      "The simple chairs are crafted from oak.\n",
    "table",
      "The simple table is crafted from oak.\n",
    "bed#beds",
      "The wooden beds are rather small with fluffy feather mattresses.\n"+
    "armoir#armoirs",
      "The armouirs are elegantly crafted from cedar.\n",
    "wall#walls",
      "The walls are made of solid granite.  They are decorated with velvet\n"+
      "tapestries that hand from the ceiling.\n",
    "granite",
      "There is granite masonry all around you here.\n",
    "ceiling#ceilings#up",
      "The granite ceilings are very high above the floor.\n"+
      "Two silver chandeliers hang down from metal chains.\n",
    "chain#chains",
      "These chains hold up the chandeliers.\n",
    "chandeliers#chandeliers",
      "The silver chandeliers are very ornate and well crafted.\n",
    "beams#beam#wood beam",
      "The thick wooden beams that support the ceiling are recessed into the\n"+
      "granite walls of the hallway.\n",
    "floor#down#",
      "The floor is made of stone and covered with many thick rugs.\n",
    "light",
      "The light emanates from the chandeliers up above.\n",
    }));
  set_smell(
    "The smell of the chandelier's oil is the only scent here.\n");
  set_listen(
    "Footsteps echoe through the halls of the Bureaucracy.\n");
  set_weather(2, 1, 0);
}
