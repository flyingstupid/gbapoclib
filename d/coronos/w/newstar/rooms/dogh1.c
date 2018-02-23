# include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if(arg) return;
 
  set_short("\A dog house\n");
  set_long(
    "This is a cramped, little dog house.  It's a mess with dog hair\n"+
    "everywhere.  A red pillow lies in the back and a well-gnawed\n"+
    "bone beside it on the dirty floor.");
  set_day_desc(
    "  Sunlight streams in from\n"+
    "the cracks in the roof.\n");
  set_night_desc(
    "  Moonbeams make little\n"+
    "shadows on the floor through the cracks in the roof.\n");
  set_items(({
    "bone#well-gnawed bone", 
      "This is a bone covered with larger teeth marks.\n",
    "hair#dog hair", 
      "Just some coarse, black dog hair.\n",
    "pillow#red pillow", 
      "This is a red, dirty pillow that the dog uses as its bed.\n",  
    "floor#dirty floor", 
      "A wooden floor of a dog house, covered in dog hair.\n",
    "crack#cracks", 
      "You can see the sky outside through the cracks in the roof.\n",
    "roof", 
      "A rather low type of ceiling that is full of cracks.\n",
    }));
  set_day_items(({
    "sunlight#light", 
      "Bright rays of warming light.\n",
    }));
  set_night_items(({
    "moonbeam#moonbeams", 
      "Pretty, silvery streams of pale light.\n",
    }));
  set_smell("It smells like a dog in here.\n");
  set_listen("You hear the winds whistling through the cracks.\n");
  set_weather(1, 2, 0);
  set_exits(({
    "players/newstar/workroom", "out",
    }));
}
