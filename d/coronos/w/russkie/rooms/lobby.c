#include <mudlib.h>
#include <ansi.h>
#include <linewrap.h>
inherit ROOM;

static string *players;

status query_players(string str);

void reset(status arg) {
  if(!present("elizabeth")) {
  move_object(clone_object("/d/coronos/w/russkie/npc/host"),this_object());
  }

  if(arg) return;

  set_short("the lobby of skyes inn");
  set_long("\
The light in this room is very softly cast by a single torch in\n\
one wall. A pale blue rug covers the old wood floor, and a large\n\
table takes up much of the small room. On the surface of the table\n\
is a large red book. A long corridor lies to the west side of the room\n\
where many doors can be seen on each side of the hall. A narrow wooden\n\
staircase is also here, leading to the tavern below.\n");
  set_items(({
"book#registry",
"This large red book is the inn registry. You may be able to read it.\n",
"table",
"A book lies on this large table.\n",
"corridor#hall#doors",
"There is a long corridor of doors lieing to the west of the room.\n",
"wall#walls#torch#light",
"A soft light is cast by a small torch in one wall.\n",
"floor#rug",
"The wood floor is covered with a soft blue rug.\n",
     "stairs#staircase#stair",
"A small wooden staircase leads down, back to the tavern.\n",
"surface",
"The surface of the table is shiny. On it lays a red book.\n",
"tavern",
"The noisy tavern lies below.\n",
}));

  set_exits(({
   "/d/coronos/w/russkie/rooms/tavern", "down",
   "/d/coronos/w/russkie/rooms/hall1", "west",
  }));
  players = ({});
  set_weather(2, 1, 0);
}

void init() {
  add_action("read", "read");
  ::init();
}

status read(string str) {
  string tmp;

  if(str == "book" || str == "registry") {
   write("If you want to rent a room here, just ask Elizabeth about one.\n"+
     "Commands: say <room> \n"+
  "Items found to be missing from rooms are NOT the concern of the management!\n");

    if(!players || !sizeof(players)) {
      write("No one has checked into the inn today.\n");
      return 1;
    }
    else {
      tmp = implode(players, ",");
   write("The following people are staying at "+BOLD+BLUE_F+"Skyes"+OFF+" inn...\n");
      writelw("\t"+tmp+"\n");
      say(this_player()->query_name() +" reads the inn's register.\n");
    }
    return 1;
  }
  return 0;
}


void add_players(string str) {
  if(!str || query_players(str)) return;
  players += ({ str, });
}

status query_players(string str) {
  if(!players || !sizeof(players)) return 0;
  if(member_array(str, players) != -1) return 1;
}
