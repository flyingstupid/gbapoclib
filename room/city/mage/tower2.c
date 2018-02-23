#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
     "file", "room/city/mage/study1", 
     "direction", "east door",
     "long",
          "A dark door bearing spidery runes on a silvery plaque:\n"+
          "\tMordenkainen's Study. Keep Out\n",
     "key id", "silver key",
     "lock id", "silver lock",
     "lock description", "A shiny silver lock that glows softly\n",
     "closed", "locked",
     "trap on",
     "trap description", 
          "The trap appears to be some kind of fire trap spell.\n",
     "trap damage", (20 + random(50)),
     "trap message", "Fire Trap spell engulfs you from the door!\n",
     "trap room message", "@@query_name:$this_player()$@@ is engulfed "+
          "by a Fire Trap on the door.\n",
  }));

  if(arg) return;
  set_short("the tower of high magic");
  set_long(
     "A long spiral staircase of black iron extends downward  \n"+
     "into the darkness below. A single torch burns brightly\n"+
     "on the side of the east door, sending shadows dancing   \n"+
     "over the walls in a ghostly display of macarbe theatrics.\n");
  set_items(({
     "stairs#staircase",
          "A stairwell of cold black iron, descending downward",
     "torch",
          "A pair of torches burning brightly",
     "shadow#shadows",
          "The seem to have a life of their own...",
     "walls#wall",
          "The walls are of a cold grey stone, possibly made by magical means",
     "stone",
          "No dwarf chiselled this stone",
  }));
  set_listen("You can hear the torch flames flutter.\n");
  set_smell("You can smell the burning of pitch on the torches.\n");
  set_exits(({
     "room/city/mage/tower1", "up",
     "room/city/mage/tower3", "down",
  }));
  set_weather(2,1,0);    
}

void heart_beat() {
  string *messages;
  messages = ({
     "The torch flickers\n",
     "The torch splutters.\n",
     "The torch casts dancing shadows across the walls.\n",
     "The torch flutters.\n",
     "The torch light dances around the room.\n",
  });
  if(!random(10))
    tell_room(this_object(), messages[random(sizeof(messages))]);
}
