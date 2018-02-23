#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
  if(!present("bench")){
  move_object(clone_object(
  "/d/coronos/w/darkness/items/bench1"),
  this_object());
  }  

  set_short("A gazebo");
  set_long(
    "This is a small gazebo made from black, wrought iron.  Many intricate\n"+
    "designs have been forged into its frame.  The roof is made up of wood\n"+
    "beams that have darkened over time.  A long continuous bench runs around\n"+
    "the inside of the gazebo to sit on.  Two archways provide exit to the\n"+
    "fountain to the east and Wall Street to the south.");

  set_day_desc(
    "  A single oil lamp\n"+
    "hangs from the center of the ceiling, swaying in the wind.\n");
  set_night_desc(
    "  A single oil lamp\n"+
    "hangs from the center of the ceiling, illuminating the gazebo.\n");
  set_items(({
    "gazebo",
    "The gazebo is made from black iron.  The roof and the bench are\n"+
    "made from blackened wood.  It is very cozy looking.\n",
    "wood#beams",
    "The wood looks to be oak, darkened over time.\n",
    "iron#wrought iron#black iron#designs#frame",
    "The designs look well crafted from black wrought iron.\n"+
    "The iron is well forged and sturdy.\n",
    "archway#archways",
    "These archways have a border design in the shape of vines.  They\n"+
    "allow access to the east and south.\n", 
    "vines",
    "The vines grow on the outside of the gazebo.\n",
    }));  
  set_day_items(({
    "lamp#oil lamp",   
    "This is a fairly large oil lamp, made from the same iron as the\n"+
    "gazebo.  It hangs from a short chain attached to the roof.\n",
    }));  
  set_night_items(({
    "lamp#oil lamp",
    "The lit lamp is attached to the roof by a short chain.  It casts\n"+
    "dancing shadows about the gazebo as it sways in the wind.\n",
    }));
  set_smell(
     "The deep smell of aged wood mingles in the air.\n");
  set_listen(
      "You hear the water trickling from a fountain.\n");
  set_weather(2, 3, 0);
  set_exits(({
      "/d/coronos/w/darkness/mainst3", "south",
      "/d/coronos/w/darkness/fountn", "east",
      }));
}
