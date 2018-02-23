#include <mudlib.h>
inherit ROOM;

reset(arg) { 

  if(!present("board")) {
    object board;
    board = clone_object(BULLETIN_BOARD);
    board -> set_short("A lords notice board");
    board -> set_long(
          "This board is for use by those higher level players who have \n"+
          "achieved lord status within the realms of Tempus and beyond.\n");
    board -> set_save_file("room/board/lords");
    move_object(board, this_object());
  }

  if(!present("couch")) {
    object chair;
    chair = clone_object("inherit/chair");
    chair -> set_short("A plush leather couch sits against the north wall");
    chair -> set_long("This huge leather couch seems big enough for three.\n");
    chair -> set_name("couch");
    chair -> set_max_sitters(3);
    move_object(chair, this_object());

    chair = clone_object("inherit/chair");
    chair -> set_short("A plush leather couch sits against the south wall");
    chair -> set_long("This small leather couch seems big enough for two.\n");
    chair -> set_name("couch");
    chair -> set_max_sitters(2);
    move_object(chair, this_object());

    chair = clone_object("inherit/chair");
    chair -> set_short("A plush leather couch sits against the east wall");
    chair -> set_long("This huge leather couch seems big enough for three.\n");
    chair -> set_name("couch");
    chair -> set_max_sitters(3);
    move_object(chair, this_object());
  }

  if(arg) return;

  set_short("the lords chambers");
  set_long(
     "Shelves line the walls of this plush sitting room. Although \n"+
     "rather informal, this is where the lords of the realms meet \n"+
     "to discuss all matters of life here in Tempus, and beyond.  \n");

  set_day_desc(
     "The soft white curtains on the west wall are open, showing  \n"+
     "the grand floor to ceiling windows that look out into the   \n"+
     "city of Tempus\n");

  set_night_desc(
     "The soft white curtains are drawn, and the large windows    \n"+
     "closed to the night air. The fireplace in beside the couch  \n"+
     "against the south wall burns away.\n");

  set_items(({
     "shelf",  "A shelves line the walls filled with hundreds of books",
     "books",  "They appear to be on the culture of the city of Tempus",

     "walls",  "The walls of this huge sitting room are lined with\n"+
               "plush leather couches, and huge book cases"
  }));

  set_day_items(({
     "curtain#curtains", 
               "The soft white curtains are drawn back to allow \n"+
               "the natural light from outside to shine through",
     "window#windows",
               "The windows are open. Outside you can see the city",
     "fire#fireplace",
               "The fireplace cold and remains unlit"
  }));
  set_night_items(({
     "curtain#curtains", 
               "The soft white curtains are drawn so as to allow \n"+
               "the heat from the fireplace to keep the room warm",
     "window#windows",
               "The windows are closed. Outside you can see the city",
     "fireplace#fire",
               "The fire has been lit, keeping the room toasty warm"
  }));

  set_exits(({
	"room/city/t_hall3", "east"
  }));
  set_weather(2, 1, 0);
}

init() {
  ::init();
  call_out("check", 1);
  add_action("light", "light");
  add_action ("get", "get");
}

light(string str) {
  if(str == "fireplace" || str == "fire") {
    if(!query_day())
      write("The fireplace is already lit.\n");
    else
      write("The fireplace can only be lit at night.\n");
  }
  return 1;
}

check() {
  string *mess;
  mess = ({
     "The fireplace crackles\n",
     "The fire warms your bones\n",
     "The fire feels toasty warm\n",
     "The fire spits and crackles\n",
     "The fireplace warms the room\n",
     "The fire makes the room feel very comfy\n"
  });
  if(!query_day()) {
    tell_room(this_object(), mess[random(sizeof(mess))]);
    call_out("check", (120 + random(120)));
  }
}
get(string str) {
  if (!str || str == "couch") {
 write ("As you start to lift the couch you hear a click in your back.\n\
And from out of no where someone says: I'd advice you not to lift\n\
things that may put your back out.\n");
 return 1;
}
if (str == "all") {
write ("Try get <item> in this room please.\n");
return 1;
}
return 0;
}
