/* A beach where you can make sand things. This idea was originally from
 * a room I designed on Sands of Time; a beach where Shally and I made
 * sand castles. This is how I originally wanted to code that room, but
 * never got beyond the 'emotes' to the room.
 * 			Angel, Jan 94
 */
#include <mudlib.h>
#include <linewrap.h>
inherit ROOM;

string *sand_creations;

void reset(status arg) {

  sand_creations = ({});

  if(arg) {
    tell_room(this_object(), "The waves wash up on the beach and destroy "+
          "the sand creations.\n");
    return;
  }

  set_short("Skol island");
  set_long(
     "The sandy beach of skol island extends to the east and west of here.\n");
  set_weather(1, 4, 6);
  set_exits(({ 
     "room/island/beach4", "east",
     "room/island/beach2", "west",
  }));
  set_listen("You hear the soothing sounds of the waves against the beach.\n");
  set_smell("Sea salt is strong in the air here.\n");
  set_items(({
     "sand",  
          "Soft, yellow sand. It feels wonderful beneath your feet",
     "beach", 
          "A small beach which extends up and down the coast of the island",
     "waves#wave",
          "Strong waves crash on the beach",
     "castle#sand castle",
          "A tall castle made from sand, decorated with small shells.\n"+
          "Perhaps you could also make something from the sand here?",
     "shell#shells",
          "Colourful shells decorate the sand castle that stands here",
  }));

  set_search_array(({
     "sand#beach",
          "All you find is sand. Did you expect to find anything else?\n",
     "castle#sand castle",
          "You find nothing but more sand, and some shells.\n",
  }));
}

void long(status wiz) {
  string tmp;
  int i;
  ::long(wiz);

  if(!sizeof(sand_creations)) return;

  tmp = "There is a ";
  for(i=0; i<sizeof(sand_creations); i++) {
    tmp += sand_creations[i];
    if((i+1) < sizeof(sand_creations) && sizeof(sand_creations) != 1)
      tmp += ", and a ";
  }
  tmp += " made from sand here.\n";
  writelw(tmp);
}

void init() {
  ::init();
  add_action("make", "make");
  add_action("make", "build");
}

/* make a sand castle, and other things ..a bit of fun 8)  */
status make(string str) {
  if(!str) {
    notify_fail("Make what out of sand?\n");
    return 0;
  }
  str = lower_case(str);
  if(member_array(str, sand_creations) > -1) {
    write("There is already a "+capitalize(str)+" made from sand here.\n");
    return 1;
  }

  write("You make a "+capitalize(str)+" out of the sand.\n");
  if(!this_player()->query_invis()) {
    say(this_player()->query_name()+" makes a "+capitalize(str)+
    " out of sand.\n",this_player());
  }
  else {
    say("The sand moves all by itself to make a "+capitalize(str)+
    ".\n", this_player());
  }
  sand_creations += ({ str, });
  this_object()->add_item(str, "A "+str+" made from soft yellow sand");
  return 1;
}

  
